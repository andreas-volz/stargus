/*
 * TilesetHub.h
 *
 *      Author: Andreas Volz
 */

#ifndef TILESETHUB_H
#define TILESETHUB_H

// project
#include "Palette.h"
#include "kaitai/tileset_cv5.h"
#include "kaitai/tileset_vx4.h"
#include "kaitai/tileset_vf4.h"
#include "kaitai/tileset_vr4.h"
#include "Storage.h"
#include "Size.h"

// system
#include <memory>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace tileset
{
/**
 * The TilesetHub parses the complete data structures inside those files:
 * - tileset\\<tileset>.cv5|vx4|vf4|vr4
 *
 * The Kaitai parsed objects in this class are by intension public. There's no benefit in putting dozen silly
 * getter around them. The alternative to put them private means to implement every parser logic
 * inside this class or friend them all.
 *
 * So the design decision is just to let them public and the outside accessing function should only read them!
 * If I ever put this stuff to a general purpose library this design might change.
 *
 *  "with great power comes great responsibility" - (Spiderman)
 */
class TilesetHub : public Converter
{
public:
  TilesetHub(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile);
  virtual ~TilesetHub();


  bool convertTiledFormat(std::shared_ptr<AbstractPalette> palette, Storage storage);

  void generateVF4Json(Storage storage);

  void generateCV5Json(Storage storage);

  const std::string getTilesetName();

  std::vector<unsigned int> getAnimationTiles();

  unsigned int getMaxStaticTiles();

  std::shared_ptr<tileset_cv5_t> cv5;
  std::shared_ptr<tileset_vx4_t> vx4;
  std::shared_ptr<tileset_vf4_t> vf4;
  std::shared_ptr<tileset_vr4_t> vr4;

  static constexpr int MEGATILE_COLUMNS = 16;
  static const Size MEGATILE_SIZE;
  static constexpr int TILE_ANIMATION_FRAMES = 8;

private:
  void init();
  void saveJson(json &j, const std::string &file, bool pretty);

  void generateTilesetJson(Storage storage);
  void generateAnimationTilesetJson(unsigned int animation_count, Storage storage);

  std::vector<unsigned char> createRangeVector(unsigned char start_index, unsigned char end_index);
  std::vector<std::pair<unsigned char, unsigned char>> createShiftVector(const std::vector<unsigned char> &rangeVector, unsigned int amount);

  std::string m_arcfile;

  std::shared_ptr<std::istream> m_cv5_stream;
  std::shared_ptr<std::istream> m_vx4_stream;
  std::shared_ptr<std::istream> m_vf4_stream;
  std::shared_ptr<std::istream> m_vr4_stream;

  std::shared_ptr<kaitai::kstream> m_cv5_ks;
  std::shared_ptr<kaitai::kstream> m_vx4_ks;
  std::shared_ptr<kaitai::kstream> m_vf4_ks;
  std::shared_ptr<kaitai::kstream> m_vr4_ks;

  std::vector<unsigned int> animation_tiles;
  unsigned int max_static_tiles = 0;

};

} /* namespace tileset */

#endif /* TILESETHUB_H */
