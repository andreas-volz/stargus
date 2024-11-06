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
  Chk(std::shared_ptr<Hurricane> hurricane);
  virtual ~Chk();

  void setUnitNames(const std::vector<std::string> &unitNames);

  virtual bool convert(const std::string &arcfile,tileset::TilesetHub &tilesethub, Storage jsonfile);

  std::shared_ptr<chk_parser_t> chk_parser;

private:
  std::vector<std::string> mUnitNames;

  std::shared_ptr<std::istream> m_chk_parser_stream;
  std::shared_ptr<kaitai::kstream> m_chk_parser_ks;

  void saveJson(json &j, const std::string &file, bool pretty);


};

#endif /* CHK_H_ */
