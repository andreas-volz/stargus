/*
 * Chk.h
 *
 *      Author: Andreas Volz
 */

#ifndef CHK_H_
#define CHK_H_

// project
#include "Storage.h"
#include "Converter.h"
#include <kaitai/chk_parser.h>
#include "tileset/TilesetHub.h"

// system
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>

// Forward declarations
class Hurricane;

/**
 * representation of a specific map (.chk) and converter
 */
class Chk : public Converter
{
public:
  Chk(std::shared_ptr<Hurricane> hurricane, const std::string &map_name);
  virtual ~Chk();

  const std::string getTileSet();

  bool convertTiled(tileset::TilesetHub &tilesethub, Storage storage);

  void generateMapJson(tileset::TilesetHub &tilesethub, Storage storage);

  std::shared_ptr<chk_parser_t> chk_parser;

private:
  std::shared_ptr<std::istream> m_chk_parser_stream;
  std::shared_ptr<kaitai::kstream> m_chk_parser_ks;
  static const std::vector<std::string> TILESET_MAPPING;
  std::string m_map_name;

  void saveJson(json &j, const std::string &file, bool pretty);


};

#endif /* CHK_H_ */
