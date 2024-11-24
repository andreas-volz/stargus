meta:
  id: tileset_cv5
  endian: le
  bit-endian: le
  
seq:
  - id: elements
    type: group
    repeat: eos
    doc: |
      This file defines the various tile groups that are referenced by the TILE/MTXM 
      sections of the CHK (0x7FF0 for the group index, 0x000F for the tile index).

types:
  group:
    seq:
      - id: terrain_type
        type: u2

      - id: terrain_flags
        type: terrain_flags_type
        
      - id: unknown1
        type: u2
        
      - id: unknown2
        type: u2
        
      - id: unknown3
        type: u2
        
      - id: unknown4
        type: u2
        
      - id: unknown5
        type: u2
        
      - id: unknown6
        type: u2
        
      - id: unknown7
        type: u2
        
      - id: unknown8
        type: u2
        
      - id: megatile_references
        type: u2
        repeat: expr
        repeat-expr: 16
        
  terrain_flags_type:
    seq:
      - id: flags_raw
        type: u2
        
    instances:
      walkable:
        value: flags_raw & 0x0001
        
      unknown1:
        value: flags_raw & 0x0002
        
      unwalkable:
        value: flags_raw & 0x0004
        
      unknown2:
        value: flags_raw & 0x0008
        
      has_doodad_cover:
        value: flags_raw & 0x0010
        
      unknown3:
        value: flags_raw & 0x0020
        
      creep:
        value: flags_raw & 0x0040
        
      unbuildable:
        value: flags_raw & 0x0080
        
      blocks_view:
        value: flags_raw & 0x0100
        
      mid_ground:
        value: flags_raw & 0x0200
        
      high_ground:
        value: flags_raw & 0x0400
        
      occupied:
        value: flags_raw & 0x0800
        
      receding_creep:
        value: flags_raw & 0x1000
        
      cliff_edge:
        value: flags_raw & 0x2000
        
      temporary_creep:
        value: flags_raw & 0x4000
        
      allow_beacons_startlocations_placeable:
        value: flags_raw & 0x8000
        
enums:
  terrain_enum:
    0: unplaceable
    1: doodad
    2: basic