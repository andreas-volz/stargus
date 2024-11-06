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


bool TilesetHub::convert(std::shared_ptr<AbstractPalette> palette, Storage storage)
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

  TiledPaletteImage ultraTile(ultra_tile_size, MEGATILE_SIZE);

  for(unsigned int i = 0; i < num_tiles; i++)
  {
    MegaTile mega(*this, i);

    ultraTile.copyTile(*mega.getImage(), i);
  }

  // FIXME: I don't like the path handling in this case. Needs to be changed!
  string save_png(storage.getFullPath() + "/" + storage.getFilename() + ".png");
  CheckPath(save_png);
  return PngExporter::save(save_png, ultraTile, palette, 0);
}

void TilesetHub::generateTilesetJson(Storage jsonfile)
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

  unsigned int num_cv5 = cv5->elements()->size();

  json j_tileset;

  j_tileset["columns"] = MEGATILE_COLUMNS;
  j_tileset["image"] = m_arcfile + ".png";
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

  vector<string> tile_slots_vector;

  for(unsigned int i = 0; i < num_cv5; i++)
  {
    tileset_cv5_t::group_t* group = cv5->elements()->at(i);

    /*if(group->terrain_type() == tileset_cv5_t::terrain_enum_t::TERRAIN_ENUM_BASIC)
    {
      num_normal++;
      cout << "normal(" << i << "): ";
    }*/


    std::vector<uint16_t>* vx4_vf4_ref = group->megatile_references();

    vector<string> tile_solids_vector;

    for(auto elem : *vx4_vf4_ref)
    {
      //cout << to_string(elem) << ",";

      /*tileset_vf4_t::minitile_t* minitile = vf4->elements()->at(elem);

      std::string subtilePassableFlags = "";
      for(auto flags : *minitile->flags())
      {
        if (flags->walkable()) {
          subtilePassableFlags += "p";
        } else {
          subtilePassableFlags += "u";
        }
      }

      tile_solids_vector.push_back(to_string(elem));
      tile_solids_vector.push_back(lg::table(lg::quote(subtilePassableFlags)));*/

      //cout << ", ";
    }
    //cout << endl;


   // tile_slots_vector.push_back(solid_str);
  }


  string full_path = jsonfile.getFullPath();
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

} /* namespace tileset */
