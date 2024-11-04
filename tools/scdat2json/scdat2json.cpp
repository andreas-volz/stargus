/*
 * scdat2json.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include "Breeze.h"
#include "Storm.h"
#include "Casc.h"
#include "FileUtil.h"
#include "StringUtil.h"
#include "optparser.h"
#include "dat/DataHub.h"
#include "Storage.h"
#include "SCJsonExporter.h"
#include "Logger.h"
#include "pacman.h"
#include "dat/Unit.h"
#include "to_json.h"

// system
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
using namespace dat;

/**
 * The scdat2json tool idea is to export the data in all relevant *.dat and corresponding *.tbl in a raw format to JSON.
 * At this point of transformation isn't much format conversation done. Just put the data as in original data structures, but readable.
 * Only exception for now is that .tbl files get some basic control sequence parsing.
 */

static Logger logger("startool.scdat2json");

// some global variables
string backend;
string archive;
string destination_directory;
bool pretty = true;
bool nested_objects = false;

bool CheckCASCDataFolder(const std::string &dir)
{
  return FileExists(dir + "/.build.info");
}

enum optionIndex
{
  UNKNOWN, HELP, BACKEND, PRETTY, OBJECTS
};
const option::Descriptor usage[] =
{
  {
    UNKNOWN, 0, "", "", option::Arg::None, "USAGE: scdat2json [options] archive destination-directory\n\n"
    "Options:"
  },
  { HELP, 0, "h", "help", option::Arg::None, "  --help, -h  \t\tPrint usage and exit" },
  { PRETTY, 0, "p", "pretty", Arg::Required, "  --pretty=[yes/no], -p  \t\tPretty print the formated JSON file (default: yes)" },
  { OBJECTS, 0, "o", "objects", Arg::Required, "  --objects=[yes/no], -o  \t\tGenerate nested objects in the data (default: no)" },
  { BACKEND, 0, "b", "backend", Arg::Required, "  --backend, -b  \t\tChoose a backend (Storm=St*arcr*ft1/Br**dwar;Casc=Remastered;Breeze=Folder)" },
  {
    UNKNOWN, 0, "", "", option::Arg::None,
    "\narchive \t\tDestination to the archive (mpq, casc or dummy folder) based on backend.\n"
    "\ndestination-directory \t\tWhere to save the extracted file with same relative path.\n"

  },
  { 0, 0, 0, 0, 0, 0 }
};

int parseOptions(int argc, const char **argv)
{
  argc -= (argc > 0);
  argv += (argc > 0); // skip program name argv[0] if present
  option::Stats stats(usage, argc, argv);
  std::unique_ptr<option::Option[]> options(new option::Option[stats.options_max]), buffer(new option::Option[stats.buffer_max]);
  option::Parser parse(usage, argc, argv, options.get(), buffer.get());

  if (parse.error())
    exit(0);

  if (options[HELP])
  {
    option::printUsage(std::cout, usage);
    exit(0);
  }

  if ( options[PRETTY].count() > 0 )
  {
    if (string(options[PRETTY].arg) == "yes")
    {
      pretty = true;
    }
    else if (string(options[PRETTY].arg) == "no")
    {
      pretty = false;
    }
  }

  if ( options[OBJECTS].count() > 0 )
  {
    if (string(options[OBJECTS].arg) == "yes")
    {
      nested_objects = true;
    }
    else if (string(options[OBJECTS].arg) == "no")
    {
      nested_objects = false;
    }
  }

  if(options[BACKEND].count() > 0)
  {
    backend = options[BACKEND].arg;
  }
  else
  {
    cerr << "Error: 'backend' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  // parse options

  for (option::Option *opt = options[UNKNOWN]; opt; opt = opt->next())
    std::cout << "Unknown option: " << opt->name << "\n";

  for (int i = 0; i < parse.nonOptionsCount(); ++i)
  {
    switch (i)
    {
    case 0:
      //cerr << "archive #" << i << ": " << parse.nonOption(i) << "\n";
      archive = parse.nonOption(i);
      break;
    case 1:
      //cerr << "destination-directory #" << i << ": " << parse.nonOption(i) << "\n";
      destination_directory = parse.nonOption(i);
      break;
    default:
      break;
    }
  }

  if (archive.empty())
  {
    cerr << "Error: 'archive' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  if (destination_directory.empty())
  {
    cerr << "Error: 'destination_directory' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  return 0;
}

void saveJson(json &j, const std::string &file, bool pretty)
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

int main(int argc, const char **argv)
{
#ifdef HAVE_LOG4CXX
  if (FileExists("logging.prop"))
  {
    log4cxx::PropertyConfigurator::configure("logging.prop");
  }
  else
  {
    logger.off();
  }
#endif // HAVE_LOG4CXX

  parseOptions(argc, argv);

  bool archive_exists = FileExists(archive);
  if(!archive_exists)
  {
    cerr << "archive not existing - exit!" << endl;
    exit(1);
  }

  // read in the json file
  std::ifstream json_file(pacman::searchFile("dataset/units.json"));
  json units_json; //create unitiialized json object
  json_file >> units_json; // initialize json object with what was read from file

  shared_ptr<Hurricane> hurricane;

  if(to_lower(backend) == "breeze")
  {
    hurricane = make_shared<Breeze>(archive);
  }
  else if(to_lower(backend) == "storm")
  {
    hurricane = make_shared<Storm>(archive);
  }
  else if(to_lower(backend) == "casc")
  {
#ifdef HAVE_CASC
    if(CheckCASCDataFolder(archive))
    {
      hurricane = make_shared<Casc>(archive);
    }
    else
    {
      cerr << "Error: 'archive' is not a CASC archive!" << endl;
    }
#else
    cerr << "Error: No CASC support compiled into sauwetter!" << endl;
    exit(1);
#endif
  }

  dat::DataHub datahub(hurricane);
  Storage jsonStorage;

  // export all units
  string unit_directory = destination_directory + "/units/";
  CheckPath(unit_directory);
  jsonStorage.setDataPath(unit_directory);

  // TODO: decide to generate from units_json list or every unit available...
  for(auto &array : units_json)
  {
    string id_string = array.at("name");
    int id = array.at("id");

    Unit unit_obj(datahub, id, id_string);
    unit_obj.set_generate_objects(nested_objects);

    json j_unit(unit_obj);

    saveJson(j_unit, jsonStorage(id_string + ".json"), pretty);
  }

  // export all graphics (flingy)
  string flingy_directory = destination_directory + "/flingy/";
  CheckPath(flingy_directory);
  jsonStorage.setDataPath(flingy_directory);

  for (unsigned int graphics = 0; graphics < datahub.flingy->sprite()->size(); graphics++)
  {
    Flingy flingy_obj(datahub, graphics);
    flingy_obj.set_generate_objects(nested_objects);

    json j_flingy(flingy_obj);
    string num_string = to_string(graphics);
    saveJson(j_flingy, jsonStorage("flingy_" + num_string + ".json"), pretty);
  }

  // export all sprites
  string sprite_directory = destination_directory + "/sprites/";
  CheckPath(sprite_directory);
  jsonStorage.setDataPath(sprite_directory);

  for (unsigned int sprite = 0; sprite < datahub.sprites->image()->size(); sprite++)
  {
    Sprite sprite_obj(datahub, sprite);
    sprite_obj.set_generate_objects(nested_objects);

    json j_sprite(sprite_obj);
    string num_string = to_string(sprite);
    saveJson(j_sprite, jsonStorage("sprite_" + num_string + ".json"), pretty);
  }

  // export all images
  string image_directory = destination_directory + "/images/";
  CheckPath(image_directory);
  jsonStorage.setDataPath(image_directory);

  // generate raw dat files

  CheckPath(destination_directory);
  jsonStorage.setDataPath(destination_directory);

  SCJsonExporter scjsonexporter(datahub);

  json j_unit_dat = scjsonexporter.export_unit_dat();
  saveJson(j_unit_dat, jsonStorage("units_dat.json"), pretty);

  json j_orders_dat = scjsonexporter.export_orders_dat();
  saveJson(j_orders_dat, jsonStorage("orders_dat.json"), pretty);

  json j_weapons_dat = scjsonexporter.export_weapons_dat();
  saveJson(j_weapons_dat, jsonStorage("weapons_dat.json"), pretty);

  json j_flingy_dat = scjsonexporter.export_flingy_dat();
  saveJson(j_flingy_dat, jsonStorage("flingy_dat.json"), pretty);

  json j_sprites_dat = scjsonexporter.export_sprites_dat();
  saveJson(j_sprites_dat, jsonStorage("sprites_dat.json"), pretty);

  json j_images_dat = scjsonexporter.export_images_dat();
  saveJson(j_images_dat, jsonStorage("images_dat.json"), pretty);

  json j_sfxdata_dat = scjsonexporter.export_sfxdata_dat();
  saveJson(j_sfxdata_dat, jsonStorage("sfxdata_dat.json"), pretty);

  json j_portdata_dat = scjsonexporter.export_portdata_dat();
  saveJson(j_portdata_dat, jsonStorage("portdata_dat.json"), pretty);

  json j_upgrades_dat = scjsonexporter.export_upgrades_dat();
  saveJson(j_upgrades_dat, jsonStorage("upgrades_dat.json"), pretty);

  json j_techdata_dat = scjsonexporter.export_techdata_dat();
  saveJson(j_techdata_dat, jsonStorage("techdata_dat.json"), pretty);

  json j_mapdata_dat = scjsonexporter.export_mapdata_dat();
  saveJson(j_mapdata_dat, jsonStorage("mapdata_dat.json"), pretty);

  // export all the .tbl ->

  json j_images_tbl = scjsonexporter.export_file_tbl(datahub.images_tbl_vec);
  saveJson(j_images_tbl, jsonStorage("images_tbl.json"), pretty);

  json j_sfxdata_tbl = scjsonexporter.export_file_tbl(datahub.sfxdata_tbl_vec);
  saveJson(j_sfxdata_tbl, jsonStorage("sfxdata_tbl.json"), pretty);

  json j_portdata_tbl = scjsonexporter.export_file_tbl(datahub.portdata_tbl_vec);
  saveJson(j_portdata_tbl, jsonStorage("portdata_tbl.json"), pretty);

  json j_mapdata_tbl = scjsonexporter.export_file_tbl(datahub.mapdata_tbl_vec);
  saveJson(j_mapdata_tbl, jsonStorage("mapdata_tbl.json"), pretty);

  /// save all the the stat_txt.tbl parts...
  json stat_txt_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_tbl_vec);
  saveJson(stat_txt_tbl, jsonStorage("stat_txt_tbl.json"), pretty);

  /*json stat_txt_units_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_units_tbl_vec);
  saveJson(stat_txt_units_tbl, jsonStorage("stat_txt_units_tbl.json"), pretty);

  json stat_txt_weapons_tbljson = scjsonexporter.export_file_tbl(datahub.stat_txt_weapons_tbl_vec);
  saveJson(stat_txt_weapons_tbljson, jsonStorage("stat_txt_weapons_tbl.json"), pretty);

  json stat_txt_error_messages_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_error_messages_tbl_vec);
  saveJson(stat_txt_error_messages_tbl, jsonStorage("stat_txt_error_messages_tbl.json"), pretty);

  json stat_txt_upgrades_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_upgrades_tbl_vec);
  saveJson(stat_txt_upgrades_tbl, jsonStorage("stat_txt_upgrades_tbl.json"), pretty);

  json stat_txt_orders_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_orders_tbl_vec);
  saveJson(stat_txt_orders_tbl, jsonStorage("stat_txt_orders_tbl.json"), pretty);

  json stat_txt_techdata_tbl = scjsonexporter.export_file_tbl(datahub.stat_txt_techdata_tbl_vec);
  saveJson(stat_txt_techdata_tbl, jsonStorage("stat_txt_techdata_tbl.json"), pretty);*/

  cerr << "Application finished!" << endl;

  return 0;
}
