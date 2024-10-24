#include "to_json.h"
#include "StringUtil.h"

#include <iostream>

using namespace std;
using namespace dat;



void to_json(json &j, units_dat_t::hit_points_type_t *t)
{
  j = json{ {"hitpoints", t->hitpoints()} };
}

void to_json(json &j, units_dat_t::special_ability_flags_type_t *t)
{
  j = json
  {
    {"building", t->building()},
    {"addon", t->addon()},
    {"flyer", t->flyer()},
    {"resourceminer", t->resourceminer()},
    {"subunit", t->subunit()},
    {"flyingbuilding", t->flyingbuilding()},
    {"hero", t->hero()},
    {"regenerate", t->regenerate()},
    {"animatedidle", t->animatedidle()},
    {"cloakable", t->cloakable()},
    {"twounitsinoneegg", t->twounitsinoneegg()},
    {"singleentity", t->singleentity()},
    {"resourcedepot", t->resourcedepot()},
    {"resourcecontainter", t->resourcecontainter()},
    {"robotic", t->robotic()},
    {"detector", t->detector()},
    {"organic", t->organic()},
    {"requirescreep", t->requirescreep()},
    {"unused", t->unused()},
    {"requirespsi", t->requirespsi()},
    {"burrowable", t->burrowable()},
    {"spellcaster", t->spellcaster()},
    {"permanentcloak", t->permanentcloak()},
    {"pickupitem", t->pickupitem()},
    {"ignoresupplycheck", t->ignoresupplycheck()},
    {"usemediumoverlays", t->usemediumoverlays()},
    {"uselargeoverlays", t->uselargeoverlays()},
    {"battlereactions", t->battlereactions()},
    {"fullautoattack", t->fullautoattack()},
    {"invincible", t->invincible()},
    {"mechanical", t->mechanical()},
    {"producesunits", t->producesunits()}
  };
}

void to_json(json &j, units_dat_t::staredit_placement_box_type_t *t)
{
  j = json{ {"width", t->width()}, {"height", t->height()} };
}

void to_json(json &j, units_dat_t::addon_position_type_t *t)
{
  j = json{ {"horizontal", t->horizontal()}, {"vertical", t->vertical()} };
}

void to_json(json &j, units_dat_t::unit_dimension_type_t *t)
{
  j = json{ {"left", t->left()}, {"up", t->up()}, {"right", t->right()}, {"down", t->down()} };
}

void to_json(json &j, units_dat_t::staredit_group_flags_type_t *t)
{
  j = json
  {
    {"zerg", t->zerg()},
    {"terran", t->terran()},
    {"protoss", t->protoss()},
    {"men", t->men()},
    {"building", t->building()},
    {"factory", t->factory()},
    {"independent", t->independent()},
    {"neutral", t->neutral()}
  };
}

void to_json(json &j, units_dat_t::staredit_availability_flags_type_t *t)
{
  j = json
  {
    {"non_neutral", t->non_neutral()},
    {"unit_listing", t->unit_listing()},
    {"mission_briefing", t->mission_briefing()},
    {"player_settings", t->player_settings()},
    {"all_races", t->all_races()},
    {"set_doodad_state", t->set_doodad_state()},
    {"non_location_triggers", t->non_location_triggers()},
    {"unit_hero_settings", t->unit_hero_settings()},
    {"location_triggers", t->location_triggers()},
    {"brood_war_only", t->brood_war_only()}
  };
}

namespace dat
{

void to_json(json &j, TblEntry t)
{
  j = json
  {
    {"name1", t.name1()},
    {"name2", t.name2()},
    {"name3", t.name3()},
    {"shortcut_pos", t.shortcut_pos()},
    {"shortcut", t.shortcut()}
  };
}

void to_json(json &j, Upgrade u)
{
  j["id"] = json(u.id());
  j["mineral_cost_base"] = json(u.mineral_cost_base());
  j["mineral_cost_factor"] = json(u.mineral_cost_factor());
  j["vespene_cost_base"] = json(u.vespene_cost_base());
  j["vespene_cost_factor"] = json(u.vespene_cost_factor());
  j["research_time_base"] = json(u.research_time_base());
  j["research_time_factor"] = json(u.research_time_factor());
  j["unknown6"] = json(u.unknown6());
  j["icon"] = json(u.icon());
  j["label"] = json(u.label());
  j["label_tbl"] = json(u.label_tbl());
  j["race"] = json(u.race());
  j["max_repeats"] = json(u.max_repeats());

  if (u.has_broodwar_flag())
  {
    j["broodwar_flags"] = json(u.broodwar_flags());
  }
}

void to_json(json &j, Order o)
{
  j["id"] = json(o.id());
  j["label"] = json(o.label());
  j["label_tbl"] = json(o.label_tbl());
  j["use_weapon_targeting"] = json(o.use_weapon_targeting());
  j["unknown2"] = json(o.unknown2());
  j["unknown3"] = json(o.unknown3());
  j["unknown4"] = json(o.unknown4());
  j["unknown5"] = json(o.unknown5());
  j["interruptible"] = json(o.interruptible());
  j["unknown7"] = json(o.unknown7());
  j["queueable"] = json(o.queueable());
  j["unknown9"] = json(o.unknown9());
  j["unknown10"] = json(o.unknown10());
  j["unknown11"] = json(o.unknown11());
  j["unknown12"] = json(o.unknown12());

  j["targeting"] = json(o.targeting());
  if(o.get_generate_objects())
  {
    try
    {
      j["targeting_obj"] = json(o.targeting_obj());
    }
    catch (PropertyNotAvailableException &ex)
    { /*it's fine, do nothing */ }
  }
  j["energy"] = json(o.energy());
  if(o.get_generate_objects())
    {
    try
    {
      j["energy_obj"] = json(o.energy_obj());
    }
    catch (PropertyNotAvailableException &ex)
    { /*it's fine, do nothing */ }
  }

  j["animation"] = json(o.animation());
  j["highlight"] = json(o.highlight());
  j["unknown17"] = json(o.unknown17());
  j["obscured_order"] = json(o.obscured_order());
  //j["obscured_order_obj"] = json(o.obscured_order_obj());
}

void to_json(json &j, Techdata t)
{
  j["id"] = json(t.id());
  j["mineral_cost"] = json(t.mineral_cost());
  j["vespene_cost"] = json(t.vespene_cost());
  j["research_time"] = json(t.research_time());
  j["energy_required"] = json(t.energy_required());
  j["unknown4"] = json(t.unknown4());
  j["icon"] = json(t.icon());
  j["label"] = json(t.label());
  j["race"] = json(t.race());
  j["unused"] = json(t.unused());

  if (t.has_broodwar_flag())
  {
    j["broodwar_flag"] = json(t.broodwar_flag());
  }
}

void to_json(json &j, Weapon w)
{
  j["id"] = json(w.id());
  j["label"] = json(w.label());
  j["label_tbl"] = json(w.label_tbl());
  j["graphics"] = json(w.graphics());
  if(w.get_generate_objects())
  {
    j["graphics_obj"] = json(w.graphics_obj());
  }
  j["explosion"] = json(w.explosion());
  j["target_flags"] = json(w.target_flags());
  j["minimum_range"] = json(w.minimum_range());
  j["maximum_range"] = json(w.maximum_range());
  j["damage_upgrade"] = json(w.damage_upgrade());
  if(w.get_generate_objects())
  {
    j["damage_upgrade_obj"] = json(w.damage_upgrade_obj());
  }
  j["weapon_type"] = json(w.weapon_type());
  j["weapon_behaviour"] = json(w.weapon_behaviour());
  j["remove_after"] = json(w.remove_after());
  j["explosive_type"] = json(w.explosive_type());
  j["inner_splash_range"] = json(w.inner_splash_range());
  j["medium_splash_range"] = json(w.medium_splash_range());
  j["outer_splash_range"] = json(w.outer_splash_range());
  j["damage_amount"] = json(w.damage_amount());
  j["damage_bonus"] = json(w.damage_bonus());
  j["weapon_cooldown"] = json(w.weapon_cooldown());
  j["damage_factor"] = json(w.damage_factor());
  j["attack_angle"] = json(w.attack_angle());
  j["launch_spin"] = json(w.launch_spin());
  j["x_offset"] = json(w.x_offset());
  j["y_offset"] = json(w.y_offset());
  j["error_message"] = json(w.error_message());
  j["error_message_tbl"] = json(w.error_message_tbl());
  j["icon"] = json(w.icon());

}

void to_json(json &j, Sfx s)
{
  j = json
  {
    {"id", s.id()},
    {"sound_file", s.sound_file()},
    {"sound_file_tbl", s.sound_file_tbl()},
    {"unknown1", s.unknown1()},
    {"unknown2", s.unknown2()},
    {"unknown3", s.unknown3()},
    {"unknown4", s.unknown4()}
  };
}

void to_json(json &j, Portrait p)
{
  j = json
  {
    {"id", p.id()},
    {"video_idle", p.video_idle()},
    {"video_idle_tbl", p.video_idle_tbl()},
    {"video_talking", p.video_talking()},
    {"video_talking_tbl", p.video_talking_tbl()},
    {"change_idle", p.change_idle()},
    {"change_talking", p.change_talking()},
    {"unknown1_idle", p.unknown1_idle()},
    {"unknown1_talking", p.unknown1_talking()}
  };
}

void to_json(json &j, Image i)
{
  j["id"] = json(i.id());
  j["grp"] = json(i.grp());
  j["grp_tbl"] = json(i.grp_tbl());
  j["gfx_turns"] = json(i.gfx_turns());
  j["clickable"] = json(i.clickable());
  j["use_full_iscript"] = json(i.use_full_iscript());
  j["draw_if_cloaked"] = json(i.draw_if_cloaked());
  j["draw_function"] = json(i.draw_function());
  j["remapping"] = json(i.remapping());
  j["iscript"] = json(i.iscript());
  j["shield_overlay"] = json(i.shield_overlay());
  try
  {
    j["shield_overlay_tbl"] = json(i.shield_overlay_tbl());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["attack_overlay"] = json(i.attack_overlay());
  try
  {
    j["attack_overlay_tbl"] = json(i.attack_overlay_tbl());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["damage_overlay"] = json(i.damage_overlay());
  try
  {
    j["damage_overlay_tbl"] = json(i.damage_overlay_tbl());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["special_overlay"] = json(i.special_overlay());
  try
  {
    j["special_overlay_tbl"] = json(i.special_overlay_tbl());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["landing_dust_overlay"] = json(i.landing_dust_overlay());
  try
  {
    j["landing_dust_overlay_tbl"] = json(i.landing_dust_overlay_tbl());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }
}

void to_json(json &j, Sprite s)
{
  j["id"] = json(s.id());
  j["image"] = json(s.image());
  if(s.get_generate_objects())
  {
    j["image_obj"] = json(s.image_obj());
  }

  try
  {
    j["health_bar"] = json(s.health_bar());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["unknown2"] = json(s.unknown2());
  j["is_visible"] = json(s.is_visible());

  try
  {
    j["select_circle_image_size"] = json(s.select_circle_image_size());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["select_circle_vertical_pos"] = json(s.select_circle_vertical_pos());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }
}

void to_json(json &j, Flingy f)
{
  j["id"] = json(f.id());
  j["sprite"] = json(f.sprite());
  if(f.get_generate_objects())
  {
    j["sprite_obj"] = json(f.sprite_obj());
  }
  j["speed"] = json(f.speed());
  j["acceleration"] = json(f.acceleration());
  j["halt_distance"] = json(f.halt_distance());
  j["turn_radius"] = json(f.turn_radius());
  j["unused"] = json(f.unused());
  j["movement_control"] = json(f.movement_control());

}

void to_json(json &j, Unit u)
{
  j["id"] = json(u.id());
  j["id_string"] = json(u.getIDString());
  j["name_tbl"] = json(u.name_tbl());
  j["graphics"] = json(u.graphics());
  if(u.get_generate_objects())
  {
    j["graphics_obj"] = json(u.graphics_obj());
  }
  j["subunit1"] = json(u.subunit1());
  if(u.get_generate_objects())
  {
    try
    {
      j["subunit1_obj"] = json(u.subunit1_obj());
    }
    catch (PropertyNotAvailableException &ex)
    { /*it's fine, do nothing */ }
  }

  j["subunit2"] = json(u.subunit2());

  if(u.get_generate_objects())
  {
    try
    {
      j["subunit2_obj"] = json(u.subunit2_obj());
    }
    catch (PropertyNotAvailableException &ex)
    { /*it's fine, do nothing */ }
  }

  try
  {
    j["infestation"] = json(u.infestation());
    if(u.get_generate_objects())
    {
      j["infestation_obj"] = json(u.infestation_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["construction_animation"] = json(u.construction_animation());
    if(u.get_generate_objects())
    {
      j["construction_animation_obj"] = json(u.construction_animation_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["unit_direction"] = json(u.unit_direction());
  j["shield_enable"] = json(u.shield_enable());
  j["shield_amount"] = json(u.shield_amount());
  j["hitpoints"] = json(u.hitpoints());
  j["elevation_level"] = json(u.elevation_level());
  j["unknown"] = json(u.unknown());
  j["rank"] = json(u.rank());
  j["ai_computer_idle"] = json(u.ai_computer_idle());
  if(u.get_generate_objects())
  {
    j["ai_computer_idle_obj"] = json(u.ai_computer_idle_obj());
  }
  j["ai_human_idle"] = json(u.ai_human_idle());
  if(u.get_generate_objects())
  {
    j["ai_human_idle_obj"] = json(u.ai_human_idle_obj());
  }
  j["ai_return_to_idle"] = json(u.ai_return_to_idle());
  if(u.get_generate_objects())
  {
    j["ai_return_to_idle_obj"] = json(u.ai_return_to_idle_obj());
  }
  j["ai_attack_unit"] = json(u.ai_attack_unit());
  if(u.get_generate_objects())
  {
    j["ai_attack_unit_obj"] = json(u.ai_attack_unit_obj());
  }
  j["ai_attack_move"] = json(u.ai_attack_move());
  if(u.get_generate_objects())
  {
    j["ai_attack_move_obj"] = json(u.ai_attack_move_obj());
  }

  try
  {
    j["ground_weapon"] = json(u.ground_weapon());
    if(u.get_generate_objects())
    {
      j["ground_weapon_obj"] = json(u.ground_weapon_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  if (u.is_format_bw())
  {
    j["max_ground_hits"] = json(u.max_ground_hits());
  }

  try
  {
    j["air_weapon"] = json(u.air_weapon());
    if(u.get_generate_objects())
    {
      j["air_weapon_obj"] = json(u.air_weapon_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  if (u.is_format_bw())
  {
    j["max_air_hits"] = json(u.max_air_hits());
  }

  j["ai_internal"] = json(u.ai_internal());
  j["special_ability_flags"] = json(u.special_ability_flags());
  j["target_acquisition_range"] = json(u.target_acquisition_range());
  j["sight_range"] = json(u.sight_range());
  j["armor_upgrade"] = json(u.armor_upgrade());
  j["unit_size"] = json(u.unit_size());
  j["armor"] = json(u.armor());
  j["right_click_action"] = json(u.right_click_action());

  try
  {
    j["ready_sound"] = json(u.ready_sound());
    if(u.get_generate_objects())
    {
      j["ready_sound_obj"] = json(u.ready_sound_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["what_sound_start"] = json(u.what_sound_start());
    j["what_sound_end"] = json(u.what_sound_end());
    if(u.get_generate_objects())
    {
      j["what_sound_obj"] = json(u.what_sound_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["piss_sound_start"] = json(u.piss_sound_start());
    j["piss_sound_end"] = json(u.piss_sound_end());
    if(u.get_generate_objects())
    {
      j["piss_sound_obj"] = json(u.piss_sound_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["what_sound_start"] = json(u.what_sound_start());
    j["what_sound_end"] = json(u.what_sound_end());
    if(u.get_generate_objects())
    {
      j["what_sound_obj"] = json(u.what_sound_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  try
  {
    j["yes_sound_start"] = json(u.yes_sound_start());
    j["yes_sound_end"] = json(u.yes_sound_end());
    if(u.get_generate_objects())
    {
      j["yes_sound_obj"] = json(u.yes_sound_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["staredit_placement_box"] = json(u.staredit_placement_box());

  try
  {
    j["addon_position"] = json(u.addon_position());
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["unit_dimension"] = json(u.unit_dimension());


  try
  {
    j["portrait"] = json(u.portrait());
    if(u.get_generate_objects())
    {
      j["portrait_obj"] = json(u.portrait_obj());
    }
  }
  catch (PropertyNotAvailableException &ex)
  { /*it's fine, do nothing */ }

  j["mineral_cost"] = json(u.mineral_cost());
  j["vespene_cost"] = json(u.vespene_cost());
  j["build_time"] = json(u.build_time());
  j["requirements"] = json(u.requirements());
  j["staredit_group_flags"] = json(u.staredit_group_flags());
  j["supply_required"] = json(u.supply_required());
  j["space_provided"] = json(u.space_provided());
  j["build_score"] = json(u.build_score());
  j["destroy_score"] = json(u.destroy_score());
  j["unit_map_string"] = json(u.unit_map_string());

  if (u.is_format_bw())
  {
    j["broodwar_flag"] = json(u.broodwar_flag());
  }

  j["is_format_bw"] = json(u.is_format_bw());
}

} /* namespace dat */
