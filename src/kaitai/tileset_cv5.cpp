// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "tileset_cv5.h"

tileset_cv5_t::tileset_cv5_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, tileset_cv5_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_elements = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tileset_cv5_t::_read() {
    m_elements = new std::vector<group_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_elements->push_back(new group_t(m__io, this, m__root));
            i++;
        }
    }
}

tileset_cv5_t::~tileset_cv5_t() {
    _clean_up();
}

void tileset_cv5_t::_clean_up() {
    if (m_elements) {
        for (std::vector<group_t*>::iterator it = m_elements->begin(); it != m_elements->end(); ++it) {
            delete *it;
        }
        delete m_elements; m_elements = 0;
    }
}

tileset_cv5_t::group_t::group_t(kaitai::kstream* p__io, tileset_cv5_t* p__parent, tileset_cv5_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_terrain_flags = 0;
    m_megatile_references = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tileset_cv5_t::group_t::_read() {
    m_terrain_type = m__io->read_u2le();
    m_terrain_flags = new terrain_flags_type_t(m__io, this, m__root);
    m_unknown1 = m__io->read_u2le();
    m_unknown2 = m__io->read_u2le();
    m_unknown3 = m__io->read_u2le();
    m_unknown4 = m__io->read_u2le();
    m_unknown5 = m__io->read_u2le();
    m_unknown6 = m__io->read_u2le();
    m_unknown7 = m__io->read_u2le();
    m_unknown8 = m__io->read_u2le();
    m_megatile_references = new std::vector<uint16_t>();
    const int l_megatile_references = 16;
    for (int i = 0; i < l_megatile_references; i++) {
        m_megatile_references->push_back(m__io->read_u2le());
    }
}

tileset_cv5_t::group_t::~group_t() {
    _clean_up();
}

void tileset_cv5_t::group_t::_clean_up() {
    if (m_terrain_flags) {
        delete m_terrain_flags; m_terrain_flags = 0;
    }
    if (m_megatile_references) {
        delete m_megatile_references; m_megatile_references = 0;
    }
}

tileset_cv5_t::terrain_flags_type_t::terrain_flags_type_t(kaitai::kstream* p__io, tileset_cv5_t::group_t* p__parent, tileset_cv5_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_walkable = false;
    f_mid_ground = false;
    f_high_ground = false;
    f_unbuildable = false;
    f_cliff_edge = false;
    f_unknown3 = false;
    f_unknown2 = false;
    f_temporary_creep = false;
    f_blocks_view = false;
    f_unwalkable = false;
    f_has_doodad_cover = false;
    f_receding_creep = false;
    f_unknown1 = false;
    f_occupied = false;
    f_allow_beacons_startlocations_placeable = false;
    f_creep = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void tileset_cv5_t::terrain_flags_type_t::_read() {
    m_flags_raw = m__io->read_u2le();
}

tileset_cv5_t::terrain_flags_type_t::~terrain_flags_type_t() {
    _clean_up();
}

void tileset_cv5_t::terrain_flags_type_t::_clean_up() {
}

int32_t tileset_cv5_t::terrain_flags_type_t::walkable() {
    if (f_walkable)
        return m_walkable;
    m_walkable = (flags_raw() & 1);
    f_walkable = true;
    return m_walkable;
}

int32_t tileset_cv5_t::terrain_flags_type_t::mid_ground() {
    if (f_mid_ground)
        return m_mid_ground;
    m_mid_ground = (flags_raw() & 512);
    f_mid_ground = true;
    return m_mid_ground;
}

int32_t tileset_cv5_t::terrain_flags_type_t::high_ground() {
    if (f_high_ground)
        return m_high_ground;
    m_high_ground = (flags_raw() & 1024);
    f_high_ground = true;
    return m_high_ground;
}

int32_t tileset_cv5_t::terrain_flags_type_t::unbuildable() {
    if (f_unbuildable)
        return m_unbuildable;
    m_unbuildable = (flags_raw() & 128);
    f_unbuildable = true;
    return m_unbuildable;
}

int32_t tileset_cv5_t::terrain_flags_type_t::cliff_edge() {
    if (f_cliff_edge)
        return m_cliff_edge;
    m_cliff_edge = (flags_raw() & 8192);
    f_cliff_edge = true;
    return m_cliff_edge;
}

int32_t tileset_cv5_t::terrain_flags_type_t::unknown3() {
    if (f_unknown3)
        return m_unknown3;
    m_unknown3 = (flags_raw() & 32);
    f_unknown3 = true;
    return m_unknown3;
}

int32_t tileset_cv5_t::terrain_flags_type_t::unknown2() {
    if (f_unknown2)
        return m_unknown2;
    m_unknown2 = (flags_raw() & 8);
    f_unknown2 = true;
    return m_unknown2;
}

int32_t tileset_cv5_t::terrain_flags_type_t::temporary_creep() {
    if (f_temporary_creep)
        return m_temporary_creep;
    m_temporary_creep = (flags_raw() & 16384);
    f_temporary_creep = true;
    return m_temporary_creep;
}

int32_t tileset_cv5_t::terrain_flags_type_t::blocks_view() {
    if (f_blocks_view)
        return m_blocks_view;
    m_blocks_view = (flags_raw() & 256);
    f_blocks_view = true;
    return m_blocks_view;
}

int32_t tileset_cv5_t::terrain_flags_type_t::unwalkable() {
    if (f_unwalkable)
        return m_unwalkable;
    m_unwalkable = (flags_raw() & 4);
    f_unwalkable = true;
    return m_unwalkable;
}

int32_t tileset_cv5_t::terrain_flags_type_t::has_doodad_cover() {
    if (f_has_doodad_cover)
        return m_has_doodad_cover;
    m_has_doodad_cover = (flags_raw() & 16);
    f_has_doodad_cover = true;
    return m_has_doodad_cover;
}

int32_t tileset_cv5_t::terrain_flags_type_t::receding_creep() {
    if (f_receding_creep)
        return m_receding_creep;
    m_receding_creep = (flags_raw() & 4096);
    f_receding_creep = true;
    return m_receding_creep;
}

int32_t tileset_cv5_t::terrain_flags_type_t::unknown1() {
    if (f_unknown1)
        return m_unknown1;
    m_unknown1 = (flags_raw() & 2);
    f_unknown1 = true;
    return m_unknown1;
}

int32_t tileset_cv5_t::terrain_flags_type_t::occupied() {
    if (f_occupied)
        return m_occupied;
    m_occupied = (flags_raw() & 2048);
    f_occupied = true;
    return m_occupied;
}

int32_t tileset_cv5_t::terrain_flags_type_t::allow_beacons_startlocations_placeable() {
    if (f_allow_beacons_startlocations_placeable)
        return m_allow_beacons_startlocations_placeable;
    m_allow_beacons_startlocations_placeable = (flags_raw() & 32768);
    f_allow_beacons_startlocations_placeable = true;
    return m_allow_beacons_startlocations_placeable;
}

int32_t tileset_cv5_t::terrain_flags_type_t::creep() {
    if (f_creep)
        return m_creep;
    m_creep = (flags_raw() & 64);
    f_creep = true;
    return m_creep;
}
