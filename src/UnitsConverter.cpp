/*
 * UnitsExporter.cpp
 *
 *      Author: Andreas
 */

// project
#include "UnitsConverter.h"
#include "Preferences.h"
#include "FileUtil.h"
#include "Logger.h"
#include "StringUtil.h"
#include "Grp.h"
#include "luagen.h"
#include "dat/DataHub.h"

// system
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <nlohmann/json.hpp>

using namespace std;

namespace dat
{

static Logger logger = Logger("startool.dat.UnitsConverter");

UnitsConverter::UnitsConverter(std::shared_ptr<Hurricane> hurricane, DataHub &datahub) :
  Converter(hurricane),
  mDatahub(datahub)
{

}

UnitsConverter::~UnitsConverter()
{

}

bool UnitsConverter::convert(json &unitsJson)
{
  bool result = true;

  Preferences &preferences = Preferences::getInstance();

  const int tilesize_pixel = 8; // size of a MiniTile in pixels
  const int minitile_multi = 4; // number of MiniTiles in one MegaTile

  Storage graphics;
  graphics.setDataPath(preferences.getDestDir());
  graphics.setDataType("graphics");

  Storage luagen;
  luagen.setDataPath(preferences.getDestDir());
  luagen.setDataType("luagen/units");
  CheckPath(luagen.getFullPath());

  ofstream lua_include;
  lua_include.open (luagen("luagen-units.lua").getFullPath());
  string lua_include_str;

  /*ofstream lua_sounds;
  lua_sounds.open (luagen("luagen-sounds.lua").getFullPath());
  string lua_lua_sounds_str;*/

  // units.dat
  for(auto &array : unitsJson)
  {
    string unit_name = array.at("name");
    int unit_id = array.at("id");
    bool extractor = true;
    bool save_result = true;

    LOG4CXX_TRACE(logger, string("Unit(") + to_string(unit_id) + ")");

    try
    {
      extractor = array.at("extractor");
    }
    catch (const nlohmann::detail::out_of_range &json_range)
    {
      extractor = true; // default behaviour TODO: maybe better write into JSON file and skip default
    }

    if(extractor)
    {
      Unit unit(mDatahub, unit_id, unit_name);

      string grp_arcfile =  "unit\\" + unit.graphics_obj().sprite_obj().image_obj().grp_tbl().name1();

      // for the LUA reference it's enough to use the idle name as we save only one LUA for idle+talking portrait
      string unit_portraits;
      try
      {
        string portrait_name = unit.portrait_obj().video_idle_tbl().name1();
        string portrait_id = unit.portrait_obj().getIDString(portrait_name);
        string portrait_lua = "portrait_" + portrait_id;
        unit_portraits = lg::assign("Portrait", portrait_lua);
      }
      catch (PropertyNotAvailableException &nex)
      {
        cout << nex.what() << endl;

        // FIXME: just use the tadvisor as some fallback for now
        unit_portraits = lg::assign("Portrait", "portrait_tadvisor");
      }

      Storage lua_file_store(luagen(unit_name + ".lua"));
      ofstream lua_file;
      lua_file.open (lua_file_store.getFullPath());

      // generate sounds Lua -->

      string makeLuaReadySounds = makeReadySounds(unit);
      string makeLuaWhatSounds = makeWhatSounds(unit);
      string makeLuaYesSounds = makeYesSounds(unit);
      string makeLuaPissSounds = makePissSounds(unit);

      vector<string> unit_LuaSounds;

      // add Ready sounds direct to the unit
      if(!makeLuaReadySounds.empty())
      {
        string unit_LuaSound_ready = lg::paramsQuote({"ready", unit_name + "-sound-ready"});
        unit_LuaSounds.push_back(unit_LuaSound_ready);
      }

      // add Yes/Acknowledge sounds direct to the unit
      if(!makeLuaYesSounds.empty())
      {
        string unit_LuaSound_acknowledge = lg::paramsQuote({"acknowledge", unit_name + "-sound-yes"});
        unit_LuaSounds.push_back(unit_LuaSound_acknowledge);
      }

      // make a sound group from What...
      vector<string> unit_LuaSelectedSounds;
      if(!makeLuaWhatSounds.empty())
      {
        unit_LuaSelectedSounds.push_back(unit_name + "-sound-what");
      }

      // ...and Piss group
      if(!makeLuaPissSounds.empty())
      {
        unit_LuaSelectedSounds.push_back(unit_name + "-sound-piss");
      }

      // create a what/piss sound group if both are existing...
      string makeLuaSelectedSound;
      // ... and add this sound group to unit Sounds
      if(unit_LuaSelectedSounds.size() > 1)
      {
        string unit_LuaSound_selected = lg::paramsQuote({"selected", unit_name + "-sound-selected"});
        unit_LuaSounds.push_back(unit_LuaSound_selected);

        makeLuaSelectedSound = lg::function("MakeSoundGroup", {lg::quote(unit_name + "-sound-selected"),
                                                               lg::paramsQuote(unit_LuaSelectedSounds)});
      }
      else if (unit_LuaSelectedSounds.size() == 1) // ...otherwise assign it direct to selected
      {
        string unit_LuaSound_selected = lg::paramsQuote({"selected", unit_LuaSelectedSounds.at(0)});
        unit_LuaSounds.push_back(unit_LuaSound_selected);
      }

      string unit_sounds = lg::assign("Sounds", lg::table({lg::params(unit_LuaSounds)}));

      // generate images and other properties Lua -->

      string image_id = unit.graphics_obj().sprite_obj().image_obj().getIDString();
      string image_lua = image_id;
      string unit_image = lg::assign("Image", image_lua);

      string unit_hitpoints = lg::assign("HitPoints", to_string(unit.hitpoints()));
      string unit_name_translated = lg::assign("Name", lg::quote(unit.name_tbl().name1()));

      bool unit_building = unit.special_ability_flags()->building();
      string unit_LuaBuilding =  lg::assign("Building", lg::boolean(unit_building));

      units_dat_t::unit_dimension_type_t *unit_dimension_tilesize = unit.unit_dimension();

      int unit_width = unit_dimension_tilesize->left() + unit_dimension_tilesize->right();
      int unit_height = unit_dimension_tilesize->up() + unit_dimension_tilesize->down();

      double unit_tilesize_width = unit_width / (double) tilesize_pixel;
      double unit_tilesize_height = unit_height / (double) tilesize_pixel;

      int unit_boxsize_width = round(unit_tilesize_width * tilesize_pixel);
      int unit_boxsize_height = round(unit_tilesize_height * tilesize_pixel);

      // for all units which could move (all non-buildings) set a square size as optimization for stratagus
      if(!unit_building)
      {
        unit_tilesize_width = unit_tilesize_height = round(sqrt(unit_tilesize_width * unit_tilesize_height));
      }

      // ensure minimal unit width
      if(unit_tilesize_width < 1)
      {
        unit_tilesize_width = 1;
      }

      // ensure minimal unit height
      if(unit_tilesize_height < 1)
      {
        unit_tilesize_height = 1;
      }

      string unit_LuaTileSize = lg::assign("TileSize", lg::table({lg::integer(unit_tilesize_width), lg::integer(unit_tilesize_height)}));
      string unit_LuaBoxSize = lg::assign("BoxSize", lg::table({to_string(unit_boxsize_width), to_string(unit_boxsize_height)}));

      // for now just give each unit a PersonalSpace of 1 around
      string unit_LuaPersonalSpace = lg::assign("PersonalSpace", lg::table({lg::integer(1), lg::integer(1)}));

      int unit_sight_range = unit.sight_range() * minitile_multi;
      string unit_computer_reaction_rangeStr ("math.ceil(" + to_string(unit_sight_range) + " * ComputerReactionRangeFactor)");
      string unit_person_reaction_rangeStr ("math.floor(" + to_string(unit_sight_range) + " * PersonReactionRangeFactor)");

      string unit_LuaSightRange = lg::assign("SightRange", to_string(unit_sight_range));
      string unit_LuaComputerReactionRange = lg::assign("ComputerReactionRange", unit_computer_reaction_rangeStr);
      string unit_LuaPersonReactionRange = lg::assign("PersonReactionRange", unit_person_reaction_rangeStr);

      // generate some standard shadow
      Pos shadow_position = Pos(-7, -7);

      // some basic flyer shadow support => to be improved
      if(unit.elevation_level() >= 16)
      {
        shadow_position = Pos(15, 15);
      }

      string unit_shadow = lg::assign("Shadow", lg::table({lg::quote("offset"), lg::posTable(shadow_position), lg::quote("scale"), "1"}));

      // generate a dummy animation as fallback to not crash
      string unit_animations = lg::assign("Animations", lg::quote("animations-dummy-still"));

      // generate a dummy icon as fallback to not crash
      string unit_icon = lg::assign("Icon", lg::quote("icon-terran-command-center"));

      string unit_LuaNumDirections = lg::assign("NumDirections", image_lua + "_NumDirections");

      string unit_LuaType(lg::assign("Type", lg::quote("land"))); // land is fallback
      string unit_LuaLandUnit(lg::assign("LandUnit", lg::boolean(true))); // LandUnit=true is fallback

      bool unit_flyer = unit.special_ability_flags()->flyer();
      string unit_LuaFlyer =  lg::assign("AirUnit", lg::boolean(unit_flyer));
      if(unit_flyer)
      {
        unit_LuaType = lg::assign("Type", lg::quote("fly"));
        unit_LuaLandUnit = lg::assign("LandUnit", lg::boolean(false));
      }

      bool unit_organic = unit.special_ability_flags()->organic();
      string unit_LuaOrganic =  lg::assign("organic", lg::boolean(unit_organic));

      int unit_build_time = ((double)unit.build_time() / 24.0) * 6.0; // SC time is 1/24 sec and *6 is stratagus magic
      int unit_minaral_costs = unit.mineral_cost();
      int unit_vespene_costs = unit.vespene_cost();

      string unit_LuaCosts =  lg::assign("Costs", lg::table({lg::quote("time"), to_string(unit_build_time),
                                                             lg::quote("minerals"), to_string(unit_minaral_costs),
                                                             lg::quote("gas"), to_string(unit_vespene_costs)
                                                            }));

      // FIXME: just make everything able to move as test
      //string unit_LuaSpeed = lg::assign("Speed", "10");

      string unit_defintion = lg::DefineUnitType(unit_name,
                                                {lg::line(unit_name_translated),
                                                 lg::line(unit_image),
                                                 lg::line(unit_shadow),
                                                 lg::line(unit_icon),
                                                 lg::line(unit_animations),
                                                 lg::line(unit_portraits),
                                                 lg::line(unit_hitpoints),
                                                 lg::line(unit_LuaTileSize),
                                                 lg::line( unit_LuaBoxSize),
                                                 lg::line(unit_LuaSightRange),
                                                 lg::line(unit_LuaComputerReactionRange),
                                                 lg::line(unit_LuaPersonReactionRange),
                                                 lg::line(unit_LuaNumDirections),
                                                 lg::line(unit_LuaFlyer),
                                                 lg::line(unit_LuaType),
                                                 lg::line(unit_LuaBuilding),
                                                 lg::line(unit_LuaOrganic),
                                                 lg::line(unit_LuaLandUnit),
                                                 lg::line(unit_LuaCosts),
                                                 lg::line(unit_LuaPersonalSpace),
                                                 lg::line(unit_sounds)
                                                });

      lua_include_str += lg::line(lg::function("Load", lg::quote(lua_file_store.getRelativePath())));

      lua_file << unit_defintion << endl;


      // write all the Lua sound functions
      if(!makeLuaReadySounds.empty())
      {
        lua_file <<  makeLuaReadySounds << endl;
      }

      if(!makeLuaWhatSounds.empty())
      {
        lua_file <<  makeLuaWhatSounds << endl;
      }

      if(!makeLuaYesSounds.empty())
      {
        lua_file <<  makeLuaYesSounds << endl;
      }

      if(!makeLuaPissSounds.empty())
      {
        lua_file <<  makeLuaPissSounds << endl;
      }

      if(!makeLuaSelectedSound.empty())
      {
        lua_file <<  makeLuaSelectedSound << endl;
      }

      lua_file.close();
    }

    printf("...%s\n", save_result ? "ok" : "nok");
  }

  lua_include << lua_include_str;
  lua_include.close();

  //lua_sounds.close();

  return result;
}

std::string UnitsConverter::makeReadySounds(Unit &unit)
{
  string make_sound;

  try
  {
    TblEntry unit_ready_sound_tbl_entry = unit.ready_sound_obj().sound_file_tbl();

    string unit_sound_ready_id = unit.getIDString() + "-sound-ready";

    string unit_ready_sound = unit_ready_sound_tbl_entry.name1();

    cout << "Ready Sound: " << unit_ready_sound  << endl;

    string sound_file_base(unit_ready_sound);
    replaceString("\\", "/", sound_file_base);
    sound_file_base = cutFileEnding(to_lower(sound_file_base), ".wav");
    string sound_file_ogg = "sounds/unit/" + sound_file_base + ".ogg";

    make_sound = lg::function("MakeSound", {lg::quote(unit_sound_ready_id), lg::table({lg::quote(sound_file_ogg)})});
  }
  catch(PropertyNotAvailableException &nex)
  {
    cout << "no Ready sound: " << nex.what() << endl;
  }

  return make_sound;
}

std::string UnitsConverter::makeWhatSounds(Unit &unit)
{
  string make_sound;

  try
  {
    vector<Sfx> sfx_vec = unit.what_sound_obj();
    vector<string> what_sound_vec;

    if(!sfx_vec.empty())
    {
      string unit_sound_ready_id = unit.getIDString() + "-sound-what";

      for (auto sfx : sfx_vec)
      {
        TblEntry unit_what_sound_tbl_entry = sfx.sound_file_tbl();

        string unit_what_sound = unit_what_sound_tbl_entry.name1();

        cout << "What Sound: " << unit_what_sound  << endl;

        string sound_file_base(unit_what_sound);
        replaceString("\\", "/", sound_file_base);
        sound_file_base = cutFileEnding(to_lower(sound_file_base), ".wav");
        string sound_file_ogg = "sounds/unit/" + sound_file_base + ".ogg";

        what_sound_vec.push_back(sound_file_ogg);
      }

      string unit_LuaWhatSoundParams = lg::paramsQuote(what_sound_vec);

      make_sound = lg::function("MakeSound", {lg::quote(unit_sound_ready_id), lg::table(unit_LuaWhatSoundParams)});
    }
  }
  catch(PropertyNotAvailableException &nex)
  {
    cout << "no What sound: " << nex.what() << endl;
  }

  return make_sound;
}

std::string UnitsConverter::makeYesSounds(Unit &unit)
{
  string make_sound;

  try
  {
    vector<Sfx> sfx_vec = unit.yes_sound_obj();
    vector<string> yes_sound_vec;

    if(!sfx_vec.empty())
    {
      string unit_yes_ready_id = unit.getIDString() + "-sound-yes";

      for (auto sfx : sfx_vec)
      {
        TblEntry unit_yes_sound_tbl_entry = sfx.sound_file_tbl();

        string unit_yes_sound = unit_yes_sound_tbl_entry.name1();

        cout << "Yes Sound: " << unit_yes_sound  << endl;

        string sound_file_base(unit_yes_sound);
        replaceString("\\", "/", sound_file_base);
        sound_file_base = cutFileEnding(to_lower(sound_file_base), ".wav");
        string sound_file_ogg = "sounds/unit/" + sound_file_base + ".ogg";

        yes_sound_vec.push_back(sound_file_ogg);
      }

      string unit_LuaYesSoundParams = lg::paramsQuote(yes_sound_vec);

      make_sound = lg::function("MakeSound", {lg::quote(unit_yes_ready_id), lg::table(unit_LuaYesSoundParams)});
    }
  }
  catch(PropertyNotAvailableException &nex)
  {
    cout << "no Yes sound: " << nex.what() << endl;
  }

  return make_sound;
}

std::string UnitsConverter::makePissSounds(Unit &unit)
{
  string make_sound;

  try
  {
    vector<Sfx> sfx_vec = unit.piss_sound_obj();
    vector<string> piss_sound_vec;

    if(!sfx_vec.empty())
    {
      string unit_sound_piss_id = unit.getIDString() + "-sound-piss";

      for (auto sfx : sfx_vec)
      {
        TblEntry unit_piss_sound_tbl_entry = sfx.sound_file_tbl();

        string unit_piss_sound = unit_piss_sound_tbl_entry.name1();

        cout << "Piss Sound: " << unit_piss_sound  << endl;

        string sound_file_base(unit_piss_sound);
        replaceString("\\", "/", sound_file_base);
        sound_file_base = cutFileEnding(to_lower(sound_file_base), ".wav");
        string sound_file_ogg = "sounds/unit/" + sound_file_base + ".ogg";

        piss_sound_vec.push_back(sound_file_ogg);
      }

      string unit_LuaPissSoundParams = lg::paramsQuote(piss_sound_vec);

      make_sound = lg::function("MakeSound", {lg::quote(unit_sound_piss_id), lg::table(unit_LuaPissSoundParams)});
    }
  }
  catch(PropertyNotAvailableException &nex)
  {
    cout << "no Piss sound: " << nex.what() << endl;
  }

  return make_sound;
}

std::string UnitsConverter::makeHelpSounds(Unit &unit)
{
  return "";
}

} /* namespace dat */
