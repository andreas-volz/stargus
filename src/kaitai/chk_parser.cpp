// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "chk_parser.h"

chk_parser_t::chk_parser_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_chunk = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::_read() {
    m_chunk = new std::vector<chunk_type_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_chunk->push_back(new chunk_type_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::~chk_parser_t() {
    _clean_up();
}

void chk_parser_t::_clean_up() {
    if (m_chunk) {
        for (std::vector<chunk_type_t*>::iterator it = m_chunk->begin(); it != m_chunk->end(); ++it) {
            delete *it;
        }
        delete m_chunk; m_chunk = 0;
    }
}

chk_parser_t::locations_t::locations_t(kaitai::kstream* p__io, chk_parser_t::locations_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_elevation = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::locations_t::_read() {
    m_coord_x1 = m__io->read_u4le();
    m_coord_y1 = m__io->read_u4le();
    m_coord_x2 = m__io->read_u4le();
    m_coord_y2 = m__io->read_u4le();
    m_string_number = m__io->read_u2le();
    m_elevation = new locations_elevation_flags_t(m__io, this, m__root);
}

chk_parser_t::locations_t::~locations_t() {
    _clean_up();
}

void chk_parser_t::locations_t::_clean_up() {
    if (m_elevation) {
        delete m_elevation; m_elevation = 0;
    }
}

chk_parser_t::trigger_execution_t::trigger_execution_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_list = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::trigger_execution_t::_read() {
    m_flags = m__io->read_u4le();
    m_list = new std::vector<uint8_t>();
    const int l_list = 28;
    for (int i = 0; i < l_list; i++) {
        m_list->push_back(m__io->read_u1());
    }
}

chk_parser_t::trigger_execution_t::~trigger_execution_t() {
    _clean_up();
}

void chk_parser_t::trigger_execution_t::_clean_up() {
    if (m_list) {
        delete m_list; m_list = 0;
    }
}

chk_parser_t::player_owner_array_t::player_owner_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::player_owner_array_t::_read() {
    m_values = new std::vector<player_owner_enum_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(static_cast<chk_parser_t::player_owner_enum_t>(m__io->read_u1()));
            i++;
        }
    }
}

chk_parser_t::player_owner_array_t::~player_owner_array_t() {
    _clean_up();
}

void chk_parser_t::player_owner_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_parser_t::upgrade_restrictions_t::upgrade_restrictions_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_repeat_len = p_repeat_len;
    m_maximum_level = 0;
    m__raw_maximum_level = 0;
    m__io__raw_maximum_level = 0;
    m_start_level = 0;
    m__raw_start_level = 0;
    m__io__raw_start_level = 0;
    m_default_maximum_level = 0;
    m_default_start_level = 0;
    m_upgrade_order = 0;
    m__raw_upgrade_order = 0;
    m__io__raw_upgrade_order = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::upgrade_restrictions_t::_read() {
    m__raw_maximum_level = new std::vector<std::string>();
    m__io__raw_maximum_level = new std::vector<kaitai::kstream*>();
    m_maximum_level = new std::vector<u1_array_t*>();
    const int l_maximum_level = repeat_len();
    for (int i = 0; i < l_maximum_level; i++) {
        m__raw_maximum_level->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_maximum_level = new kaitai::kstream(m__raw_maximum_level->at(m__raw_maximum_level->size() - 1));
        m__io__raw_maximum_level->push_back(io__raw_maximum_level);
        m_maximum_level->push_back(new u1_array_t(io__raw_maximum_level, this, m__root));
    }
    m__raw_start_level = new std::vector<std::string>();
    m__io__raw_start_level = new std::vector<kaitai::kstream*>();
    m_start_level = new std::vector<u1_array_t*>();
    const int l_start_level = repeat_len();
    for (int i = 0; i < l_start_level; i++) {
        m__raw_start_level->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_start_level = new kaitai::kstream(m__raw_start_level->at(m__raw_start_level->size() - 1));
        m__io__raw_start_level->push_back(io__raw_start_level);
        m_start_level->push_back(new u1_array_t(io__raw_start_level, this, m__root));
    }
    m_default_maximum_level = new std::vector<uint8_t>();
    const int l_default_maximum_level = repeat_len();
    for (int i = 0; i < l_default_maximum_level; i++) {
        m_default_maximum_level->push_back(m__io->read_u1());
    }
    m_default_start_level = new std::vector<uint8_t>();
    const int l_default_start_level = repeat_len();
    for (int i = 0; i < l_default_start_level; i++) {
        m_default_start_level->push_back(m__io->read_u1());
    }
    m__raw_upgrade_order = new std::vector<std::string>();
    m__io__raw_upgrade_order = new std::vector<kaitai::kstream*>();
    m_upgrade_order = new std::vector<u1_array_t*>();
    const int l_upgrade_order = repeat_len();
    for (int i = 0; i < l_upgrade_order; i++) {
        m__raw_upgrade_order->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_upgrade_order = new kaitai::kstream(m__raw_upgrade_order->at(m__raw_upgrade_order->size() - 1));
        m__io__raw_upgrade_order->push_back(io__raw_upgrade_order);
        m_upgrade_order->push_back(new u1_array_t(io__raw_upgrade_order, this, m__root));
    }
}

chk_parser_t::upgrade_restrictions_t::~upgrade_restrictions_t() {
    _clean_up();
}

void chk_parser_t::upgrade_restrictions_t::_clean_up() {
    if (m__raw_maximum_level) {
        delete m__raw_maximum_level; m__raw_maximum_level = 0;
    }
    if (m__io__raw_maximum_level) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_maximum_level->begin(); it != m__io__raw_maximum_level->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_maximum_level; m__io__raw_maximum_level = 0;
    }
    if (m_maximum_level) {
        for (std::vector<u1_array_t*>::iterator it = m_maximum_level->begin(); it != m_maximum_level->end(); ++it) {
            delete *it;
        }
        delete m_maximum_level; m_maximum_level = 0;
    }
    if (m__raw_start_level) {
        delete m__raw_start_level; m__raw_start_level = 0;
    }
    if (m__io__raw_start_level) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_start_level->begin(); it != m__io__raw_start_level->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_start_level; m__io__raw_start_level = 0;
    }
    if (m_start_level) {
        for (std::vector<u1_array_t*>::iterator it = m_start_level->begin(); it != m_start_level->end(); ++it) {
            delete *it;
        }
        delete m_start_level; m_start_level = 0;
    }
    if (m_default_maximum_level) {
        delete m_default_maximum_level; m_default_maximum_level = 0;
    }
    if (m_default_start_level) {
        delete m_default_start_level; m_default_start_level = 0;
    }
    if (m__raw_upgrade_order) {
        delete m__raw_upgrade_order; m__raw_upgrade_order = 0;
    }
    if (m__io__raw_upgrade_order) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_upgrade_order->begin(); it != m__io__raw_upgrade_order->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_upgrade_order; m__io__raw_upgrade_order = 0;
    }
    if (m_upgrade_order) {
        for (std::vector<u1_array_t*>::iterator it = m_upgrade_order->begin(); it != m_upgrade_order->end(); ++it) {
            delete *it;
        }
        delete m_upgrade_order; m_upgrade_order = 0;
    }
}

chk_parser_t::remastered_player_colors_t::remastered_player_colors_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_color_select = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::remastered_player_colors_t::_read() {
    m_red = m__io->read_u1();
    m_green = m__io->read_u1();
    m_blue = m__io->read_u1();
    m_color_select = new std::vector<color_select_enum_t>();
    const int l_color_select = 8;
    for (int i = 0; i < l_color_select; i++) {
        m_color_select->push_back(static_cast<chk_parser_t::color_select_enum_t>(m__io->read_u1()));
    }
}

chk_parser_t::remastered_player_colors_t::~remastered_player_colors_t() {
    _clean_up();
}

void chk_parser_t::remastered_player_colors_t::_clean_up() {
    if (m_color_select) {
        delete m_color_select; m_color_select = 0;
    }
}

chk_parser_t::special_properties_flags_t::special_properties_flags_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::special_properties_flags_t::_read() {
    m_cloacked = m__io->read_bits_int_le(1);
    m_burrowed = m__io->read_bits_int_le(1);
    m_transit = m__io->read_bits_int_le(1);
    m_hallucinated = m__io->read_bits_int_le(1);
    m_invincible = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(11);
}

chk_parser_t::special_properties_flags_t::~special_properties_flags_t() {
    _clean_up();
}

void chk_parser_t::special_properties_flags_t::_clean_up() {
}

chk_parser_t::string_data_t::string_data_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_strings = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::string_data_t::_read() {
    m_strings_number = m__io->read_u2le();
    m_strings = new std::vector<string_address_t*>();
    const int l_strings = strings_number();
    for (int i = 0; i < l_strings; i++) {
        m_strings->push_back(new string_address_t(m__io, this, m__root));
    }
}

chk_parser_t::string_data_t::~string_data_t() {
    _clean_up();
}

void chk_parser_t::string_data_t::_clean_up() {
    if (m_strings) {
        for (std::vector<string_address_t*>::iterator it = m_strings->begin(); it != m_strings->end(); ++it) {
            delete *it;
        }
        delete m_strings; m_strings = 0;
    }
}

chk_parser_t::staredit_sprites_array_t::staredit_sprites_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::staredit_sprites_array_t::_read() {
    m_values = new std::vector<staredit_sprites_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new staredit_sprites_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::staredit_sprites_array_t::~staredit_sprites_array_t() {
    _clean_up();
}

void chk_parser_t::staredit_sprites_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<staredit_sprites_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::string_address_t::string_address_t(kaitai::kstream* p__io, chk_parser_t::string_data_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_string = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::string_address_t::_read() {
    m_address = m__io->read_u2le();
}

chk_parser_t::string_address_t::~string_address_t() {
    _clean_up();
}

void chk_parser_t::string_address_t::_clean_up() {
    if (f_string) {
    }
}

std::string chk_parser_t::string_address_t::string() {
    if (f_string)
        return m_string;
    std::streampos _pos = m__io->pos();
    m__io->seek(address());
    m_string = kaitai::kstream::bytes_to_str(m__io->read_bytes_term(0, false, true, true), std::string("ASCII"));
    m__io->seek(_pos);
    f_string = true;
    return m_string;
}

chk_parser_t::trigger_condition_t::trigger_condition_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::trigger_condition_t::_read() {
    m_location = m__io->read_u4le();
    m_group = m__io->read_u4le();
    m_amount = m__io->read_u4le();
    m_unit_id = m__io->read_u2le();
    m_rule = m__io->read_u1();
    m_condition = m__io->read_u1();
    m_type = m__io->read_u1();
    m_flags = m__io->read_u1();
    m_internal_used = m__io->read_u2le();
}

chk_parser_t::trigger_condition_t::~trigger_condition_t() {
    _clean_up();
}

void chk_parser_t::trigger_condition_t::_clean_up() {
}

chk_parser_t::locations_array_t::locations_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::locations_array_t::_read() {
    m_values = new std::vector<locations_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new locations_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::locations_array_t::~locations_array_t() {
    _clean_up();
}

void chk_parser_t::locations_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<locations_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::locations_elevation_flags_t::locations_elevation_flags_t(kaitai::kstream* p__io, chk_parser_t::locations_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::locations_elevation_flags_t::_read() {
    m_low_ground = m__io->read_bits_int_le(1);
    m_medium_ground = m__io->read_bits_int_le(1);
    m_high_ground = m__io->read_bits_int_le(1);
    m_low_air = m__io->read_bits_int_le(1);
    m_medium_air = m__io->read_bits_int_le(1);
    m_high_air = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(10);
}

chk_parser_t::locations_elevation_flags_t::~locations_elevation_flags_t() {
    _clean_up();
}

void chk_parser_t::locations_elevation_flags_t::_clean_up() {
}

chk_parser_t::cuwp_slots_t::cuwp_slots_t(kaitai::kstream* p__io, chk_parser_t::cuwp_slots_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_special_properties = 0;
    m_mapmaker_properties = 0;
    m_unit_flags = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::cuwp_slots_t::_read() {
    m_special_properties = new special_properties_flags_t(m__io, this, m__root);
    m_mapmaker_properties = new mapmaker_properties_flags_t(m__io, this, m__root);
    m_unit_owner = m__io->read_u1();
    m_hit_points = m__io->read_u1();
    m_shield_points = m__io->read_u1();
    m_energy_points = m__io->read_u1();
    m_resource_amount = m__io->read_u4le();
    m_units_in_hangar = m__io->read_u2le();
    m_unit_flags = new special_properties_flags_t(m__io, this, m__root);
    m_unused = m__io->read_u4le();
}

chk_parser_t::cuwp_slots_t::~cuwp_slots_t() {
    _clean_up();
}

void chk_parser_t::cuwp_slots_t::_clean_up() {
    if (m_special_properties) {
        delete m_special_properties; m_special_properties = 0;
    }
    if (m_mapmaker_properties) {
        delete m_mapmaker_properties; m_mapmaker_properties = 0;
    }
    if (m_unit_flags) {
        delete m_unit_flags; m_unit_flags = 0;
    }
}

chk_parser_t::tileset_t::tileset_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::tileset_t::_read() {
    m_value = static_cast<chk_parser_t::tileset_enum_t>(m__io->read_u2le());
}

chk_parser_t::tileset_t::~tileset_t() {
    _clean_up();
}

void chk_parser_t::tileset_t::_clean_up() {
}

chk_parser_t::player_colors_t::player_colors_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_color = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::player_colors_t::_read() {
    m_color = new std::vector<player_colors_enum_t>();
    const int l_color = 8;
    for (int i = 0; i < l_color; i++) {
        m_color->push_back(static_cast<chk_parser_t::player_colors_enum_t>(m__io->read_u1()));
    }
}

chk_parser_t::player_colors_t::~player_colors_t() {
    _clean_up();
}

void chk_parser_t::player_colors_t::_clean_up() {
    if (m_color) {
        delete m_color; m_color = 0;
    }
}

chk_parser_t::starcraft_sprites_use_flasgs_t::starcraft_sprites_use_flasgs_t(kaitai::kstream* p__io, chk_parser_t::starcraft_sprites_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::starcraft_sprites_use_flasgs_t::_read() {
    m_unused = m__io->read_bits_int_le(12);
    m_draw_as_sprite = m__io->read_bits_int_le(1);
    m_unused2 = m__io->read_bits_int_le(2);
    m_disabled = m__io->read_bits_int_le(1);
}

chk_parser_t::starcraft_sprites_use_flasgs_t::~starcraft_sprites_use_flasgs_t() {
    _clean_up();
}

void chk_parser_t::starcraft_sprites_use_flasgs_t::_clean_up() {
}

chk_parser_t::mapmaker_properties_flags_t::mapmaker_properties_flags_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::mapmaker_properties_flags_t::_read() {
    m_owner_valid = m__io->read_bits_int_le(1);
    m_hp_valid = m__io->read_bits_int_le(1);
    m_shields_valid = m__io->read_bits_int_le(1);
    m_energy_valid = m__io->read_bits_int_le(1);
    m_resource_amount_valid = m__io->read_bits_int_le(1);
    m_amount_in_hangar_valid = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(10);
}

chk_parser_t::mapmaker_properties_flags_t::~mapmaker_properties_flags_t() {
    _clean_up();
}

void chk_parser_t::mapmaker_properties_flags_t::_clean_up() {
}

chk_parser_t::tech_settings_t::tech_settings_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_repeat_len = p_repeat_len;
    m_default_settings = 0;
    m_mineral_cost = 0;
    m_gas_cost = 0;
    m_time_required = 0;
    m_energy_cost = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::tech_settings_t::_read() {
    m_default_settings = new std::vector<uint8_t>();
    const int l_default_settings = repeat_len();
    for (int i = 0; i < l_default_settings; i++) {
        m_default_settings->push_back(m__io->read_u1());
    }
    m_mineral_cost = new std::vector<uint16_t>();
    const int l_mineral_cost = repeat_len();
    for (int i = 0; i < l_mineral_cost; i++) {
        m_mineral_cost->push_back(m__io->read_u2le());
    }
    m_gas_cost = new std::vector<uint16_t>();
    const int l_gas_cost = repeat_len();
    for (int i = 0; i < l_gas_cost; i++) {
        m_gas_cost->push_back(m__io->read_u2le());
    }
    m_time_required = new std::vector<uint16_t>();
    const int l_time_required = repeat_len();
    for (int i = 0; i < l_time_required; i++) {
        m_time_required->push_back(m__io->read_u2le());
    }
    m_energy_cost = new std::vector<uint16_t>();
    const int l_energy_cost = repeat_len();
    for (int i = 0; i < l_energy_cost; i++) {
        m_energy_cost->push_back(m__io->read_u2le());
    }
}

chk_parser_t::tech_settings_t::~tech_settings_t() {
    _clean_up();
}

void chk_parser_t::tech_settings_t::_clean_up() {
    if (m_default_settings) {
        delete m_default_settings; m_default_settings = 0;
    }
    if (m_mineral_cost) {
        delete m_mineral_cost; m_mineral_cost = 0;
    }
    if (m_gas_cost) {
        delete m_gas_cost; m_gas_cost = 0;
    }
    if (m_time_required) {
        delete m_time_required; m_time_required = 0;
    }
    if (m_energy_cost) {
        delete m_energy_cost; m_energy_cost = 0;
    }
}

chk_parser_t::fog_of_war_layer_t::fog_of_war_layer_t(kaitai::kstream* p__io, chk_parser_t::fog_of_war_layer_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::fog_of_war_layer_t::_read() {
    m_player1 = m__io->read_bits_int_le(1);
    m_player2 = m__io->read_bits_int_le(1);
    m_player3 = m__io->read_bits_int_le(1);
    m_player4 = m__io->read_bits_int_le(1);
    m_player5 = m__io->read_bits_int_le(1);
    m_player6 = m__io->read_bits_int_le(1);
    m_player7 = m__io->read_bits_int_le(1);
    m_player8 = m__io->read_bits_int_le(1);
}

chk_parser_t::fog_of_war_layer_t::~fog_of_war_layer_t() {
    _clean_up();
}

void chk_parser_t::fog_of_war_layer_t::_clean_up() {
}

chk_parser_t::triggers_array_t::triggers_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::triggers_array_t::_read() {
    m_values = new std::vector<triggers_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new triggers_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::triggers_array_t::~triggers_array_t() {
    _clean_up();
}

void chk_parser_t::triggers_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<triggers_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::unit_settings_t::unit_settings_t(uint8_t p_weapon_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_weapon_repeat_len = p_weapon_repeat_len;
    m_use_defaults = 0;
    m_hit_points = 0;
    m_shield_points = 0;
    m_armor_points = 0;
    m_build_time = 0;
    m_mineral_costs = 0;
    m_gas_costs = 0;
    m_string_num = 0;
    m_base_weapon_damage = 0;
    m_upgrade_bonus_weapon_damage = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::unit_settings_t::_read() {
    m_use_defaults = new std::vector<uint8_t>();
    const int l_use_defaults = 228;
    for (int i = 0; i < l_use_defaults; i++) {
        m_use_defaults->push_back(m__io->read_u1());
    }
    m_hit_points = new std::vector<uint32_t>();
    const int l_hit_points = 228;
    for (int i = 0; i < l_hit_points; i++) {
        m_hit_points->push_back(m__io->read_u4le());
    }
    m_shield_points = new std::vector<uint16_t>();
    const int l_shield_points = 228;
    for (int i = 0; i < l_shield_points; i++) {
        m_shield_points->push_back(m__io->read_u2le());
    }
    m_armor_points = new std::vector<uint8_t>();
    const int l_armor_points = 228;
    for (int i = 0; i < l_armor_points; i++) {
        m_armor_points->push_back(m__io->read_u1());
    }
    m_build_time = new std::vector<uint16_t>();
    const int l_build_time = 228;
    for (int i = 0; i < l_build_time; i++) {
        m_build_time->push_back(m__io->read_u2le());
    }
    m_mineral_costs = new std::vector<uint16_t>();
    const int l_mineral_costs = 228;
    for (int i = 0; i < l_mineral_costs; i++) {
        m_mineral_costs->push_back(m__io->read_u2le());
    }
    m_gas_costs = new std::vector<uint16_t>();
    const int l_gas_costs = 228;
    for (int i = 0; i < l_gas_costs; i++) {
        m_gas_costs->push_back(m__io->read_u2le());
    }
    m_string_num = new std::vector<uint16_t>();
    const int l_string_num = 228;
    for (int i = 0; i < l_string_num; i++) {
        m_string_num->push_back(m__io->read_u2le());
    }
    m_base_weapon_damage = new std::vector<uint16_t>();
    const int l_base_weapon_damage = weapon_repeat_len();
    for (int i = 0; i < l_base_weapon_damage; i++) {
        m_base_weapon_damage->push_back(m__io->read_u2le());
    }
    m_upgrade_bonus_weapon_damage = new std::vector<uint16_t>();
    const int l_upgrade_bonus_weapon_damage = weapon_repeat_len();
    for (int i = 0; i < l_upgrade_bonus_weapon_damage; i++) {
        m_upgrade_bonus_weapon_damage->push_back(m__io->read_u2le());
    }
}

chk_parser_t::unit_settings_t::~unit_settings_t() {
    _clean_up();
}

void chk_parser_t::unit_settings_t::_clean_up() {
    if (m_use_defaults) {
        delete m_use_defaults; m_use_defaults = 0;
    }
    if (m_hit_points) {
        delete m_hit_points; m_hit_points = 0;
    }
    if (m_shield_points) {
        delete m_shield_points; m_shield_points = 0;
    }
    if (m_armor_points) {
        delete m_armor_points; m_armor_points = 0;
    }
    if (m_build_time) {
        delete m_build_time; m_build_time = 0;
    }
    if (m_mineral_costs) {
        delete m_mineral_costs; m_mineral_costs = 0;
    }
    if (m_gas_costs) {
        delete m_gas_costs; m_gas_costs = 0;
    }
    if (m_string_num) {
        delete m_string_num; m_string_num = 0;
    }
    if (m_base_weapon_damage) {
        delete m_base_weapon_damage; m_base_weapon_damage = 0;
    }
    if (m_upgrade_bonus_weapon_damage) {
        delete m_upgrade_bonus_weapon_damage; m_upgrade_bonus_weapon_damage = 0;
    }
}

chk_parser_t::player_unit_restrictions_t::player_unit_restrictions_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_availability_overwrite = 0;
    m__raw_availability_overwrite = 0;
    m__io__raw_availability_overwrite = 0;
    m_global_availability = 0;
    m_overwrite_defaults = 0;
    m__raw_overwrite_defaults = 0;
    m__io__raw_overwrite_defaults = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::player_unit_restrictions_t::_read() {
    m__raw_availability_overwrite = new std::vector<std::string>();
    m__io__raw_availability_overwrite = new std::vector<kaitai::kstream*>();
    m_availability_overwrite = new std::vector<u1_array_t*>();
    const int l_availability_overwrite = 228;
    for (int i = 0; i < l_availability_overwrite; i++) {
        m__raw_availability_overwrite->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_availability_overwrite = new kaitai::kstream(m__raw_availability_overwrite->at(m__raw_availability_overwrite->size() - 1));
        m__io__raw_availability_overwrite->push_back(io__raw_availability_overwrite);
        m_availability_overwrite->push_back(new u1_array_t(io__raw_availability_overwrite, this, m__root));
    }
    m_global_availability = new std::vector<uint8_t>();
    const int l_global_availability = 228;
    for (int i = 0; i < l_global_availability; i++) {
        m_global_availability->push_back(m__io->read_u1());
    }
    m__raw_overwrite_defaults = new std::vector<std::string>();
    m__io__raw_overwrite_defaults = new std::vector<kaitai::kstream*>();
    m_overwrite_defaults = new std::vector<u1_array_t*>();
    const int l_overwrite_defaults = 228;
    for (int i = 0; i < l_overwrite_defaults; i++) {
        m__raw_overwrite_defaults->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_overwrite_defaults = new kaitai::kstream(m__raw_overwrite_defaults->at(m__raw_overwrite_defaults->size() - 1));
        m__io__raw_overwrite_defaults->push_back(io__raw_overwrite_defaults);
        m_overwrite_defaults->push_back(new u1_array_t(io__raw_overwrite_defaults, this, m__root));
    }
}

chk_parser_t::player_unit_restrictions_t::~player_unit_restrictions_t() {
    _clean_up();
}

void chk_parser_t::player_unit_restrictions_t::_clean_up() {
    if (m__raw_availability_overwrite) {
        delete m__raw_availability_overwrite; m__raw_availability_overwrite = 0;
    }
    if (m__io__raw_availability_overwrite) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_availability_overwrite->begin(); it != m__io__raw_availability_overwrite->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_availability_overwrite; m__io__raw_availability_overwrite = 0;
    }
    if (m_availability_overwrite) {
        for (std::vector<u1_array_t*>::iterator it = m_availability_overwrite->begin(); it != m_availability_overwrite->end(); ++it) {
            delete *it;
        }
        delete m_availability_overwrite; m_availability_overwrite = 0;
    }
    if (m_global_availability) {
        delete m_global_availability; m_global_availability = 0;
    }
    if (m__raw_overwrite_defaults) {
        delete m__raw_overwrite_defaults; m__raw_overwrite_defaults = 0;
    }
    if (m__io__raw_overwrite_defaults) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_overwrite_defaults->begin(); it != m__io__raw_overwrite_defaults->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_overwrite_defaults; m__io__raw_overwrite_defaults = 0;
    }
    if (m_overwrite_defaults) {
        for (std::vector<u1_array_t*>::iterator it = m_overwrite_defaults->begin(); it != m_overwrite_defaults->end(); ++it) {
            delete *it;
        }
        delete m_overwrite_defaults; m_overwrite_defaults = 0;
    }
}

chk_parser_t::version_t::version_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::version_t::_read() {
    m_version = m__io->read_u2le();
}

chk_parser_t::version_t::~version_t() {
    _clean_up();
}

void chk_parser_t::version_t::_clean_up() {
}

chk_parser_t::triggers_t::triggers_t(kaitai::kstream* p__io, chk_parser_t::triggers_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_conditions = 0;
    m_actions = 0;
    m_execution = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::triggers_t::_read() {
    m_conditions = new std::vector<trigger_condition_t*>();
    const int l_conditions = 16;
    for (int i = 0; i < l_conditions; i++) {
        m_conditions->push_back(new trigger_condition_t(m__io, this, m__root));
    }
    m_actions = new std::vector<trigger_actions_t*>();
    const int l_actions = 64;
    for (int i = 0; i < l_actions; i++) {
        m_actions->push_back(new trigger_actions_t(m__io, this, m__root));
    }
    m_execution = new trigger_execution_t(m__io, this, m__root);
}

chk_parser_t::triggers_t::~triggers_t() {
    _clean_up();
}

void chk_parser_t::triggers_t::_clean_up() {
    if (m_conditions) {
        for (std::vector<trigger_condition_t*>::iterator it = m_conditions->begin(); it != m_conditions->end(); ++it) {
            delete *it;
        }
        delete m_conditions; m_conditions = 0;
    }
    if (m_actions) {
        for (std::vector<trigger_actions_t*>::iterator it = m_actions->begin(); it != m_actions->end(); ++it) {
            delete *it;
        }
        delete m_actions; m_actions = 0;
    }
    if (m_execution) {
        delete m_execution; m_execution = 0;
    }
}

chk_parser_t::u2_array_t::u2_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::u2_array_t::_read() {
    m_values = new std::vector<uint16_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(m__io->read_u2le());
            i++;
        }
    }
}

chk_parser_t::u2_array_t::~u2_array_t() {
    _clean_up();
}

void chk_parser_t::u2_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_parser_t::placed_units_t::placed_units_t(kaitai::kstream* p__io, chk_parser_t::placed_units_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_special_properties = 0;
    m_mapmaker_properties = 0;
    m_unit_state = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::placed_units_t::_read() {
    m_instance_id = m__io->read_u4le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_unit_id = m__io->read_u2le();
    m_relation_type = m__io->read_u2le();
    m_special_properties = new special_properties_flags_t(m__io, this, m__root);
    m_mapmaker_properties = new mapmaker_properties_flags_t(m__io, this, m__root);
    m_player_owner = m__io->read_u1();
    m_hit_points = m__io->read_u1();
    m_shield_points = m__io->read_u1();
    m_energy_points = m__io->read_u1();
    m_resource_amount = m__io->read_u4le();
    m_units_in_hangar = m__io->read_u2le();
    m_unit_state = new special_properties_flags_t(m__io, this, m__root);
    m_unused = m__io->read_u4le();
    m_linked_unit = m__io->read_u4le();
}

chk_parser_t::placed_units_t::~placed_units_t() {
    _clean_up();
}

void chk_parser_t::placed_units_t::_clean_up() {
    if (m_special_properties) {
        delete m_special_properties; m_special_properties = 0;
    }
    if (m_mapmaker_properties) {
        delete m_mapmaker_properties; m_mapmaker_properties = 0;
    }
    if (m_unit_state) {
        delete m_unit_state; m_unit_state = 0;
    }
}

chk_parser_t::data_type_t::data_type_t(kaitai::kstream* p__io, chk_parser_t::chunk_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::data_type_t::_read() {
    {
        std::string on = _parent()->tag();
        if (on == std::string("TECS")) {
            m_content = new tech_settings_t(24, m__io, this, m__root);
        }
        else if (on == std::string("STR ")) {
            m_content = new string_data_t(m__io, this, m__root);
        }
        else if (on == std::string("TRIG")) {
            m_content = new triggers_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGS")) {
            m_content = new upgrade_settings_t(46, m__io, this, m__root);
        }
        else if (on == std::string("SWNM")) {
            m_content = new u4_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIS")) {
            m_content = new unit_settings_t(100, m__io, this, m__root);
        }
        else if (on == std::string("TECx")) {
            m_content = new tech_settings_t(44, m__io, this, m__root);
        }
        else if (on == std::string("OWNR")) {
            m_content = new player_owner_array_t(m__io, this, m__root);
        }
        else if (on == std::string("WAV ")) {
            m_content = new u4_array_t(m__io, this, m__root);
        }
        else if (on == std::string("THG2")) {
            m_content = new starcraft_sprites_array_t(m__io, this, m__root);
        }
        else if (on == std::string("ERA ")) {
            m_content = new tileset_t(m__io, this, m__root);
        }
        else if (on == std::string("PTEC")) {
            m_content = new tech_restrictions_t(24, m__io, this, m__root);
        }
        else if (on == std::string("ISOM")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("VER ")) {
            m_content = new version_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGR")) {
            m_content = new upgrade_restrictions_t(46, m__io, this, m__root);
        }
        else if (on == std::string("SIDE")) {
            m_content = new player_races_t(m__io, this, m__root);
        }
        else if (on == std::string("PUPx")) {
            m_content = new upgrade_restrictions_t(61, m__io, this, m__root);
        }
        else if (on == std::string("IOWN")) {
            m_content = new player_owner_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIT")) {
            m_content = new placed_units_array_t(m__io, this, m__root);
        }
        else if (on == std::string("VCOD")) {
            m_content = new verification_code_t(m__io, this, m__root);
        }
        else if (on == std::string("FORC")) {
            m_content = new force_settings_t(m__io, this, m__root);
        }
        else if (on == std::string("TILE")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPUS")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("SPRP")) {
            m_content = new scenario_properties_t(m__io, this, m__root);
        }
        else if (on == std::string("IVER")) {
            m_content = new version_t(m__io, this, m__root);
        }
        else if (on == std::string("PTEx")) {
            m_content = new tech_restrictions_t(44, m__io, this, m__root);
        }
        else if (on == std::string("MBRF")) {
            m_content = new triggers_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPRP")) {
            m_content = new cuwp_slots_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MASK")) {
            m_content = new fog_of_war_layer_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIx")) {
            m_content = new unit_settings_t(130, m__io, this, m__root);
        }
        else if (on == std::string("DD2 ")) {
            m_content = new staredit_sprites_array_t(m__io, this, m__root);
        }
        else if (on == std::string("COLR")) {
            m_content = new player_colors_t(m__io, this, m__root);
        }
        else if (on == std::string("DIM ")) {
            m_content = new dimension_t(m__io, this, m__root);
        }
        else if (on == std::string("IVE2")) {
            m_content = new version_t(m__io, this, m__root);
        }
        else if (on == std::string("CRGB")) {
            m_content = new remastered_player_colors_t(m__io, this, m__root);
        }
        else if (on == std::string("MTXM")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MRGN")) {
            m_content = new locations_array_t(m__io, this, m__root);
        }
        else if (on == std::string("TYPE")) {
            m_content = new map_type_t(m__io, this, m__root);
        }
        else if (on == std::string("PUNI")) {
            m_content = new player_unit_restrictions_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGx")) {
            m_content = new upgrade_settings_t(61, m__io, this, m__root);
        }
        else {
            m_content = new u1_array_t(m__io, this, m__root);
        }
    }
}

chk_parser_t::data_type_t::~data_type_t() {
    _clean_up();
}

void chk_parser_t::data_type_t::_clean_up() {
    if (m_content) {
        delete m_content; m_content = 0;
    }
}

chk_parser_t::scenario_properties_t::scenario_properties_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::scenario_properties_t::_read() {
    m_name = m__io->read_u2le();
    m_decription = m__io->read_u2le();
}

chk_parser_t::scenario_properties_t::~scenario_properties_t() {
    _clean_up();
}

void chk_parser_t::scenario_properties_t::_clean_up() {
}

chk_parser_t::starcraft_sprites_t::starcraft_sprites_t(kaitai::kstream* p__io, chk_parser_t::starcraft_sprites_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_use_flags = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::starcraft_sprites_t::_read() {
    m_unit_or_sprite_number = m__io->read_u2le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_owner = m__io->read_u1();
    m_unused = m__io->read_u1();
    m_use_flags = new starcraft_sprites_use_flasgs_t(m__io, this, m__root);
}

chk_parser_t::starcraft_sprites_t::~starcraft_sprites_t() {
    _clean_up();
}

void chk_parser_t::starcraft_sprites_t::_clean_up() {
    if (m_use_flags) {
        delete m_use_flags; m_use_flags = 0;
    }
}

chk_parser_t::player_races_t::player_races_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_value = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::player_races_t::_read() {
    m_value = new std::vector<player_races_enum_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_value->push_back(static_cast<chk_parser_t::player_races_enum_t>(m__io->read_u1()));
            i++;
        }
    }
}

chk_parser_t::player_races_t::~player_races_t() {
    _clean_up();
}

void chk_parser_t::player_races_t::_clean_up() {
    if (m_value) {
        delete m_value; m_value = 0;
    }
}

chk_parser_t::force_settings_t::force_settings_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_player_force = 0;
    m_force_string = 0;
    m_flags = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::force_settings_t::_read() {
    m_player_force = new std::vector<uint8_t>();
    const int l_player_force = 8;
    for (int i = 0; i < l_player_force; i++) {
        m_player_force->push_back(m__io->read_u1());
    }
    m_force_string = new std::vector<uint16_t>();
    const int l_force_string = 4;
    for (int i = 0; i < l_force_string; i++) {
        m_force_string->push_back(m__io->read_u2le());
    }
    m_flags = new std::vector<force_settings_flags_t*>();
    const int l_flags = 4;
    for (int i = 0; i < l_flags; i++) {
        m_flags->push_back(new force_settings_flags_t(m__io, this, m__root));
    }
}

chk_parser_t::force_settings_t::~force_settings_t() {
    _clean_up();
}

void chk_parser_t::force_settings_t::_clean_up() {
    if (m_player_force) {
        delete m_player_force; m_player_force = 0;
    }
    if (m_force_string) {
        delete m_force_string; m_force_string = 0;
    }
    if (m_flags) {
        for (std::vector<force_settings_flags_t*>::iterator it = m_flags->begin(); it != m_flags->end(); ++it) {
            delete *it;
        }
        delete m_flags; m_flags = 0;
    }
}

chk_parser_t::placed_units_array_t::placed_units_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::placed_units_array_t::_read() {
    m_values = new std::vector<placed_units_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new placed_units_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::placed_units_array_t::~placed_units_array_t() {
    _clean_up();
}

void chk_parser_t::placed_units_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<placed_units_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::u4_array_t::u4_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::u4_array_t::_read() {
    m_values = new std::vector<uint32_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(m__io->read_u4le());
            i++;
        }
    }
}

chk_parser_t::u4_array_t::~u4_array_t() {
    _clean_up();
}

void chk_parser_t::u4_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_parser_t::u1_array_t::u1_array_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::u1_array_t::_read() {
    m_values = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(m__io->read_u1());
            i++;
        }
    }
}

chk_parser_t::u1_array_t::~u1_array_t() {
    _clean_up();
}

void chk_parser_t::u1_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_parser_t::map_type_t::map_type_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::map_type_t::_read() {
    m_map_type = m__io->read_u4le();
}

chk_parser_t::map_type_t::~map_type_t() {
    _clean_up();
}

void chk_parser_t::map_type_t::_clean_up() {
}

chk_parser_t::cuwp_slots_array_t::cuwp_slots_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::cuwp_slots_array_t::_read() {
    m_values = new std::vector<cuwp_slots_t*>();
    const int l_values = 64;
    for (int i = 0; i < l_values; i++) {
        m_values->push_back(new cuwp_slots_t(m__io, this, m__root));
    }
}

chk_parser_t::cuwp_slots_array_t::~cuwp_slots_array_t() {
    _clean_up();
}

void chk_parser_t::cuwp_slots_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<cuwp_slots_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::starcraft_sprites_array_t::starcraft_sprites_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::starcraft_sprites_array_t::_read() {
    m_values = new std::vector<starcraft_sprites_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new starcraft_sprites_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::starcraft_sprites_array_t::~starcraft_sprites_array_t() {
    _clean_up();
}

void chk_parser_t::starcraft_sprites_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<starcraft_sprites_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::force_settings_flags_t::force_settings_flags_t(kaitai::kstream* p__io, chk_parser_t::force_settings_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::force_settings_flags_t::_read() {
    m_random_start_location = m__io->read_bits_int_le(1);
    m_allies = m__io->read_bits_int_le(1);
    m_allied_victory = m__io->read_bits_int_le(1);
    m_shared_vision = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(4);
}

chk_parser_t::force_settings_flags_t::~force_settings_flags_t() {
    _clean_up();
}

void chk_parser_t::force_settings_flags_t::_clean_up() {
}

chk_parser_t::fog_of_war_layer_array_t::fog_of_war_layer_array_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_values = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::fog_of_war_layer_array_t::_read() {
    m_values = new std::vector<fog_of_war_layer_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new fog_of_war_layer_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_parser_t::fog_of_war_layer_array_t::~fog_of_war_layer_array_t() {
    _clean_up();
}

void chk_parser_t::fog_of_war_layer_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<fog_of_war_layer_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_parser_t::upgrade_settings_t::upgrade_settings_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_repeat_len = p_repeat_len;
    m_default_settings = 0;
    m_base_mineral_cost = 0;
    m_mineral_cost_factor = 0;
    m_base_gas_cost = 0;
    m_gas_cost_factor = 0;
    m_base_time = 0;
    m_time_factor = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::upgrade_settings_t::_read() {
    m_default_settings = new std::vector<uint8_t>();
    const int l_default_settings = repeat_len();
    for (int i = 0; i < l_default_settings; i++) {
        m_default_settings->push_back(m__io->read_u1());
    }
    n_unused = true;
    if (repeat_len() == 61) {
        n_unused = false;
        m_unused = m__io->read_u1();
    }
    m_base_mineral_cost = new std::vector<uint16_t>();
    const int l_base_mineral_cost = repeat_len();
    for (int i = 0; i < l_base_mineral_cost; i++) {
        m_base_mineral_cost->push_back(m__io->read_u2le());
    }
    m_mineral_cost_factor = new std::vector<uint16_t>();
    const int l_mineral_cost_factor = repeat_len();
    for (int i = 0; i < l_mineral_cost_factor; i++) {
        m_mineral_cost_factor->push_back(m__io->read_u2le());
    }
    m_base_gas_cost = new std::vector<uint16_t>();
    const int l_base_gas_cost = repeat_len();
    for (int i = 0; i < l_base_gas_cost; i++) {
        m_base_gas_cost->push_back(m__io->read_u2le());
    }
    m_gas_cost_factor = new std::vector<uint16_t>();
    const int l_gas_cost_factor = repeat_len();
    for (int i = 0; i < l_gas_cost_factor; i++) {
        m_gas_cost_factor->push_back(m__io->read_u2le());
    }
    m_base_time = new std::vector<uint16_t>();
    const int l_base_time = repeat_len();
    for (int i = 0; i < l_base_time; i++) {
        m_base_time->push_back(m__io->read_u2le());
    }
    m_time_factor = new std::vector<uint16_t>();
    const int l_time_factor = repeat_len();
    for (int i = 0; i < l_time_factor; i++) {
        m_time_factor->push_back(m__io->read_u2le());
    }
}

chk_parser_t::upgrade_settings_t::~upgrade_settings_t() {
    _clean_up();
}

void chk_parser_t::upgrade_settings_t::_clean_up() {
    if (m_default_settings) {
        delete m_default_settings; m_default_settings = 0;
    }
    if (!n_unused) {
    }
    if (m_base_mineral_cost) {
        delete m_base_mineral_cost; m_base_mineral_cost = 0;
    }
    if (m_mineral_cost_factor) {
        delete m_mineral_cost_factor; m_mineral_cost_factor = 0;
    }
    if (m_base_gas_cost) {
        delete m_base_gas_cost; m_base_gas_cost = 0;
    }
    if (m_gas_cost_factor) {
        delete m_gas_cost_factor; m_gas_cost_factor = 0;
    }
    if (m_base_time) {
        delete m_base_time; m_base_time = 0;
    }
    if (m_time_factor) {
        delete m_time_factor; m_time_factor = 0;
    }
}

chk_parser_t::trigger_actions_t::trigger_actions_t(kaitai::kstream* p__io, chk_parser_t::triggers_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::trigger_actions_t::_read() {
    m_source = m__io->read_u4le();
    m_string_number = m__io->read_u4le();
    m_wav_string = m__io->read_u4le();
    m_time = m__io->read_u4le();
    m_first_affected = m__io->read_u4le();
    m_second_affected = m__io->read_u4le();
    m_type = m__io->read_u2le();
    m_action = m__io->read_u1();
    m_unit_number = m__io->read_u1();
    m_flags = m__io->read_u1();
    m_internal_used = m__io->read_bytes(3);
}

chk_parser_t::trigger_actions_t::~trigger_actions_t() {
    _clean_up();
}

void chk_parser_t::trigger_actions_t::_clean_up() {
}

chk_parser_t::staredit_sprites_t::staredit_sprites_t(kaitai::kstream* p__io, chk_parser_t::staredit_sprites_array_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::staredit_sprites_t::_read() {
    m_doodad_number = m__io->read_u2le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_owner = m__io->read_u1();
    m_disabled = m__io->read_u1();
}

chk_parser_t::staredit_sprites_t::~staredit_sprites_t() {
    _clean_up();
}

void chk_parser_t::staredit_sprites_t::_clean_up() {
}

chk_parser_t::verification_code_t::verification_code_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_seed_values = 0;
    m_operation_codes = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::verification_code_t::_read() {
    m_seed_values = new std::vector<uint32_t>();
    const int l_seed_values = 256;
    for (int i = 0; i < l_seed_values; i++) {
        m_seed_values->push_back(m__io->read_u4le());
    }
    m_operation_codes = new std::vector<uint8_t>();
    const int l_operation_codes = 16;
    for (int i = 0; i < l_operation_codes; i++) {
        m_operation_codes->push_back(m__io->read_u1());
    }
}

chk_parser_t::verification_code_t::~verification_code_t() {
    _clean_up();
}

void chk_parser_t::verification_code_t::_clean_up() {
    if (m_seed_values) {
        delete m_seed_values; m_seed_values = 0;
    }
    if (m_operation_codes) {
        delete m_operation_codes; m_operation_codes = 0;
    }
}

chk_parser_t::dimension_t::dimension_t(kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::dimension_t::_read() {
    m_width = m__io->read_u2le();
    m_height = m__io->read_u2le();
}

chk_parser_t::dimension_t::~dimension_t() {
    _clean_up();
}

void chk_parser_t::dimension_t::_clean_up() {
}

chk_parser_t::chunk_type_t::chunk_type_t(kaitai::kstream* p__io, chk_parser_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;
    m__io__raw_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::chunk_type_t::_read() {
    m_tag = kaitai::kstream::bytes_to_str(m__io->read_bytes(4), std::string("ASCII"));
    m_chunk_size = m__io->read_u4le();
    m__raw_data = m__io->read_bytes(chunk_size());
    m__io__raw_data = new kaitai::kstream(m__raw_data);
    m_data = new data_type_t(m__io__raw_data, this, m__root);
}

chk_parser_t::chunk_type_t::~chunk_type_t() {
    _clean_up();
}

void chk_parser_t::chunk_type_t::_clean_up() {
    if (m__io__raw_data) {
        delete m__io__raw_data; m__io__raw_data = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

chk_parser_t::tech_restrictions_t::tech_restrictions_t(uint8_t p_repeat_len, kaitai::kstream* p__io, chk_parser_t::data_type_t* p__parent, chk_parser_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_repeat_len = p_repeat_len;
    m_availability = 0;
    m__raw_availability = 0;
    m__io__raw_availability = 0;
    m_alreeady_researched = 0;
    m__raw_alreeady_researched = 0;
    m__io__raw_alreeady_researched = 0;
    m_default_availability = 0;
    m_default_already_research = 0;
    m_use_global_defaults = 0;
    m__raw_use_global_defaults = 0;
    m__io__raw_use_global_defaults = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_parser_t::tech_restrictions_t::_read() {
    m__raw_availability = new std::vector<std::string>();
    m__io__raw_availability = new std::vector<kaitai::kstream*>();
    m_availability = new std::vector<u1_array_t*>();
    const int l_availability = repeat_len();
    for (int i = 0; i < l_availability; i++) {
        m__raw_availability->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_availability = new kaitai::kstream(m__raw_availability->at(m__raw_availability->size() - 1));
        m__io__raw_availability->push_back(io__raw_availability);
        m_availability->push_back(new u1_array_t(io__raw_availability, this, m__root));
    }
    m__raw_alreeady_researched = new std::vector<std::string>();
    m__io__raw_alreeady_researched = new std::vector<kaitai::kstream*>();
    m_alreeady_researched = new std::vector<u1_array_t*>();
    const int l_alreeady_researched = repeat_len();
    for (int i = 0; i < l_alreeady_researched; i++) {
        m__raw_alreeady_researched->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_alreeady_researched = new kaitai::kstream(m__raw_alreeady_researched->at(m__raw_alreeady_researched->size() - 1));
        m__io__raw_alreeady_researched->push_back(io__raw_alreeady_researched);
        m_alreeady_researched->push_back(new u1_array_t(io__raw_alreeady_researched, this, m__root));
    }
    m_default_availability = new std::vector<uint8_t>();
    const int l_default_availability = repeat_len();
    for (int i = 0; i < l_default_availability; i++) {
        m_default_availability->push_back(m__io->read_u1());
    }
    m_default_already_research = new std::vector<uint8_t>();
    const int l_default_already_research = repeat_len();
    for (int i = 0; i < l_default_already_research; i++) {
        m_default_already_research->push_back(m__io->read_u1());
    }
    m__raw_use_global_defaults = new std::vector<std::string>();
    m__io__raw_use_global_defaults = new std::vector<kaitai::kstream*>();
    m_use_global_defaults = new std::vector<u1_array_t*>();
    const int l_use_global_defaults = repeat_len();
    for (int i = 0; i < l_use_global_defaults; i++) {
        m__raw_use_global_defaults->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_use_global_defaults = new kaitai::kstream(m__raw_use_global_defaults->at(m__raw_use_global_defaults->size() - 1));
        m__io__raw_use_global_defaults->push_back(io__raw_use_global_defaults);
        m_use_global_defaults->push_back(new u1_array_t(io__raw_use_global_defaults, this, m__root));
    }
}

chk_parser_t::tech_restrictions_t::~tech_restrictions_t() {
    _clean_up();
}

void chk_parser_t::tech_restrictions_t::_clean_up() {
    if (m__raw_availability) {
        delete m__raw_availability; m__raw_availability = 0;
    }
    if (m__io__raw_availability) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_availability->begin(); it != m__io__raw_availability->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_availability; m__io__raw_availability = 0;
    }
    if (m_availability) {
        for (std::vector<u1_array_t*>::iterator it = m_availability->begin(); it != m_availability->end(); ++it) {
            delete *it;
        }
        delete m_availability; m_availability = 0;
    }
    if (m__raw_alreeady_researched) {
        delete m__raw_alreeady_researched; m__raw_alreeady_researched = 0;
    }
    if (m__io__raw_alreeady_researched) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_alreeady_researched->begin(); it != m__io__raw_alreeady_researched->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_alreeady_researched; m__io__raw_alreeady_researched = 0;
    }
    if (m_alreeady_researched) {
        for (std::vector<u1_array_t*>::iterator it = m_alreeady_researched->begin(); it != m_alreeady_researched->end(); ++it) {
            delete *it;
        }
        delete m_alreeady_researched; m_alreeady_researched = 0;
    }
    if (m_default_availability) {
        delete m_default_availability; m_default_availability = 0;
    }
    if (m_default_already_research) {
        delete m_default_already_research; m_default_already_research = 0;
    }
    if (m__raw_use_global_defaults) {
        delete m__raw_use_global_defaults; m__raw_use_global_defaults = 0;
    }
    if (m__io__raw_use_global_defaults) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_use_global_defaults->begin(); it != m__io__raw_use_global_defaults->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_use_global_defaults; m__io__raw_use_global_defaults = 0;
    }
    if (m_use_global_defaults) {
        for (std::vector<u1_array_t*>::iterator it = m_use_global_defaults->begin(); it != m_use_global_defaults->end(); ++it) {
            delete *it;
        }
        delete m_use_global_defaults; m_use_global_defaults = 0;
    }
}
