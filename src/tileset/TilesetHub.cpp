/*
 * TilesetHub.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include "TilesetHub.h"
#include "PaletteImage.h"
#include "PngExporter.h"
#include "MegaTile.h"
#include "FileUtil.h"
#include "luagen.h"
#include "Preferences.h"
#include "Hurricane.h"
#include "FileUtil.h"

// system
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

namespace tileset
{

const Size TilesetHub::MEGATILE_SIZE = Size(32, 32);

TilesetHub::TilesetHub(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile) :
  Converter(hurricane),
  m_arcfile(arcfile)
{
  init();
}

TilesetHub::~TilesetHub()
{

}

void TilesetHub::init()
{
  m_cv5_stream = mHurricane->extractStream(m_arcfile + ".cv5");
  m_cv5_ks = make_shared<kaitai::kstream>(&*m_cv5_stream);
  cv5 = make_shared<tileset_cv5_t>(m_cv5_ks.get());

  m_vx4_stream = mHurricane->extractStream(m_arcfile + ".vx4");
  m_vx4_ks = make_shared<kaitai::kstream>(&*m_vx4_stream);
  vx4 = make_shared<tileset_vx4_t>(m_vx4_ks.get());

  m_vf4_stream = mHurricane->extractStream(m_arcfile + ".vf4");
  m_vf4_ks = make_shared<kaitai::kstream>(&*m_vf4_stream);
  vf4 = make_shared<tileset_vf4_t>(m_vf4_ks.get());

  m_vr4_stream = mHurricane->extractStream(m_arcfile + ".vr4");
  m_vr4_ks = make_shared<kaitai::kstream>(&*m_vr4_stream);
  vr4 = make_shared<tileset_vr4_t>(m_vr4_ks.get());
}

std::vector<unsigned char> TilesetHub::createRangeVector(unsigned char start_index, unsigned char end_index)
{
  vector<unsigned char> rangeVector;

  for(unsigned char i = start_index; i <= end_index; i++)
  {
    rangeVector.push_back(i);
  }
  return rangeVector;
}

std::vector<std::pair<unsigned char, unsigned char>> TilesetHub::createShiftVector(const std::vector<unsigned char> &rangeVector, unsigned int amount)
{
  std::vector<std::pair<unsigned char, unsigned char>> replacer;
  std::vector<unsigned char> tmp_copy(rangeVector);

  amount = amount % rangeVector.size();
  rotate(tmp_copy.rbegin(), tmp_copy.rbegin() + amount, tmp_copy.rend());

  for(unsigned int i = 0; i < rangeVector.size(); i++)
  {
    replacer.push_back(pair(rangeVector[i], tmp_copy[i]));
  }

  return replacer;
}


bool TilesetHub::convertTiledFormat(std::shared_ptr<AbstractPalette> palette, Storage storage)
{
  if(!vx4) // if it isn't available just return false
  {
    return false;
  }

  if(!palette) // if something wrong with palette just return false
  {
    return false;
  }

  unsigned int num_tiles = vx4->elements()->size();
  int tiles_width = MEGATILE_COLUMNS;
  int tiles_height = static_cast<int>(ceil(static_cast<float>(num_tiles) / static_cast<float>(tiles_width)));
  Size ultra_tile_size = Size(tiles_width, tiles_height);

  /*
   * identify how many tiles have palette animation to calculate maximum image size
   */
  for(unsigned int i = 0; i < num_tiles; i++)
  {
    MegaTile mega(*this, i);

    std::shared_ptr<PaletteImage> palette_image = mega.getImage();
    bool index_found = palette_image->hasPaletteIndexRange(1, 6) || palette_image->hasPaletteIndexRange(7, 13);
    if(index_found)
    {
      animation_tiles.push_back(i);
    }
  }

  Size ultra_animation_tile_size = Size(TILE_ANIMATION_FRAMES, animation_tiles.size());

  TiledPaletteImage ultraTile(ultra_tile_size, MEGATILE_SIZE);
  TiledPaletteImage ultraTileAnimation(ultra_animation_tile_size, MEGATILE_SIZE);

  unsigned int anim_group = 0;
  for(unsigned int i = 0; i < num_tiles; i++)
  {
    MegaTile mega(*this, i);

    std::shared_ptr<PaletteImage> palette_image = mega.getImage();
    auto found_it = find(animation_tiles.begin(), animation_tiles.end(), i);
    if(found_it != animation_tiles.end())
    {
      for(unsigned int frame = 0; frame < TILE_ANIMATION_FRAMES; frame++)
      {
        auto replacer = createShiftVector(createRangeVector(1, 6), frame);
        auto replacer2 = createShiftVector(createRangeVector(7, 13), frame);
        replacer.insert(replacer.end(), replacer2.begin(), replacer2.end());

        PaletteImage replaced_image(*palette_image, replacer);
        ultraTileAnimation.copyTile(replaced_image, Pos(frame, anim_group));
      }

      anim_group++;
    }
    else
    {
      // TODO: save animated tiles in static tileset and remember index, then no need to export the static tile (maybe)
    }

    max_static_tiles++;
    ultraTile.copyTile(*palette_image, i);
  }

  storage.setFilename(m_arcfile);
  string save_png(storage.getFullPath() + ".png");
  string save_png_anim(storage.getFullPath() + "_animation.png");
  CheckPath(save_png);
  CheckPath(save_png_anim);
  PngExporter::save(save_png, ultraTile, palette, false, false);
  PngExporter::save(save_png_anim, ultraTileAnimation, palette, false, false);

  generateTilesetJson(storage);
  generateAnimationTilesetJson(anim_group, storage);

  return true; // hack
}

void TilesetHub::generateCV5Json(Storage storage)
{
  json j_cv5;

  for(auto element : *cv5->elements())
  {
    json j_megatiles;

    for(auto megatile_ref : *element->megatile_references())
    {
      j_megatiles.push_back(megatile_ref);
    }
    //bool unwalkable = group->terrain_flags()->unwalkable();
    j_cv5.push_back(j_megatiles);
  }

  storage.setFilename(m_arcfile + "_cv5.json");
  string full_path = storage.getFullPath();
  CheckPath(full_path);
  saveJson(j_cv5, full_path, true);
}

void TilesetHub::generateVF4Json(Storage storage)
{
  json j_vf4;


  for(auto element : *vf4->elements())
  {
    json j_minitiles;

    for(auto flags : *element->flags())
    {
      bool walkable;
      if (flags->walkable())
      {
        walkable = true;
      }
      else
      {
        walkable = false;
      }
      j_minitiles.push_back(walkable);
    }

    j_vf4.push_back(j_minitiles);
  }

  storage.setFilename(m_arcfile + "_vf4.json");
  string full_path = storage.getFullPath();
  CheckPath(full_path);
  saveJson(j_vf4, full_path, true);
}

void TilesetHub::generateTilesetJson(Storage storage)
{
  if(!cv5) // if it isn't available just return with no action
  {
    return;
  }

  unsigned int num_tiles = vx4->elements()->size();
  int tiles_width = MEGATILE_COLUMNS;
  int tiles_height = static_cast<int>(ceil(static_cast<float>(num_tiles) / static_cast<float>(tiles_width)));
  const Size ultra_tile_size = Size(tiles_width, tiles_height);
  const Size image_size = ultra_tile_size * MEGATILE_SIZE;

  json j_tileset;

  j_tileset["columns"] = MEGATILE_COLUMNS;
  j_tileset["image"] = "../" + m_arcfile + ".png";
  j_tileset["imageheight"] = image_size.getHeight();
  j_tileset["imagewidth"] = image_size.getWidth();
  j_tileset["margin"] = 0;
  j_tileset["name"] = m_arcfile;
  j_tileset["spacing"] = 0;
  j_tileset["tilecount"] = ultra_tile_size.getHeight() * ultra_tile_size.getWidth();
  j_tileset["tileheight"] = MEGATILE_SIZE.getHeight();
  j_tileset["tilewidth"] = MEGATILE_SIZE.getWidth();
  j_tileset["type"] = "tileset";
  j_tileset["version"] = "1.8";

  storage.setFilename(m_arcfile + ".tsj");
  string full_path = storage.getFullPath();
  CheckPath(full_path);
  saveJson(j_tileset, full_path, true);

}

void TilesetHub::generateAnimationTilesetJson(unsigned int animation_count, Storage storage)
{
  if(!cv5) // if it isn't available just return with no action
  {
    return;
  }

  int tiles_width = TILE_ANIMATION_FRAMES;
  int tiles_height = animation_count;
  const Size ultra_tile_size = Size(tiles_width, tiles_height);
  const Size image_size = ultra_tile_size * MEGATILE_SIZE;
  unsigned int duration = 200;

  json j_tileset;

  j_tileset["columns"] = TILE_ANIMATION_FRAMES;
  j_tileset["image"] = "../" + m_arcfile + "_animation.png";
  j_tileset["imageheight"] = image_size.getHeight();
  j_tileset["imagewidth"] = image_size.getWidth();
  j_tileset["margin"] = 0;
  j_tileset["name"] = m_arcfile + " Animations";
  j_tileset["spacing"] = 0;
  j_tileset["tilecount"] = ultra_tile_size.getHeight() * ultra_tile_size.getWidth();
  j_tileset["tileheight"] = MEGATILE_SIZE.getHeight();
  j_tileset["tilewidth"] = MEGATILE_SIZE.getWidth();
  j_tileset["type"] = "tileset";
  j_tileset["version"] = "1.8";

  unsigned int tileid = 0;
  for(unsigned int ac = 0; ac < animation_count; ac++)
  {
    json j_animation;
    json j_tile;
    j_tile["id"] = tileid;
    for(unsigned int af = 0; af < TILE_ANIMATION_FRAMES; af++)
    {
      json j_animation_frame;
      j_animation_frame["duration"] = duration;
      j_animation_frame["tileid"] = tileid;
      j_animation.push_back(j_animation_frame);
      tileid++;
    }
    j_tile["animation"] = j_animation;


    j_tileset["tiles"].push_back(j_tile);
  }


  storage.setFilename(m_arcfile + "_animation.tsj");
  string full_path = storage.getFullPath();
  CheckPath(full_path);
  saveJson(j_tileset, full_path, true);

}

void TilesetHub::saveJson(json &j, const std::string &file, bool pretty)
{
  std::ofstream filestream(file);

  if(pretty)
  {
    filestream << std::setw(4) << j;
  }
  else
  {
    filestream << j;
  }
}

const std::string TilesetHub::getTilesetName()
{
  return m_arcfile;
}

std::vector<unsigned int> TilesetHub::getAnimationTiles()
{
  return animation_tiles;
}

unsigned int TilesetHub::getMaxStaticTiles()
{
  /* calculate all tiles of complete image. this adds also empty tiles in the last line */
  float max_tiles_f = static_cast<float>(max_static_tiles) / MEGATILE_COLUMNS + 1;
  int max_tiles_i = static_cast<int>(max_tiles_f) * MEGATILE_COLUMNS;

  return max_tiles_i;
}

} /* namespace tileset */
