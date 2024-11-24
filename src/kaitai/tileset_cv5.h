#ifndef TILESET_CV5_H_
#define TILESET_CV5_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class tileset_cv5_t : public kaitai::kstruct {

public:
    class group_t;
    class terrain_flags_type_t;

    enum terrain_enum_t {
        TERRAIN_ENUM_UNPLACEABLE = 0,
        TERRAIN_ENUM_DOODAD = 1,
        TERRAIN_ENUM_BASIC = 2
    };

    tileset_cv5_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, tileset_cv5_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~tileset_cv5_t();

    class group_t : public kaitai::kstruct {

    public:

        group_t(kaitai::kstream* p__io, tileset_cv5_t* p__parent = 0, tileset_cv5_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~group_t();

    private:
        uint16_t m_terrain_type;
        terrain_flags_type_t* m_terrain_flags;
        uint16_t m_unknown1;
        uint16_t m_unknown2;
        uint16_t m_unknown3;
        uint16_t m_unknown4;
        uint16_t m_unknown5;
        uint16_t m_unknown6;
        uint16_t m_unknown7;
        uint16_t m_unknown8;
        std::vector<uint16_t>* m_megatile_references;
        tileset_cv5_t* m__root;
        tileset_cv5_t* m__parent;

    public:
        uint16_t terrain_type() const { return m_terrain_type; }
        terrain_flags_type_t* terrain_flags() const { return m_terrain_flags; }
        uint16_t unknown1() const { return m_unknown1; }
        uint16_t unknown2() const { return m_unknown2; }
        uint16_t unknown3() const { return m_unknown3; }
        uint16_t unknown4() const { return m_unknown4; }
        uint16_t unknown5() const { return m_unknown5; }
        uint16_t unknown6() const { return m_unknown6; }
        uint16_t unknown7() const { return m_unknown7; }
        uint16_t unknown8() const { return m_unknown8; }
        std::vector<uint16_t>* megatile_references() const { return m_megatile_references; }
        tileset_cv5_t* _root() const { return m__root; }
        tileset_cv5_t* _parent() const { return m__parent; }
    };

    class terrain_flags_type_t : public kaitai::kstruct {

    public:

        terrain_flags_type_t(kaitai::kstream* p__io, tileset_cv5_t::group_t* p__parent = 0, tileset_cv5_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~terrain_flags_type_t();

    private:
        bool f_walkable;
        int32_t m_walkable;

    public:
        int32_t walkable();

    private:
        bool f_mid_ground;
        int32_t m_mid_ground;

    public:
        int32_t mid_ground();

    private:
        bool f_high_ground;
        int32_t m_high_ground;

    public:
        int32_t high_ground();

    private:
        bool f_unbuildable;
        int32_t m_unbuildable;

    public:
        int32_t unbuildable();

    private:
        bool f_cliff_edge;
        int32_t m_cliff_edge;

    public:
        int32_t cliff_edge();

    private:
        bool f_unknown3;
        int32_t m_unknown3;

    public:
        int32_t unknown3();

    private:
        bool f_unknown2;
        int32_t m_unknown2;

    public:
        int32_t unknown2();

    private:
        bool f_temporary_creep;
        int32_t m_temporary_creep;

    public:
        int32_t temporary_creep();

    private:
        bool f_blocks_view;
        int32_t m_blocks_view;

    public:
        int32_t blocks_view();

    private:
        bool f_unwalkable;
        int32_t m_unwalkable;

    public:
        int32_t unwalkable();

    private:
        bool f_has_doodad_cover;
        int32_t m_has_doodad_cover;

    public:
        int32_t has_doodad_cover();

    private:
        bool f_receding_creep;
        int32_t m_receding_creep;

    public:
        int32_t receding_creep();

    private:
        bool f_unknown1;
        int32_t m_unknown1;

    public:
        int32_t unknown1();

    private:
        bool f_occupied;
        int32_t m_occupied;

    public:
        int32_t occupied();

    private:
        bool f_allow_beacons_startlocations_placeable;
        int32_t m_allow_beacons_startlocations_placeable;

    public:
        int32_t allow_beacons_startlocations_placeable();

    private:
        bool f_creep;
        int32_t m_creep;

    public:
        int32_t creep();

    private:
        uint16_t m_flags_raw;
        tileset_cv5_t* m__root;
        tileset_cv5_t::group_t* m__parent;

    public:
        uint16_t flags_raw() const { return m_flags_raw; }
        tileset_cv5_t* _root() const { return m__root; }
        tileset_cv5_t::group_t* _parent() const { return m__parent; }
    };

private:
    std::vector<group_t*>* m_elements;
    tileset_cv5_t* m__root;
    kaitai::kstruct* m__parent;

public:

    /**
     * This file defines the various tile groups that are referenced by the TILE/MTXM 
     * sections of the CHK (0x7FF0 for the group index, 0x000F for the tile index).
     */
    std::vector<group_t*>* elements() const { return m_elements; }
    tileset_cv5_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // TILESET_CV5_H_
