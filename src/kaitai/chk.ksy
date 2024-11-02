meta:
  id: chk
  file-extension: chk
  endian: le
  bit-endian: le

seq:
  - id: chunk
    type: chunk_type
    repeat: eos
    
types:
  chunk_type:
    seq:
      - id: tag
        type: str
        size: 4
        encoding: ASCII

      - id: chunk_size
        type: u4
        
      - id: data
        size: chunk_size
        type: data_type

  # `data_type` decides how the `data`- filed is interpreted
  data_type:
    seq:
      - id: content
        type:
          switch-on: _parent.tag
          cases:
            '"VER "': u2_array # Format Version
            '"IVER"': u2_array # Map Version
            '"IVE2"': u2_array # Map Version
            '"VCOD"': u2_array # Verification Code ## TODO later
            '"IOWN"': player_owner_array #StarEdit Player Types
            '"OWNR"': player_owner_array # StarCraft Player Types
            '"ERA "': tileset # Tileset
            '"DIM "': dimension # Map Dimensions
            '"SIDE"': player_races # Player Races
            '"MTXM"': u2_array # StarCraft Terrain
            '"PUNI"': player_unit_restrictions # Player Unit Restrictions
            '"UPGR"': upgrade_restrictions # Upgrade Restrictions
            '"PTEC"': tech_restrictions # Tech Restrictions
            '"UNIT"': placed_units_array # Placed Units
            '"ISOM"': u2_array # Isometric Terrain
            '"TILE"': u2_array # StarEdit Terrain
            '"DD2 "': staredit_sprites_array # StarEdit Sprites (Doodads)
            '"THG2"': starcraft_sprites_array #StarCraft Sprites
            '"MASK"': fog_of_war_layer_array # Fog of War Layer
            '"STR "': string_data # String Data
            '"UPRP"': cuwp_slots_array # CUWP Slots
            '"UPUS"': u1_array # CUWP Slots Used
            '"MRGN"': locations_array # Locations
            '"TRIG"': triggers_array # Triggers
            '"MBRF"': u1_array # Mission Briefings ## TODO later
            '"SPRP"': scenario_properties # Scenario Properties
            '"FORC"': force_settings # Force Settings
            '"WAV "': u4_array # WAV String Indexes
            '"UNIS"': unit_settings # Unit Settings
            '"UPGS"': upgrade_settings # Upgrade Settings
            '"TECS"': tech_settings # Tech Settings
            '"SWNM"': u4_array # Switch Names
            '"COLR"': player_colors # Player Colors
            '"CRGB"': u1_array # Remastered Player Colors ## TODO later
            '"PUPx"': u1_array ## TODO later
            '"PTEx"': u1_array ## TODO later
            '"UNIx"': u1_array ## TODO later
            '"UPGx"': u1_array ## TODO later
            '"TECx"': u1_array ## TODO later
            _: u1_array

  u1_array:
    seq:
      - id: values
        type: u1
        repeat: eos
  
  
  u2_array:
    seq:
      - id: values
        type: u2
        repeat: eos
        
  u4_array:
    seq:
      - id: values
        type: u4
        repeat: eos
  
  player_owner_array:
    seq:
      - id: values
        type: u1
        enum: player_owner_enum
        repeat: eos
  
  tileset:
    seq:
      - id: value
        type: u2
        enum: tileset_enum
        
  dimension:
    seq:
      - id: width
        type: u2
      - id: height
        type: u2
        
  player_races:
    seq:
      - id: value
        type: u1
        enum: player_races_enum
        repeat: eos
        
  player_unit_restrictions:
    seq:
      - id: availability_overwrite
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 228
        
      - id: global_availability
        type: u1
        repeat: expr
        repeat-expr: 228
        
      - id: overwrite_defaults
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 228
        
  upgrade_restrictions:
    seq:
      - id: maximum_level
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 46

      - id: start_level
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 46
        
      - id: default_maximum_level
        type: u1
        repeat: expr
        repeat-expr: 46
        
      - id: default_start_level
        type: u1
        repeat: expr
        repeat-expr: 46
        
      - id: upgrade_order
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 46
        
  tech_restrictions:
    seq:
      - id: availability
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 24

      - id: alreeady_researched
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 24
        
      - id: default_availability
        type: u1
        repeat: expr
        repeat-expr: 24
        
      - id: default_already_research
        type: u1
        repeat: expr
        repeat-expr: 24
        
      - id: use_global_defaults
        type: u1_array
        size: 12
        repeat: expr
        repeat-expr: 24
  
  placed_units_array:
    seq:
      - id: values
        type: placed_units
        repeat: eos
        
  placed_units:
    seq:
      - id: instance_id
        type: u4
        
      - id: coord_x
        type: u2
        
      - id: coord_y
        type: u2
        
      - id: unit_id
        type: u2
        
      - id: relation_type
        type: u2
        
      - id: special_properties
        type: placed_units_special_properties_flags
        
      - id: mapmaker_properties
        type: placed_units_mapmaker_properties_flags
        
      - id: player_owner
        type: u1
        
      - id: hit_points
        type: u1
        
      - id: shield_points
        type: u1
        
      - id: energy_points
        type: u1
        
      - id: resource_amount
        type: u4
        
      - id: units_in_hangar
        type: u2
        
      - id: unit_state
        type: placed_units_state_flags
        
      - id: unused
        type: u4
        
      - id: linked_unit
        type: u4
        
  placed_units_special_properties_flags:
    seq:
      - id: cloak_valid
        type: b1
        
      - id: burrow_valid
        type: b1
        
      - id: transit_valid
        type: b1
        
      - id: hallucinated_valid
        type: b1
        
      - id: invincible_valid
        type: b1
        
      - id: unused
        type: b11
        
  placed_units_mapmaker_properties_flags:
    seq:
      - id: owner_valid
        type: b1
        
      - id: hp_valid
        type: b1
        
      - id: shields_valid
        type: b1
        
      - id: energy_valid
        type: b1
        
      - id: resource_amount_valid
        type: b1
        
      - id: amount_in_hangar_valid
        type: b1
        
      - id: unused
        type: b10
        
  placed_units_state_flags:
    seq:
      - id: cloacked
        type: b1
        
      - id: burrowed
        type: b1
        
      - id: transit
        type: b1
        
      - id: hallucinated
        type: b1
        
      - id: invincible
        type: b1
        
      - id: unused
        type: b11
  
  staredit_sprites_array:
    seq:
      - id: values
        type: staredit_sprites
        repeat: eos
      
  staredit_sprites:
    seq:
      - id: doodad_number
        type: u2
        
      - id: coord_x
        type: u2
        
      - id: coord_y
        type: u2
        
      - id: owner
        type: u1
        
      - id: disabled
        type: u1
        
  starcraft_sprites_array:
    seq:
      - id: values
        type: starcraft_sprites
        repeat: eos
      
  starcraft_sprites:
    seq:
      - id: unit_or_sprite_number
        type: u2
        
      - id: coord_x
        type: u2
        
      - id: coord_y
        type: u2
        
      - id: owner
        type: u1
        
      - id: unused
        type: u1
        
      - id: use_flags
        type: starcraft_sprites_use_flasgs
        
  starcraft_sprites_use_flasgs:
    seq:
      - id: unused
        type: b12
        
      - id: draw_as_sprite
        type: b1
        
      - id: unused2
        type: b2
        
      - id: disabled
        type: b1
        
  fog_of_war_layer_array:
    seq:
      - id: values
        type: fog_of_war_layer
        repeat: eos
        
  fog_of_war_layer:
    seq:
      - id: player1
        type: b1
        
      - id: player2
        type: b1
        
      - id: player3
        type: b1
        
      - id: player4
        type: b1
        
      - id: player5
        type: b1
        
      - id: player6
        type: b1
        
      - id: player7
        type: b1

      - id: player8
        type: b1
        
  string_data:
    seq:
      - id: strings_number
        type: u2
        
      - id: strings
        type: string_address
        repeat: expr
        repeat-expr: strings_number
        
  string_address:
    seq:
      - id: address
        type: u2
    instances:
      string:
        pos: address
        type: strz
        encoding: ASCII
        
  cuwp_slots_array:
    seq:
      - id: values
        type: cuwp_slots
        repeat: expr
        repeat-expr: 64
        
  cuwp_slots:
    seq:
      - id: special_properties
        type: cuwp_slots_special_properties_flags
        
      - id: validity
        type: cuwp_slots_validity_flags
        
      - id: unit_owner
        type: u1
        
      - id: hit_points
        type: u1
        
      - id: shield_points
        type: u1
        
      - id: energy_points
        type: u1
        
      - id: resource_amount
        type: u4
        
      - id: units_in_hangar
        type: u2
        
      - id: unit_flags
        type: cuwp_slots_unit_flags
        
      - id: unused
        type: u4
        
  cuwp_slots_special_properties_flags:
    seq:
      - id: cloak_valid
        type: b1
        
      - id: burrowed_valid
        type: b1
        
      - id: transit_valid
        type: b1
        
      - id: hallucinated_valid
        type: b1
        
      - id: invincible_valid
        type: b1
        
      - id: unused
        type: b11
        
  cuwp_slots_validity_flags:
    seq:
      - id: owner_valid
        type: b1
        
      - id: hp_valid
        type: b1
        
      - id: shields_valid
        type: b1
        
      - id: energy_valid
        type: b1
        
      - id: resource_amount_valid
        type: b1
        
      - id: amount_in_hangar_valid
        type: b1

      - id: unknown
        type: b10

  cuwp_slots_unit_flags:
    seq:
      - id: cloaked
        type: b1
        
      - id: burrowed
        type: b1

      - id: transit
        type: b1
        
      - id: hallucinated
        type: b1
        
      - id: invincible
        type: b1

      - id: unused
        type: b11

  locations_array:
    seq:
      - id: values
        type: locations
        repeat: eos

  locations:
    seq:
      - id: coord_x1
        type: u4
        
      - id: coord_y1
        type: u4
        
      - id: coord_x2
        type: u4
        
      - id: coord_y2
        type: u4
        
      - id: string_number
        type: u2
        
      - id: elevation
        type: locations_elevation_flags
        
  locations_elevation_flags:
    seq:
      - id: low_ground
        type: b1
        
      - id: medium_ground
        type: b1
        
      - id: high_ground
        type: b1
        
      - id: low_air
        type: b1
        
      - id: medium_air
        type: b1
        
      - id: high_air
        type: b1
        
      - id: unused
        type: b10
        
  triggers_array:
    seq:
      - id: values
        type: triggers
        repeat: eos
        
  triggers:
    seq:
      - id: conditions
        type: trigger_condition
        repeat: expr
        repeat-expr: 16
        
      - id: actions
        type: trigger_actions
        repeat: expr
        repeat-expr: 64
        
      - id: execution
        type: trigger_execution
        
  trigger_condition:
    seq:
      - id: location
        type: u4
        
      - id: group
        type: u4
      
      - id: amount
        type: u4
        
      - id: unit_id
        type: u2

      - id: rule
        type: u1

      - id: condition
        type: u1
        
      - id: type
        type: u1
        
      - id: flags
        type: u1
        
      - id: internal_used
        type: u2
        
  trigger_actions:
    seq:
      - id: source
        type: u4
        
      - id: string_number
        type: u4
        
      - id: wav_string
        type: u4
        
      - id: time
        type: u4
        
      - id: first_affected
        type: u4
        
      - id: second_affected
        type: u4
        
      - id: type
        type: u2
        
      - id: action
        type: u1
        
      - id: unit_number
        type: u1
        
      - id: flags
        type: u1
        
      - id: internal_used
        size: 3
      
  trigger_execution:
    seq:
      - id: flags
        type: u4
        
      - id: list
        type: u1
        repeat: expr
        repeat-expr: 28

  scenario_properties:
    seq:
      - id: name
        type: u2
        
      - id: decription
        type: u2

  force_settings:
    seq:
      - id: player_force
        type: u1
        repeat: expr
        repeat-expr: 8

      - id: force_string
        type: u2
        repeat: expr
        repeat-expr: 4

      - id: flags
        type: force_settings_flags
        repeat: expr
        repeat-expr: 4

  force_settings_flags:
    seq:
      - id: random_start_location
        type: b1
        
      - id: allies
        type: b1
        
      - id: allied_victory
        type: b1
        
      - id: shared_vision
        type: b1
        
      - id: unused
        type: b4

  unit_settings:
    seq:
      - id: use_defaults
        type: u1
        repeat: expr
        repeat-expr: 228
        
      - id: hit_points
        type: u4
        repeat: expr
        repeat-expr: 228
        
      - id: shield_points
        type: u2
        repeat: expr
        repeat-expr: 228
        
      - id: armor_points
        type: u1
        repeat: expr
        repeat-expr: 228
        
      - id: build_time
        type: u2
        repeat: expr
        repeat-expr: 228
        
      - id: mineral_costs
        type: u2
        repeat: expr
        repeat-expr: 228
        
      - id: gas_costs
        type: u2
        repeat: expr
        repeat-expr: 228
        
      - id: string_num
        type: u2
        repeat: expr
        repeat-expr: 228
        
      - id: base_weapon_damage
        type: u2
        repeat: expr
        repeat-expr: 100
        
      - id: upgrade_bonus_weapon_damage
        type: u2
        repeat: expr
        repeat-expr: 100
        
  upgrade_settings:
    seq:
      - id: default_settings
        type: u1
        repeat: expr
        repeat-expr: 46
      
      - id: base_mineral_cost
        type: u2
        repeat: expr
        repeat-expr: 46
      
      - id: mineral_cost_factor
        type: u2
        repeat: expr
        repeat-expr: 46
        
      - id: base_gas_cost
        type: u2
        repeat: expr
        repeat-expr: 46
        
      - id: gas_cost_factor
        type: u2
        repeat: expr
        repeat-expr: 46
        
      - id: base_time
        type: u2
        repeat: expr
        repeat-expr: 46
        
      - id: time_factor
        type: u2
        repeat: expr
        repeat-expr: 46
        
  tech_settings:
    seq:
      - id: default_settings
        type: u1
        repeat: expr
        repeat-expr: 24
        
      - id: mineral_cost
        type: u2
        repeat: expr
        repeat-expr: 24
        
      - id: gas_cost
        type: u2
        repeat: expr
        repeat-expr: 24
        
      - id: time_required
        type: u2
        repeat: expr
        repeat-expr: 24
        
      - id: energy_cost
        type: u2
        repeat: expr
        repeat-expr: 24
        
  player_colors:
    seq:
      - id: color
        type: u1
        enum: player_colors_enum
        repeat: expr
        repeat-expr: 8
        
enums:
  player_owner_enum:
    0: inactive
    1: computer_game
    2: occupied_by_human_player
    3: rescue_passive
    4: unused
    5: computer
    6: human_open_slot
    7: neutral
    8: closed_slot
    
  tileset_enum:
    0: badlands
    1: space_platform
    2: installation
    3: ashworld
    4: jungle
    5: dessert
    6: artic
    7: twilight
    
  player_races_enum:
    0: zerg
    1: terran
    2: protoss
    3: invalid_independent
    4: invalid_neutral
    5: user_selectable
    6: random # forced; acts as a selected race
    7: inactive
    
  player_colors_enum:
    0: red # (#F40404)
    1: blue # (#0C48CC)
    2: teal # (#2CB494)
    3: purple # (#88409C)
    4: orange # (#F88C14)
    5: brown # (#703014)
    6: white # (#CCE0D0)
    7: yellow # (#FCFC38)
    8: green # (#088008)
    9: pale_yellow # (#FCFC7C)
    10: tan # (#ECC4B0)
    11: azure # (Neutral color, #4068D4)
    
    
