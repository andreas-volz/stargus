#ifndef CHK_PARSER_H_
#define CHK_PARSER_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class chk_parser_t : public kaitai::kstruct {

public:
    class locations_t;
    class trigger_execution_t;
    class player_owner_array_t;
    class upgrade_restrictions_t;
    class remastered_player_colors_t;
    class special_properties_flags_t;
    class string_data_t;
    class staredit_sprites_array_t;
    class string_address_t;
    class trigger_condition_t;
    class locations_array_t;
    class locations_elevation_flags_t;
    class cuwp_slots_t;
    class tileset_t;
    class player_colors_t;
    class starcraft_sprites_use_flasgs_t;
    class mapmaker_properties_flags_t;
    class tech_settings_t;
    class fog_of_war_layer_t;
    class triggers_array_t;
    class unit_settings_t;
    class player_unit_restrictions_t;
    class version_t;
    class triggers_t;
    class u2_array_t;
    class placed_units_t;
    class data_type_t;
    class scenario_properties_t;
    class starcraft_sprites_t;
    class player_races_t;
    class force_settings_t;
    class placed_units_array_t;
    class u4_array_t;
    class u1_array_t;
    class map_type_t;
    class cuwp_slots_array_t;
    class starcraft_sprites_array_t;
    class force_settings_flags_t;
    class fog_of_war_layer_array_t;
    class upgrade_settings_t;
    class trigger_actions_t;
    class staredit_sprites_t;
    class verification_code_t;
    class dimension_t;
    class chunk_type_t;
    class tech_restrictions_t;

    enum player_colors_enum_t {
        PLAYER_COLORS_ENUM_RED = 0,
        PLAYER_COLORS_ENUM_BLUE = 1,
        PLAYER_COLORS_ENUM_TEAL = 2,
        PLAYER_COLORS_ENUM_PURPLE = 3,
        PLAYER_COLORS_ENUM_ORANGE = 4,
        PLAYER_COLORS_ENUM_BROWN = 5,
        PLAYER_COLORS_ENUM_WHITE = 6,
        PLAYER_COLORS_ENUM_YELLOW = 7,
        PLAYER_COLORS_ENUM_GREEN = 8,
        PLAYER_COLORS_ENUM_PALE_YELLOW = 9,
        PLAYER_COLORS_ENUM_TAN = 10,
        PLAYER_COLORS_ENUM_AZURE = 11
    };

    enum player_races_enum_t {
        PLAYER_RACES_ENUM_ZERG = 0,
        PLAYER_RACES_ENUM_TERRAN = 1,
        PLAYER_RACES_ENUM_PROTOSS = 2,
        PLAYER_RACES_ENUM_INVALID_INDEPENDENT = 3,
        PLAYER_RACES_ENUM_INVALID_NEUTRAL = 4,
        PLAYER_RACES_ENUM_USER_SELECTABLE = 5,
        PLAYER_RACES_ENUM_RANDOM = 6,
        PLAYER_RACES_ENUM_INACTIVE = 7
    };

    enum color_select_enum_t {
        COLOR_SELECT_ENUM_RANDOM_PREDEFINED = 0,
        COLOR_SELECT_ENUM_PLAYER_CHOICE = 1,
        COLOR_SELECT_ENUM_CUSTOM_RGB = 2,
        COLOR_SELECT_ENUM_COLOR_ID = 3
    };

    enum player_owner_enum_t {
        PLAYER_OWNER_ENUM_INACTIVE = 0,
        PLAYER_OWNER_ENUM_COMPUTER_GAME = 1,
        PLAYER_OWNER_ENUM_OCCUPIED_BY_HUMAN_PLAYER = 2,
        PLAYER_OWNER_ENUM_RESCUE_PASSIVE = 3,
        PLAYER_OWNER_ENUM_UNUSED = 4,
        PLAYER_OWNER_ENUM_COMPUTER = 5,
        PLAYER_OWNER_ENUM_HUMAN_OPEN_SLOT = 6,
        PLAYER_OWNER_ENUM_NEUTRAL = 7,
        PLAYER_OWNER_ENUM_CLOSED_SLOT = 8
    };

    enum tileset_enum_t {
        TILESET_ENUM_BADLANDS = 0,
        TILESET_ENUM_PLATFORM = 1,
        TILESET_ENUM_INSTALL = 2,
        TILESET_ENUM_ASHWORLD = 3,
        TILESET_ENUM_JUNGLE = 4,
        TILESET_ENUM_DESSERT = 5,
        TILESET_ENUM_ARTIC = 6,
        TILESET_ENUM_TWILIGHT = 7
    };

    chk_parser_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, chk_parser_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~chk_parser_t();

    class locations_t : public kaitai::kstruct {

    public:

        locations_t(kaitai::kstream* p__io, chk_parser_t::locations_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~locations_t();

    private:
        uint32_t m_coord_x1;
        uint32_t m_coord_y1;
        uint32_t m_coord_x2;
        uint32_t m_coord_y2;
        uint16_t m_string_number;
        locations_elevation_flags_t* m_elevation;
        chk_parser_t* m__root;
        chk_parser_t::locations_array_t* m__parent;

    public:
        uint32_t coord_x1() const { return m_coord_x1; }
        uint32_t coord_y1() const { return m_coord_y1; }
        uint32_t coord_x2() const { return m_coord_x2; }
        uint32_t coord_y2() const { return m_coord_y2; }
        uint16_t string_number() const { return m_string_number; }
        locations_elevation_flags_t* elevation() const { return m_elevation; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::locations_array_t* _parent() const { return m__parent; }
    };

    class trigger_execution_t : public kaitai::kstruct {

    public:

        trigger_execution_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~trigger_execution_t();

    private:
        uint32_t m_flags;
        std::vector<uint8_t>* m_list;
        chk_parser_t* m__root;
        chk_parser_t::triggers_t* m__parent;

    public:
        uint32_t flags() const { return m_flags; }
        std::vector<uint8_t>* list() const { return m_list; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::triggers_t* _parent() const { return m__parent; }
    };

    class player_owner_array_t : public kaitai::kstruct {

    public:

        player_owner_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~player_owner_array_t();

    private:
        std::vector<player_owner_enum_t>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<player_owner_enum_t>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class upgrade_restrictions_t : public kaitai::kstruct {

    public:

        upgrade_restrictions_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~upgrade_restrictions_t();

    private:
        std::vector<u1_array_t*>* m_maximum_level;
        std::vector<u1_array_t*>* m_start_level;
        std::vector<uint8_t>* m_default_maximum_level;
        std::vector<uint8_t>* m_default_start_level;
        std::vector<u1_array_t*>* m_upgrade_order;
        uint8_t m_repeat_len;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;
        std::vector<std::string>* m__raw_maximum_level;
        std::vector<kaitai::kstream*>* m__io__raw_maximum_level;
        std::vector<std::string>* m__raw_start_level;
        std::vector<kaitai::kstream*>* m__io__raw_start_level;
        std::vector<std::string>* m__raw_upgrade_order;
        std::vector<kaitai::kstream*>* m__io__raw_upgrade_order;

    public:
        std::vector<u1_array_t*>* maximum_level() const { return m_maximum_level; }
        std::vector<u1_array_t*>* start_level() const { return m_start_level; }
        std::vector<uint8_t>* default_maximum_level() const { return m_default_maximum_level; }
        std::vector<uint8_t>* default_start_level() const { return m_default_start_level; }
        std::vector<u1_array_t*>* upgrade_order() const { return m_upgrade_order; }
        uint8_t repeat_len() const { return m_repeat_len; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
        std::vector<std::string>* _raw_maximum_level() const { return m__raw_maximum_level; }
        std::vector<kaitai::kstream*>* _io__raw_maximum_level() const { return m__io__raw_maximum_level; }
        std::vector<std::string>* _raw_start_level() const { return m__raw_start_level; }
        std::vector<kaitai::kstream*>* _io__raw_start_level() const { return m__io__raw_start_level; }
        std::vector<std::string>* _raw_upgrade_order() const { return m__raw_upgrade_order; }
        std::vector<kaitai::kstream*>* _io__raw_upgrade_order() const { return m__io__raw_upgrade_order; }
    };

    class remastered_player_colors_t : public kaitai::kstruct {

    public:

        remastered_player_colors_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~remastered_player_colors_t();

    private:
        uint8_t m_red;
        uint8_t m_green;
        uint8_t m_blue;
        std::vector<color_select_enum_t>* m_color_select;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint8_t red() const { return m_red; }
        uint8_t green() const { return m_green; }
        uint8_t blue() const { return m_blue; }
        std::vector<color_select_enum_t>* color_select() const { return m_color_select; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class special_properties_flags_t : public kaitai::kstruct {

    public:

        special_properties_flags_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~special_properties_flags_t();

    private:
        bool m_cloacked;
        bool m_burrowed;
        bool m_transit;
        bool m_hallucinated;
        bool m_invincible;
        uint64_t m_unused;
        chk_parser_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        bool cloacked() const { return m_cloacked; }
        bool burrowed() const { return m_burrowed; }
        bool transit() const { return m_transit; }
        bool hallucinated() const { return m_hallucinated; }
        bool invincible() const { return m_invincible; }
        uint64_t unused() const { return m_unused; }
        chk_parser_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class string_data_t : public kaitai::kstruct {

    public:

        string_data_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~string_data_t();

    private:
        uint16_t m_strings_number;
        std::vector<string_address_t*>* m_strings;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint16_t strings_number() const { return m_strings_number; }
        std::vector<string_address_t*>* strings() const { return m_strings; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class staredit_sprites_array_t : public kaitai::kstruct {

    public:

        staredit_sprites_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~staredit_sprites_array_t();

    private:
        std::vector<staredit_sprites_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<staredit_sprites_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class string_address_t : public kaitai::kstruct {

    public:

        string_address_t(kaitai::kstream* p__io, chk_parser_t::string_data_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~string_address_t();

    private:
        bool f_string;
        std::string m_string;

    public:
        std::string string();

    private:
        uint16_t m_address;
        chk_parser_t* m__root;
        chk_parser_t::string_data_t* m__parent;

    public:
        uint16_t address() const { return m_address; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::string_data_t* _parent() const { return m__parent; }
    };

    class trigger_condition_t : public kaitai::kstruct {

    public:

        trigger_condition_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~trigger_condition_t();

    private:
        uint32_t m_location;
        uint32_t m_group;
        uint32_t m_amount;
        uint16_t m_unit_id;
        uint8_t m_rule;
        uint8_t m_condition;
        uint8_t m_type;
        uint8_t m_flags;
        uint16_t m_internal_used;
        chk_parser_t* m__root;
        chk_parser_t::triggers_t* m__parent;

    public:
        uint32_t location() const { return m_location; }
        uint32_t group() const { return m_group; }
        uint32_t amount() const { return m_amount; }
        uint16_t unit_id() const { return m_unit_id; }
        uint8_t rule() const { return m_rule; }
        uint8_t condition() const { return m_condition; }
        uint8_t type() const { return m_type; }
        uint8_t flags() const { return m_flags; }
        uint16_t internal_used() const { return m_internal_used; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::triggers_t* _parent() const { return m__parent; }
    };

    class locations_array_t : public kaitai::kstruct {

    public:

        locations_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~locations_array_t();

    private:
        std::vector<locations_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<locations_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class locations_elevation_flags_t : public kaitai::kstruct {

    public:

        locations_elevation_flags_t(kaitai::kstream* p__io, chk_parser_t::locations_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~locations_elevation_flags_t();

    private:
        bool m_low_ground;
        bool m_medium_ground;
        bool m_high_ground;
        bool m_low_air;
        bool m_medium_air;
        bool m_high_air;
        uint64_t m_unused;
        chk_parser_t* m__root;
        chk_parser_t::locations_t* m__parent;

    public:
        bool low_ground() const { return m_low_ground; }
        bool medium_ground() const { return m_medium_ground; }
        bool high_ground() const { return m_high_ground; }
        bool low_air() const { return m_low_air; }
        bool medium_air() const { return m_medium_air; }
        bool high_air() const { return m_high_air; }
        uint64_t unused() const { return m_unused; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::locations_t* _parent() const { return m__parent; }
    };

    class cuwp_slots_t : public kaitai::kstruct {

    public:

        cuwp_slots_t(kaitai::kstream* p__io, chk_parser_t::cuwp_slots_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~cuwp_slots_t();

    private:
        special_properties_flags_t* m_special_properties;
        mapmaker_properties_flags_t* m_mapmaker_properties;
        uint8_t m_unit_owner;
        uint8_t m_hit_points;
        uint8_t m_shield_points;
        uint8_t m_energy_points;
        uint32_t m_resource_amount;
        uint16_t m_units_in_hangar;
        special_properties_flags_t* m_unit_flags;
        uint32_t m_unused;
        chk_parser_t* m__root;
        chk_parser_t::cuwp_slots_array_t* m__parent;

    public:
        special_properties_flags_t* special_properties() const { return m_special_properties; }
        mapmaker_properties_flags_t* mapmaker_properties() const { return m_mapmaker_properties; }
        uint8_t unit_owner() const { return m_unit_owner; }
        uint8_t hit_points() const { return m_hit_points; }
        uint8_t shield_points() const { return m_shield_points; }
        uint8_t energy_points() const { return m_energy_points; }
        uint32_t resource_amount() const { return m_resource_amount; }
        uint16_t units_in_hangar() const { return m_units_in_hangar; }
        special_properties_flags_t* unit_flags() const { return m_unit_flags; }
        uint32_t unused() const { return m_unused; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::cuwp_slots_array_t* _parent() const { return m__parent; }
    };

    class tileset_t : public kaitai::kstruct {

    public:

        tileset_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tileset_t();

    private:
        tileset_enum_t m_value;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        tileset_enum_t value() const { return m_value; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class player_colors_t : public kaitai::kstruct {

    public:

        player_colors_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~player_colors_t();

    private:
        std::vector<player_colors_enum_t>* m_color;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<player_colors_enum_t>* color() const { return m_color; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class starcraft_sprites_use_flasgs_t : public kaitai::kstruct {

    public:

        starcraft_sprites_use_flasgs_t(kaitai::kstream* p__io, chk_parser_t::starcraft_sprites_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~starcraft_sprites_use_flasgs_t();

    private:
        uint64_t m_unused;
        bool m_draw_as_sprite;
        uint64_t m_unused2;
        bool m_disabled;
        chk_parser_t* m__root;
        chk_parser_t::starcraft_sprites_t* m__parent;

    public:
        uint64_t unused() const { return m_unused; }
        bool draw_as_sprite() const { return m_draw_as_sprite; }
        uint64_t unused2() const { return m_unused2; }
        bool disabled() const { return m_disabled; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::starcraft_sprites_t* _parent() const { return m__parent; }
    };

    class mapmaker_properties_flags_t : public kaitai::kstruct {

    public:

        mapmaker_properties_flags_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~mapmaker_properties_flags_t();

    private:
        bool m_owner_valid;
        bool m_hp_valid;
        bool m_shields_valid;
        bool m_energy_valid;
        bool m_resource_amount_valid;
        bool m_amount_in_hangar_valid;
        uint64_t m_unused;
        chk_parser_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        bool owner_valid() const { return m_owner_valid; }
        bool hp_valid() const { return m_hp_valid; }
        bool shields_valid() const { return m_shields_valid; }
        bool energy_valid() const { return m_energy_valid; }
        bool resource_amount_valid() const { return m_resource_amount_valid; }
        bool amount_in_hangar_valid() const { return m_amount_in_hangar_valid; }
        uint64_t unused() const { return m_unused; }
        chk_parser_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class tech_settings_t : public kaitai::kstruct {

    public:

        tech_settings_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tech_settings_t();

    private:
        std::vector<uint8_t>* m_default_settings;
        std::vector<uint16_t>* m_mineral_cost;
        std::vector<uint16_t>* m_gas_cost;
        std::vector<uint16_t>* m_time_required;
        std::vector<uint16_t>* m_energy_cost;
        uint8_t m_repeat_len;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint8_t>* default_settings() const { return m_default_settings; }
        std::vector<uint16_t>* mineral_cost() const { return m_mineral_cost; }
        std::vector<uint16_t>* gas_cost() const { return m_gas_cost; }
        std::vector<uint16_t>* time_required() const { return m_time_required; }
        std::vector<uint16_t>* energy_cost() const { return m_energy_cost; }
        uint8_t repeat_len() const { return m_repeat_len; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class fog_of_war_layer_t : public kaitai::kstruct {

    public:

        fog_of_war_layer_t(kaitai::kstream* p__io, chk_parser_t::fog_of_war_layer_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~fog_of_war_layer_t();

    private:
        bool m_player1;
        bool m_player2;
        bool m_player3;
        bool m_player4;
        bool m_player5;
        bool m_player6;
        bool m_player7;
        bool m_player8;
        chk_parser_t* m__root;
        chk_parser_t::fog_of_war_layer_array_t* m__parent;

    public:
        bool player1() const { return m_player1; }
        bool player2() const { return m_player2; }
        bool player3() const { return m_player3; }
        bool player4() const { return m_player4; }
        bool player5() const { return m_player5; }
        bool player6() const { return m_player6; }
        bool player7() const { return m_player7; }
        bool player8() const { return m_player8; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::fog_of_war_layer_array_t* _parent() const { return m__parent; }
    };

    class triggers_array_t : public kaitai::kstruct {

    public:

        triggers_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~triggers_array_t();

    private:
        std::vector<triggers_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<triggers_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class unit_settings_t : public kaitai::kstruct {

    public:

        unit_settings_t(uint8_t p_weapon_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~unit_settings_t();

    private:
        std::vector<uint8_t>* m_use_defaults;
        std::vector<uint32_t>* m_hit_points;
        std::vector<uint16_t>* m_shield_points;
        std::vector<uint8_t>* m_armor_points;
        std::vector<uint16_t>* m_build_time;
        std::vector<uint16_t>* m_mineral_costs;
        std::vector<uint16_t>* m_gas_costs;
        std::vector<uint16_t>* m_string_num;
        std::vector<uint16_t>* m_base_weapon_damage;
        std::vector<uint16_t>* m_upgrade_bonus_weapon_damage;
        uint8_t m_weapon_repeat_len;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint8_t>* use_defaults() const { return m_use_defaults; }
        std::vector<uint32_t>* hit_points() const { return m_hit_points; }
        std::vector<uint16_t>* shield_points() const { return m_shield_points; }
        std::vector<uint8_t>* armor_points() const { return m_armor_points; }
        std::vector<uint16_t>* build_time() const { return m_build_time; }
        std::vector<uint16_t>* mineral_costs() const { return m_mineral_costs; }
        std::vector<uint16_t>* gas_costs() const { return m_gas_costs; }
        std::vector<uint16_t>* string_num() const { return m_string_num; }
        std::vector<uint16_t>* base_weapon_damage() const { return m_base_weapon_damage; }
        std::vector<uint16_t>* upgrade_bonus_weapon_damage() const { return m_upgrade_bonus_weapon_damage; }
        uint8_t weapon_repeat_len() const { return m_weapon_repeat_len; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class player_unit_restrictions_t : public kaitai::kstruct {

    public:

        player_unit_restrictions_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~player_unit_restrictions_t();

    private:
        std::vector<u1_array_t*>* m_availability_overwrite;
        std::vector<uint8_t>* m_global_availability;
        std::vector<u1_array_t*>* m_overwrite_defaults;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;
        std::vector<std::string>* m__raw_availability_overwrite;
        std::vector<kaitai::kstream*>* m__io__raw_availability_overwrite;
        std::vector<std::string>* m__raw_overwrite_defaults;
        std::vector<kaitai::kstream*>* m__io__raw_overwrite_defaults;

    public:
        std::vector<u1_array_t*>* availability_overwrite() const { return m_availability_overwrite; }
        std::vector<uint8_t>* global_availability() const { return m_global_availability; }
        std::vector<u1_array_t*>* overwrite_defaults() const { return m_overwrite_defaults; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
        std::vector<std::string>* _raw_availability_overwrite() const { return m__raw_availability_overwrite; }
        std::vector<kaitai::kstream*>* _io__raw_availability_overwrite() const { return m__io__raw_availability_overwrite; }
        std::vector<std::string>* _raw_overwrite_defaults() const { return m__raw_overwrite_defaults; }
        std::vector<kaitai::kstream*>* _io__raw_overwrite_defaults() const { return m__io__raw_overwrite_defaults; }
    };

    class version_t : public kaitai::kstruct {

    public:

        version_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~version_t();

    private:
        uint16_t m_version;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint16_t version() const { return m_version; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class triggers_t : public kaitai::kstruct {

    public:

        triggers_t(kaitai::kstream* p__io, chk_parser_t::triggers_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~triggers_t();

    private:
        std::vector<trigger_condition_t*>* m_conditions;
        std::vector<trigger_actions_t*>* m_actions;
        trigger_execution_t* m_execution;
        chk_parser_t* m__root;
        chk_parser_t::triggers_array_t* m__parent;

    public:
        std::vector<trigger_condition_t*>* conditions() const { return m_conditions; }
        std::vector<trigger_actions_t*>* actions() const { return m_actions; }
        trigger_execution_t* execution() const { return m_execution; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::triggers_array_t* _parent() const { return m__parent; }
    };

    class u2_array_t : public kaitai::kstruct {

    public:

        u2_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~u2_array_t();

    private:
        std::vector<uint16_t>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint16_t>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class placed_units_t : public kaitai::kstruct {

    public:

        placed_units_t(kaitai::kstream* p__io, chk_parser_t::placed_units_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~placed_units_t();

    private:
        uint32_t m_instance_id;
        uint16_t m_coord_x;
        uint16_t m_coord_y;
        uint16_t m_unit_id;
        uint16_t m_relation_type;
        special_properties_flags_t* m_special_properties;
        mapmaker_properties_flags_t* m_mapmaker_properties;
        uint8_t m_player_owner;
        uint8_t m_hit_points;
        uint8_t m_shield_points;
        uint8_t m_energy_points;
        uint32_t m_resource_amount;
        uint16_t m_units_in_hangar;
        special_properties_flags_t* m_unit_state;
        uint32_t m_unused;
        uint32_t m_linked_unit;
        chk_parser_t* m__root;
        chk_parser_t::placed_units_array_t* m__parent;

    public:
        uint32_t instance_id() const { return m_instance_id; }
        uint16_t coord_x() const { return m_coord_x; }
        uint16_t coord_y() const { return m_coord_y; }
        uint16_t unit_id() const { return m_unit_id; }
        uint16_t relation_type() const { return m_relation_type; }
        special_properties_flags_t* special_properties() const { return m_special_properties; }
        mapmaker_properties_flags_t* mapmaker_properties() const { return m_mapmaker_properties; }
        uint8_t player_owner() const { return m_player_owner; }
        uint8_t hit_points() const { return m_hit_points; }
        uint8_t shield_points() const { return m_shield_points; }
        uint8_t energy_points() const { return m_energy_points; }
        uint32_t resource_amount() const { return m_resource_amount; }
        uint16_t units_in_hangar() const { return m_units_in_hangar; }
        special_properties_flags_t* unit_state() const { return m_unit_state; }
        uint32_t unused() const { return m_unused; }
        uint32_t linked_unit() const { return m_linked_unit; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::placed_units_array_t* _parent() const { return m__parent; }
    };

    class data_type_t : public kaitai::kstruct {

    public:

        data_type_t(kaitai::kstream* p__io, chk_parser_t::chunk_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_type_t();

    private:
        kaitai::kstruct* m_content;
        chk_parser_t* m__root;
        chk_parser_t::chunk_type_t* m__parent;

    public:
        kaitai::kstruct* content() const { return m_content; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::chunk_type_t* _parent() const { return m__parent; }
    };

    class scenario_properties_t : public kaitai::kstruct {

    public:

        scenario_properties_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~scenario_properties_t();

    private:
        uint16_t m_name;
        uint16_t m_decription;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint16_t name() const { return m_name; }
        uint16_t decription() const { return m_decription; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class starcraft_sprites_t : public kaitai::kstruct {

    public:

        starcraft_sprites_t(kaitai::kstream* p__io, chk_parser_t::starcraft_sprites_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~starcraft_sprites_t();

    private:
        uint16_t m_unit_or_sprite_number;
        uint16_t m_coord_x;
        uint16_t m_coord_y;
        uint8_t m_owner;
        uint8_t m_unused;
        starcraft_sprites_use_flasgs_t* m_use_flags;
        chk_parser_t* m__root;
        chk_parser_t::starcraft_sprites_array_t* m__parent;

    public:
        uint16_t unit_or_sprite_number() const { return m_unit_or_sprite_number; }
        uint16_t coord_x() const { return m_coord_x; }
        uint16_t coord_y() const { return m_coord_y; }
        uint8_t owner() const { return m_owner; }
        uint8_t unused() const { return m_unused; }
        starcraft_sprites_use_flasgs_t* use_flags() const { return m_use_flags; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::starcraft_sprites_array_t* _parent() const { return m__parent; }
    };

    class player_races_t : public kaitai::kstruct {

    public:

        player_races_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~player_races_t();

    private:
        std::vector<player_races_enum_t>* m_value;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<player_races_enum_t>* value() const { return m_value; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class force_settings_t : public kaitai::kstruct {

    public:

        force_settings_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~force_settings_t();

    private:
        std::vector<uint8_t>* m_player_force;
        std::vector<uint16_t>* m_force_string;
        std::vector<force_settings_flags_t*>* m_flags;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint8_t>* player_force() const { return m_player_force; }
        std::vector<uint16_t>* force_string() const { return m_force_string; }
        std::vector<force_settings_flags_t*>* flags() const { return m_flags; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class placed_units_array_t : public kaitai::kstruct {

    public:

        placed_units_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~placed_units_array_t();

    private:
        std::vector<placed_units_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<placed_units_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class u4_array_t : public kaitai::kstruct {

    public:

        u4_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~u4_array_t();

    private:
        std::vector<uint32_t>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint32_t>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class u1_array_t : public kaitai::kstruct {

    public:

        u1_array_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~u1_array_t();

    private:
        std::vector<uint8_t>* m_values;
        chk_parser_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::vector<uint8_t>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class map_type_t : public kaitai::kstruct {

    public:

        map_type_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~map_type_t();

    private:
        uint32_t m_map_type;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint32_t map_type() const { return m_map_type; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class cuwp_slots_array_t : public kaitai::kstruct {

    public:

        cuwp_slots_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~cuwp_slots_array_t();

    private:
        std::vector<cuwp_slots_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<cuwp_slots_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class starcraft_sprites_array_t : public kaitai::kstruct {

    public:

        starcraft_sprites_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~starcraft_sprites_array_t();

    private:
        std::vector<starcraft_sprites_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<starcraft_sprites_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class force_settings_flags_t : public kaitai::kstruct {

    public:

        force_settings_flags_t(kaitai::kstream* p__io, chk_parser_t::force_settings_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~force_settings_flags_t();

    private:
        bool m_random_start_location;
        bool m_allies;
        bool m_allied_victory;
        bool m_shared_vision;
        uint64_t m_unused;
        chk_parser_t* m__root;
        chk_parser_t::force_settings_t* m__parent;

    public:
        bool random_start_location() const { return m_random_start_location; }
        bool allies() const { return m_allies; }
        bool allied_victory() const { return m_allied_victory; }
        bool shared_vision() const { return m_shared_vision; }
        uint64_t unused() const { return m_unused; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::force_settings_t* _parent() const { return m__parent; }
    };

    class fog_of_war_layer_array_t : public kaitai::kstruct {

    public:

        fog_of_war_layer_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~fog_of_war_layer_array_t();

    private:
        std::vector<fog_of_war_layer_t*>* m_values;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<fog_of_war_layer_t*>* values() const { return m_values; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class upgrade_settings_t : public kaitai::kstruct {

    public:

        upgrade_settings_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~upgrade_settings_t();

    private:
        std::vector<uint8_t>* m_default_settings;
        uint8_t m_unused;
        bool n_unused;

    public:
        bool _is_null_unused() { unused(); return n_unused; };

    private:
        std::vector<uint16_t>* m_base_mineral_cost;
        std::vector<uint16_t>* m_mineral_cost_factor;
        std::vector<uint16_t>* m_base_gas_cost;
        std::vector<uint16_t>* m_gas_cost_factor;
        std::vector<uint16_t>* m_base_time;
        std::vector<uint16_t>* m_time_factor;
        uint8_t m_repeat_len;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint8_t>* default_settings() const { return m_default_settings; }
        uint8_t unused() const { return m_unused; }
        std::vector<uint16_t>* base_mineral_cost() const { return m_base_mineral_cost; }
        std::vector<uint16_t>* mineral_cost_factor() const { return m_mineral_cost_factor; }
        std::vector<uint16_t>* base_gas_cost() const { return m_base_gas_cost; }
        std::vector<uint16_t>* gas_cost_factor() const { return m_gas_cost_factor; }
        std::vector<uint16_t>* base_time() const { return m_base_time; }
        std::vector<uint16_t>* time_factor() const { return m_time_factor; }
        uint8_t repeat_len() const { return m_repeat_len; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class trigger_actions_t : public kaitai::kstruct {

    public:

        trigger_actions_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~trigger_actions_t();

    private:
        uint32_t m_source;
        uint32_t m_string_number;
        uint32_t m_wav_string;
        uint32_t m_time;
        uint32_t m_first_affected;
        uint32_t m_second_affected;
        uint16_t m_type;
        uint8_t m_action;
        uint8_t m_unit_number;
        uint8_t m_flags;
        std::string m_internal_used;
        chk_parser_t* m__root;
        chk_parser_t::triggers_t* m__parent;

    public:
        uint32_t source() const { return m_source; }
        uint32_t string_number() const { return m_string_number; }
        uint32_t wav_string() const { return m_wav_string; }
        uint32_t time() const { return m_time; }
        uint32_t first_affected() const { return m_first_affected; }
        uint32_t second_affected() const { return m_second_affected; }
        uint16_t type() const { return m_type; }
        uint8_t action() const { return m_action; }
        uint8_t unit_number() const { return m_unit_number; }
        uint8_t flags() const { return m_flags; }
        std::string internal_used() const { return m_internal_used; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::triggers_t* _parent() const { return m__parent; }
    };

    class staredit_sprites_t : public kaitai::kstruct {

    public:

        staredit_sprites_t(kaitai::kstream* p__io, chk_parser_t::staredit_sprites_array_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~staredit_sprites_t();

    private:
        uint16_t m_doodad_number;
        uint16_t m_coord_x;
        uint16_t m_coord_y;
        uint8_t m_owner;
        uint8_t m_disabled;
        chk_parser_t* m__root;
        chk_parser_t::staredit_sprites_array_t* m__parent;

    public:
        uint16_t doodad_number() const { return m_doodad_number; }
        uint16_t coord_x() const { return m_coord_x; }
        uint16_t coord_y() const { return m_coord_y; }
        uint8_t owner() const { return m_owner; }
        uint8_t disabled() const { return m_disabled; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::staredit_sprites_array_t* _parent() const { return m__parent; }
    };

    class verification_code_t : public kaitai::kstruct {

    public:

        verification_code_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~verification_code_t();

    private:
        std::vector<uint32_t>* m_seed_values;
        std::vector<uint8_t>* m_operation_codes;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        std::vector<uint32_t>* seed_values() const { return m_seed_values; }
        std::vector<uint8_t>* operation_codes() const { return m_operation_codes; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class dimension_t : public kaitai::kstruct {

    public:

        dimension_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~dimension_t();

    private:
        uint16_t m_width;
        uint16_t m_height;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;

    public:
        uint16_t width() const { return m_width; }
        uint16_t height() const { return m_height; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
    };

    class chunk_type_t : public kaitai::kstruct {

    public:

        chunk_type_t(kaitai::kstream* p__io, chk_parser_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~chunk_type_t();

    private:
        std::string m_tag;
        uint32_t m_chunk_size;
        data_type_t* m_data;
        chk_parser_t* m__root;
        chk_parser_t* m__parent;
        std::string m__raw_data;
        kaitai::kstream* m__io__raw_data;

    public:
        std::string tag() const { return m_tag; }
        uint32_t chunk_size() const { return m_chunk_size; }
        data_type_t* data() const { return m_data; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class tech_restrictions_t : public kaitai::kstruct {

    public:

        tech_restrictions_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent = 0, chk_parser_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~tech_restrictions_t();

    private:
        std::vector<u1_array_t*>* m_availability;
        std::vector<u1_array_t*>* m_alreeady_researched;
        std::vector<uint8_t>* m_default_availability;
        std::vector<uint8_t>* m_default_already_research;
        std::vector<u1_array_t*>* m_use_global_defaults;
        uint8_t m_repeat_len;
        chk_parser_t* m__root;
        chk_parser_t::data_type_t* m__parent;
        std::vector<std::string>* m__raw_availability;
        std::vector<kaitai::kstream*>* m__io__raw_availability;
        std::vector<std::string>* m__raw_alreeady_researched;
        std::vector<kaitai::kstream*>* m__io__raw_alreeady_researched;
        std::vector<std::string>* m__raw_use_global_defaults;
        std::vector<kaitai::kstream*>* m__io__raw_use_global_defaults;

    public:
        std::vector<u1_array_t*>* availability() const { return m_availability; }
        std::vector<u1_array_t*>* alreeady_researched() const { return m_alreeady_researched; }
        std::vector<uint8_t>* default_availability() const { return m_default_availability; }
        std::vector<uint8_t>* default_already_research() const { return m_default_already_research; }
        std::vector<u1_array_t*>* use_global_defaults() const { return m_use_global_defaults; }
        uint8_t repeat_len() const { return m_repeat_len; }
        chk_parser_t* _root() const { return m__root; }
        chk_parser_t::data_type_t* _parent() const { return m__parent; }
        std::vector<std::string>* _raw_availability() const { return m__raw_availability; }
        std::vector<kaitai::kstream*>* _io__raw_availability() const { return m__io__raw_availability; }
        std::vector<std::string>* _raw_alreeady_researched() const { return m__raw_alreeady_researched; }
        std::vector<kaitai::kstream*>* _io__raw_alreeady_researched() const { return m__io__raw_alreeady_researched; }
        std::vector<std::string>* _raw_use_global_defaults() const { return m__raw_use_global_defaults; }
        std::vector<kaitai::kstream*>* _io__raw_use_global_defaults() const { return m__io__raw_use_global_defaults; }
    };

private:
    std::vector<chunk_type_t*>* m_chunk;
    chk_parser_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<chunk_type_t*>* chunk() const { return m_chunk; }
    chk_parser_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // CHK_PARSER_H_
