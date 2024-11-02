// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "chk.h"

chk_t::chk_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::_read() {
    m_chunk = new std::vector<chunk_type_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_chunk->push_back(new chunk_type_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::~chk_t() {
    _clean_up();
}

void chk_t::_clean_up() {
    if (m_chunk) {
        for (std::vector<chunk_type_t*>::iterator it = m_chunk->begin(); it != m_chunk->end(); ++it) {
            delete *it;
        }
        delete m_chunk; m_chunk = 0;
    }
}

chk_t::locations_t::locations_t(kaitai::kstream* p__io, chk_t::locations_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::locations_t::_read() {
    m_coord_x1 = m__io->read_u4le();
    m_coord_y1 = m__io->read_u4le();
    m_coord_x2 = m__io->read_u4le();
    m_coord_y2 = m__io->read_u4le();
    m_string_number = m__io->read_u2le();
    m_elevation = new locations_elevation_flags_t(m__io, this, m__root);
}

chk_t::locations_t::~locations_t() {
    _clean_up();
}

void chk_t::locations_t::_clean_up() {
    if (m_elevation) {
        delete m_elevation; m_elevation = 0;
    }
}

chk_t::player_owner_array_t::player_owner_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::player_owner_array_t::_read() {
    m_values = new std::vector<player_owner_enum_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(static_cast<chk_t::player_owner_enum_t>(m__io->read_u1()));
            i++;
        }
    }
}

chk_t::player_owner_array_t::~player_owner_array_t() {
    _clean_up();
}

void chk_t::player_owner_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_t::upgrade_restrictions_t::upgrade_restrictions_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
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

void chk_t::upgrade_restrictions_t::_read() {
    m__raw_maximum_level = new std::vector<std::string>();
    m__io__raw_maximum_level = new std::vector<kaitai::kstream*>();
    m_maximum_level = new std::vector<u1_array_t*>();
    const int l_maximum_level = 46;
    for (int i = 0; i < l_maximum_level; i++) {
        m__raw_maximum_level->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_maximum_level = new kaitai::kstream(m__raw_maximum_level->at(m__raw_maximum_level->size() - 1));
        m__io__raw_maximum_level->push_back(io__raw_maximum_level);
        m_maximum_level->push_back(new u1_array_t(io__raw_maximum_level, this, m__root));
    }
    m__raw_start_level = new std::vector<std::string>();
    m__io__raw_start_level = new std::vector<kaitai::kstream*>();
    m_start_level = new std::vector<u1_array_t*>();
    const int l_start_level = 46;
    for (int i = 0; i < l_start_level; i++) {
        m__raw_start_level->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_start_level = new kaitai::kstream(m__raw_start_level->at(m__raw_start_level->size() - 1));
        m__io__raw_start_level->push_back(io__raw_start_level);
        m_start_level->push_back(new u1_array_t(io__raw_start_level, this, m__root));
    }
    m_default_maximum_level = new std::vector<uint8_t>();
    const int l_default_maximum_level = 46;
    for (int i = 0; i < l_default_maximum_level; i++) {
        m_default_maximum_level->push_back(m__io->read_u1());
    }
    m_default_start_level = new std::vector<uint8_t>();
    const int l_default_start_level = 46;
    for (int i = 0; i < l_default_start_level; i++) {
        m_default_start_level->push_back(m__io->read_u1());
    }
    m__raw_upgrade_order = new std::vector<std::string>();
    m__io__raw_upgrade_order = new std::vector<kaitai::kstream*>();
    m_upgrade_order = new std::vector<u1_array_t*>();
    const int l_upgrade_order = 46;
    for (int i = 0; i < l_upgrade_order; i++) {
        m__raw_upgrade_order->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_upgrade_order = new kaitai::kstream(m__raw_upgrade_order->at(m__raw_upgrade_order->size() - 1));
        m__io__raw_upgrade_order->push_back(io__raw_upgrade_order);
        m_upgrade_order->push_back(new u1_array_t(io__raw_upgrade_order, this, m__root));
    }
}

chk_t::upgrade_restrictions_t::~upgrade_restrictions_t() {
    _clean_up();
}

void chk_t::upgrade_restrictions_t::_clean_up() {
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

chk_t::placed_units_mapmaker_properties_flags_t::placed_units_mapmaker_properties_flags_t(kaitai::kstream* p__io, chk_t::placed_units_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::placed_units_mapmaker_properties_flags_t::_read() {
    m_owner_valid = m__io->read_bits_int_le(1);
    m_hp_valid = m__io->read_bits_int_le(1);
    m_shields_valid = m__io->read_bits_int_le(1);
    m_energy_valid = m__io->read_bits_int_le(1);
    m_resource_amount_valid = m__io->read_bits_int_le(1);
    m_amount_in_hangar_valid = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(10);
}

chk_t::placed_units_mapmaker_properties_flags_t::~placed_units_mapmaker_properties_flags_t() {
    _clean_up();
}

void chk_t::placed_units_mapmaker_properties_flags_t::_clean_up() {
}

chk_t::string_data_t::string_data_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::string_data_t::_read() {
    m_strings_number = m__io->read_u2le();
    m_strings = new std::vector<string_address_t*>();
    const int l_strings = strings_number();
    for (int i = 0; i < l_strings; i++) {
        m_strings->push_back(new string_address_t(m__io, this, m__root));
    }
}

chk_t::string_data_t::~string_data_t() {
    _clean_up();
}

void chk_t::string_data_t::_clean_up() {
    if (m_strings) {
        for (std::vector<string_address_t*>::iterator it = m_strings->begin(); it != m_strings->end(); ++it) {
            delete *it;
        }
        delete m_strings; m_strings = 0;
    }
}

chk_t::staredit_sprites_array_t::staredit_sprites_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::staredit_sprites_array_t::_read() {
    m_values = new std::vector<staredit_sprites_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new staredit_sprites_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::staredit_sprites_array_t::~staredit_sprites_array_t() {
    _clean_up();
}

void chk_t::staredit_sprites_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<staredit_sprites_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::string_address_t::string_address_t(kaitai::kstream* p__io, chk_t::string_data_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::string_address_t::_read() {
    m_address = m__io->read_u2le();
}

chk_t::string_address_t::~string_address_t() {
    _clean_up();
}

void chk_t::string_address_t::_clean_up() {
    if (f_string) {
    }
}

std::string chk_t::string_address_t::string() {
    if (f_string)
        return m_string;
    std::streampos _pos = m__io->pos();
    m__io->seek(address());
    m_string = kaitai::kstream::bytes_to_str(m__io->read_bytes_term(0, false, true, true), std::string("ASCII"));
    m__io->seek(_pos);
    f_string = true;
    return m_string;
}

chk_t::locations_array_t::locations_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::locations_array_t::_read() {
    m_values = new std::vector<locations_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new locations_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::locations_array_t::~locations_array_t() {
    _clean_up();
}

void chk_t::locations_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<locations_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::locations_elevation_flags_t::locations_elevation_flags_t(kaitai::kstream* p__io, chk_t::locations_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::locations_elevation_flags_t::_read() {
    m_low_ground = m__io->read_bits_int_le(1);
    m_medium_ground = m__io->read_bits_int_le(1);
    m_high_ground = m__io->read_bits_int_le(1);
    m_low_air = m__io->read_bits_int_le(1);
    m_medium_air = m__io->read_bits_int_le(1);
    m_high_air = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(10);
}

chk_t::locations_elevation_flags_t::~locations_elevation_flags_t() {
    _clean_up();
}

void chk_t::locations_elevation_flags_t::_clean_up() {
}

chk_t::placed_units_special_properties_flags_t::placed_units_special_properties_flags_t(kaitai::kstream* p__io, chk_t::placed_units_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::placed_units_special_properties_flags_t::_read() {
    m_cloak_valid = m__io->read_bits_int_le(1);
    m_burrow_valid = m__io->read_bits_int_le(1);
    m_transit_valid = m__io->read_bits_int_le(1);
    m_hallucinated_valid = m__io->read_bits_int_le(1);
    m_invincible_valid = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(11);
}

chk_t::placed_units_special_properties_flags_t::~placed_units_special_properties_flags_t() {
    _clean_up();
}

void chk_t::placed_units_special_properties_flags_t::_clean_up() {
}

chk_t::cuwp_slots_t::cuwp_slots_t(kaitai::kstream* p__io, chk_t::cuwp_slots_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_special_properties = 0;
    m_validity = 0;
    m_unit_flags = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::cuwp_slots_t::_read() {
    m_special_properties = new cuwp_slots_special_properties_flags_t(m__io, this, m__root);
    m_validity = new cuwp_slots_validity_flags_t(m__io, this, m__root);
    m_unit_owner = m__io->read_u1();
    m_hit_points = m__io->read_u1();
    m_shield_points = m__io->read_u1();
    m_energy_points = m__io->read_u1();
    m_resource_amount = m__io->read_u4le();
    m_units_in_hangar = m__io->read_u2le();
    m_unit_flags = new cuwp_slots_unit_flags_t(m__io, this, m__root);
    m_unused = m__io->read_u4le();
}

chk_t::cuwp_slots_t::~cuwp_slots_t() {
    _clean_up();
}

void chk_t::cuwp_slots_t::_clean_up() {
    if (m_special_properties) {
        delete m_special_properties; m_special_properties = 0;
    }
    if (m_validity) {
        delete m_validity; m_validity = 0;
    }
    if (m_unit_flags) {
        delete m_unit_flags; m_unit_flags = 0;
    }
}

chk_t::tileset_t::tileset_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::tileset_t::_read() {
    m_value = static_cast<chk_t::tileset_enum_t>(m__io->read_u2le());
}

chk_t::tileset_t::~tileset_t() {
    _clean_up();
}

void chk_t::tileset_t::_clean_up() {
}

chk_t::cuwp_slots_validity_flags_t::cuwp_slots_validity_flags_t(kaitai::kstream* p__io, chk_t::cuwp_slots_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::cuwp_slots_validity_flags_t::_read() {
    m_owner_valid = m__io->read_bits_int_le(1);
    m_hp_valid = m__io->read_bits_int_le(1);
    m_shields_valid = m__io->read_bits_int_le(1);
    m_energy_valid = m__io->read_bits_int_le(1);
    m_resource_amount_valid = m__io->read_bits_int_le(1);
    m_amount_in_hangar_valid = m__io->read_bits_int_le(1);
    m_unknown = m__io->read_bits_int_le(10);
}

chk_t::cuwp_slots_validity_flags_t::~cuwp_slots_validity_flags_t() {
    _clean_up();
}

void chk_t::cuwp_slots_validity_flags_t::_clean_up() {
}

chk_t::starcraft_sprites_use_flasgs_t::starcraft_sprites_use_flasgs_t(kaitai::kstream* p__io, chk_t::starcraft_sprites_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::starcraft_sprites_use_flasgs_t::_read() {
    m_unused = m__io->read_bits_int_le(12);
    m_draw_as_sprite = m__io->read_bits_int_le(1);
    m_unused2 = m__io->read_bits_int_le(2);
    m_disabled = m__io->read_bits_int_le(1);
}

chk_t::starcraft_sprites_use_flasgs_t::~starcraft_sprites_use_flasgs_t() {
    _clean_up();
}

void chk_t::starcraft_sprites_use_flasgs_t::_clean_up() {
}

chk_t::fog_of_war_layer_t::fog_of_war_layer_t(kaitai::kstream* p__io, chk_t::fog_of_war_layer_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::fog_of_war_layer_t::_read() {
    m_player1 = m__io->read_bits_int_le(1);
    m_player2 = m__io->read_bits_int_le(1);
    m_player3 = m__io->read_bits_int_le(1);
    m_player4 = m__io->read_bits_int_le(1);
    m_player5 = m__io->read_bits_int_le(1);
    m_player6 = m__io->read_bits_int_le(1);
    m_player7 = m__io->read_bits_int_le(1);
    m_player8 = m__io->read_bits_int_le(1);
}

chk_t::fog_of_war_layer_t::~fog_of_war_layer_t() {
    _clean_up();
}

void chk_t::fog_of_war_layer_t::_clean_up() {
}

chk_t::player_unit_restrictions_t::player_unit_restrictions_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::player_unit_restrictions_t::_read() {
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

chk_t::player_unit_restrictions_t::~player_unit_restrictions_t() {
    _clean_up();
}

void chk_t::player_unit_restrictions_t::_clean_up() {
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

chk_t::u2_array_t::u2_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::u2_array_t::_read() {
    m_values = new std::vector<uint16_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(m__io->read_u2le());
            i++;
        }
    }
}

chk_t::u2_array_t::~u2_array_t() {
    _clean_up();
}

void chk_t::u2_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_t::placed_units_t::placed_units_t(kaitai::kstream* p__io, chk_t::placed_units_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::placed_units_t::_read() {
    m_instance_id = m__io->read_u4le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_unit_id = m__io->read_u2le();
    m_relation_type = m__io->read_u2le();
    m_special_properties = new placed_units_special_properties_flags_t(m__io, this, m__root);
    m_mapmaker_properties = new placed_units_mapmaker_properties_flags_t(m__io, this, m__root);
    m_player_owner = m__io->read_u1();
    m_hit_points = m__io->read_u1();
    m_shield_points = m__io->read_u1();
    m_energy_points = m__io->read_u1();
    m_resource_amount = m__io->read_u4le();
    m_units_in_hangar = m__io->read_u2le();
    m_unit_state = new placed_units_state_flags_t(m__io, this, m__root);
    m_unused = m__io->read_u4le();
    m_linked_unit = m__io->read_u4le();
}

chk_t::placed_units_t::~placed_units_t() {
    _clean_up();
}

void chk_t::placed_units_t::_clean_up() {
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

chk_t::data_type_t::data_type_t(kaitai::kstream* p__io, chk_t::chunk_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::data_type_t::_read() {
    {
        std::string on = _parent()->tag();
        if (on == std::string("TECS")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("STR ")) {
            m_content = new string_data_t(m__io, this, m__root);
        }
        else if (on == std::string("TRIG")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGS")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("SWNM")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIS")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("TECx")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("OWNR")) {
            m_content = new player_owner_array_t(m__io, this, m__root);
        }
        else if (on == std::string("WAV ")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("THG2")) {
            m_content = new starcraft_sprites_array_t(m__io, this, m__root);
        }
        else if (on == std::string("ERA ")) {
            m_content = new tileset_t(m__io, this, m__root);
        }
        else if (on == std::string("PTEC")) {
            m_content = new tech_restrictions_t(m__io, this, m__root);
        }
        else if (on == std::string("ISOM")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("VER ")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGR")) {
            m_content = new upgrade_restrictions_t(m__io, this, m__root);
        }
        else if (on == std::string("SIDE")) {
            m_content = new player_races_t(m__io, this, m__root);
        }
        else if (on == std::string("PUPx")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("IOWN")) {
            m_content = new player_owner_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIT")) {
            m_content = new placed_units_array_t(m__io, this, m__root);
        }
        else if (on == std::string("VCOD")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("FORC")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("TILE")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPUS")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("SPRP")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("IVER")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("PTEx")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MBRF")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UPRP")) {
            m_content = new cuwp_slots_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MASK")) {
            m_content = new fog_of_war_layer_array_t(m__io, this, m__root);
        }
        else if (on == std::string("UNIx")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("DD2 ")) {
            m_content = new staredit_sprites_array_t(m__io, this, m__root);
        }
        else if (on == std::string("COLR")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else if (on == std::string("DIM ")) {
            m_content = new dimension_t(m__io, this, m__root);
        }
        else if (on == std::string("IVE2")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MTXM")) {
            m_content = new u2_array_t(m__io, this, m__root);
        }
        else if (on == std::string("MRGN")) {
            m_content = new locations_array_t(m__io, this, m__root);
        }
        else if (on == std::string("PUNI")) {
            m_content = new player_unit_restrictions_t(m__io, this, m__root);
        }
        else if (on == std::string("UPGx")) {
            m_content = new u1_array_t(m__io, this, m__root);
        }
        else {
            m_content = new u1_array_t(m__io, this, m__root);
        }
    }
}

chk_t::data_type_t::~data_type_t() {
    _clean_up();
}

void chk_t::data_type_t::_clean_up() {
    if (m_content) {
        delete m_content; m_content = 0;
    }
}

chk_t::starcraft_sprites_t::starcraft_sprites_t(kaitai::kstream* p__io, chk_t::starcraft_sprites_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::starcraft_sprites_t::_read() {
    m_unit_or_sprite_number = m__io->read_u2le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_owner = m__io->read_u1();
    m_unused = m__io->read_u1();
    m_use_flags = new starcraft_sprites_use_flasgs_t(m__io, this, m__root);
}

chk_t::starcraft_sprites_t::~starcraft_sprites_t() {
    _clean_up();
}

void chk_t::starcraft_sprites_t::_clean_up() {
    if (m_use_flags) {
        delete m_use_flags; m_use_flags = 0;
    }
}

chk_t::placed_units_state_flags_t::placed_units_state_flags_t(kaitai::kstream* p__io, chk_t::placed_units_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::placed_units_state_flags_t::_read() {
    m_cloacked = m__io->read_bits_int_le(1);
    m_burrowed = m__io->read_bits_int_le(1);
    m_transit = m__io->read_bits_int_le(1);
    m_hallucinated = m__io->read_bits_int_le(1);
    m_invincible = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(11);
}

chk_t::placed_units_state_flags_t::~placed_units_state_flags_t() {
    _clean_up();
}

void chk_t::placed_units_state_flags_t::_clean_up() {
}

chk_t::player_races_t::player_races_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::player_races_t::_read() {
    m_value = new std::vector<player_races_enum_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_value->push_back(static_cast<chk_t::player_races_enum_t>(m__io->read_u1()));
            i++;
        }
    }
}

chk_t::player_races_t::~player_races_t() {
    _clean_up();
}

void chk_t::player_races_t::_clean_up() {
    if (m_value) {
        delete m_value; m_value = 0;
    }
}

chk_t::placed_units_array_t::placed_units_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::placed_units_array_t::_read() {
    m_values = new std::vector<placed_units_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new placed_units_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::placed_units_array_t::~placed_units_array_t() {
    _clean_up();
}

void chk_t::placed_units_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<placed_units_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::u1_array_t::u1_array_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::u1_array_t::_read() {
    m_values = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(m__io->read_u1());
            i++;
        }
    }
}

chk_t::u1_array_t::~u1_array_t() {
    _clean_up();
}

void chk_t::u1_array_t::_clean_up() {
    if (m_values) {
        delete m_values; m_values = 0;
    }
}

chk_t::cuwp_slots_special_properties_flags_t::cuwp_slots_special_properties_flags_t(kaitai::kstream* p__io, chk_t::cuwp_slots_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::cuwp_slots_special_properties_flags_t::_read() {
    m_cloak_valid = m__io->read_bits_int_le(1);
    m_burrowed_valid = m__io->read_bits_int_le(1);
    m_transit_valid = m__io->read_bits_int_le(1);
    m_hallucinated_valid = m__io->read_bits_int_le(1);
    m_invincible_valid = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(11);
}

chk_t::cuwp_slots_special_properties_flags_t::~cuwp_slots_special_properties_flags_t() {
    _clean_up();
}

void chk_t::cuwp_slots_special_properties_flags_t::_clean_up() {
}

chk_t::cuwp_slots_array_t::cuwp_slots_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::cuwp_slots_array_t::_read() {
    m_values = new std::vector<cuwp_slots_t*>();
    const int l_values = 64;
    for (int i = 0; i < l_values; i++) {
        m_values->push_back(new cuwp_slots_t(m__io, this, m__root));
    }
}

chk_t::cuwp_slots_array_t::~cuwp_slots_array_t() {
    _clean_up();
}

void chk_t::cuwp_slots_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<cuwp_slots_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::cuwp_slots_unit_flags_t::cuwp_slots_unit_flags_t(kaitai::kstream* p__io, chk_t::cuwp_slots_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::cuwp_slots_unit_flags_t::_read() {
    m_cloaked = m__io->read_bits_int_le(1);
    m_burrowed = m__io->read_bits_int_le(1);
    m_transit = m__io->read_bits_int_le(1);
    m_hallucinated = m__io->read_bits_int_le(1);
    m_invincible = m__io->read_bits_int_le(1);
    m_unused = m__io->read_bits_int_le(11);
}

chk_t::cuwp_slots_unit_flags_t::~cuwp_slots_unit_flags_t() {
    _clean_up();
}

void chk_t::cuwp_slots_unit_flags_t::_clean_up() {
}

chk_t::starcraft_sprites_array_t::starcraft_sprites_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::starcraft_sprites_array_t::_read() {
    m_values = new std::vector<starcraft_sprites_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new starcraft_sprites_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::starcraft_sprites_array_t::~starcraft_sprites_array_t() {
    _clean_up();
}

void chk_t::starcraft_sprites_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<starcraft_sprites_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::fog_of_war_layer_array_t::fog_of_war_layer_array_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::fog_of_war_layer_array_t::_read() {
    m_values = new std::vector<fog_of_war_layer_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_values->push_back(new fog_of_war_layer_t(m__io, this, m__root));
            i++;
        }
    }
}

chk_t::fog_of_war_layer_array_t::~fog_of_war_layer_array_t() {
    _clean_up();
}

void chk_t::fog_of_war_layer_array_t::_clean_up() {
    if (m_values) {
        for (std::vector<fog_of_war_layer_t*>::iterator it = m_values->begin(); it != m_values->end(); ++it) {
            delete *it;
        }
        delete m_values; m_values = 0;
    }
}

chk_t::staredit_sprites_t::staredit_sprites_t(kaitai::kstream* p__io, chk_t::staredit_sprites_array_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::staredit_sprites_t::_read() {
    m_doodad_number = m__io->read_u2le();
    m_coord_x = m__io->read_u2le();
    m_coord_y = m__io->read_u2le();
    m_owner = m__io->read_u1();
    m_disabled = m__io->read_u1();
}

chk_t::staredit_sprites_t::~staredit_sprites_t() {
    _clean_up();
}

void chk_t::staredit_sprites_t::_clean_up() {
}

chk_t::dimension_t::dimension_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void chk_t::dimension_t::_read() {
    m_width = m__io->read_u2le();
    m_height = m__io->read_u2le();
}

chk_t::dimension_t::~dimension_t() {
    _clean_up();
}

void chk_t::dimension_t::_clean_up() {
}

chk_t::chunk_type_t::chunk_type_t(kaitai::kstream* p__io, chk_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
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

void chk_t::chunk_type_t::_read() {
    m_tag = kaitai::kstream::bytes_to_str(m__io->read_bytes(4), std::string("ASCII"));
    m_chunk_size = m__io->read_u4le();
    m__raw_data = m__io->read_bytes(chunk_size());
    m__io__raw_data = new kaitai::kstream(m__raw_data);
    m_data = new data_type_t(m__io__raw_data, this, m__root);
}

chk_t::chunk_type_t::~chunk_type_t() {
    _clean_up();
}

void chk_t::chunk_type_t::_clean_up() {
    if (m__io__raw_data) {
        delete m__io__raw_data; m__io__raw_data = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

chk_t::tech_restrictions_t::tech_restrictions_t(kaitai::kstream* p__io, chk_t::data_type_t* p__parent, chk_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
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

void chk_t::tech_restrictions_t::_read() {
    m__raw_availability = new std::vector<std::string>();
    m__io__raw_availability = new std::vector<kaitai::kstream*>();
    m_availability = new std::vector<u1_array_t*>();
    const int l_availability = 24;
    for (int i = 0; i < l_availability; i++) {
        m__raw_availability->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_availability = new kaitai::kstream(m__raw_availability->at(m__raw_availability->size() - 1));
        m__io__raw_availability->push_back(io__raw_availability);
        m_availability->push_back(new u1_array_t(io__raw_availability, this, m__root));
    }
    m__raw_alreeady_researched = new std::vector<std::string>();
    m__io__raw_alreeady_researched = new std::vector<kaitai::kstream*>();
    m_alreeady_researched = new std::vector<u1_array_t*>();
    const int l_alreeady_researched = 24;
    for (int i = 0; i < l_alreeady_researched; i++) {
        m__raw_alreeady_researched->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_alreeady_researched = new kaitai::kstream(m__raw_alreeady_researched->at(m__raw_alreeady_researched->size() - 1));
        m__io__raw_alreeady_researched->push_back(io__raw_alreeady_researched);
        m_alreeady_researched->push_back(new u1_array_t(io__raw_alreeady_researched, this, m__root));
    }
    m_default_availability = new std::vector<uint8_t>();
    const int l_default_availability = 24;
    for (int i = 0; i < l_default_availability; i++) {
        m_default_availability->push_back(m__io->read_u1());
    }
    m_default_already_research = new std::vector<uint8_t>();
    const int l_default_already_research = 24;
    for (int i = 0; i < l_default_already_research; i++) {
        m_default_already_research->push_back(m__io->read_u1());
    }
    m__raw_use_global_defaults = new std::vector<std::string>();
    m__io__raw_use_global_defaults = new std::vector<kaitai::kstream*>();
    m_use_global_defaults = new std::vector<u1_array_t*>();
    const int l_use_global_defaults = 24;
    for (int i = 0; i < l_use_global_defaults; i++) {
        m__raw_use_global_defaults->push_back(m__io->read_bytes(12));
        kaitai::kstream* io__raw_use_global_defaults = new kaitai::kstream(m__raw_use_global_defaults->at(m__raw_use_global_defaults->size() - 1));
        m__io__raw_use_global_defaults->push_back(io__raw_use_global_defaults);
        m_use_global_defaults->push_back(new u1_array_t(io__raw_use_global_defaults, this, m__root));
    }
}

chk_t::tech_restrictions_t::~tech_restrictions_t() {
    _clean_up();
}

void chk_t::tech_restrictions_t::_clean_up() {
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
