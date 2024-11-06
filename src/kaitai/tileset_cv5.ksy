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

      - id: ground
        type: ground_nibbles
        
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
        
  ground_nibbles:
    seq:
      - id: buildable
        type: b4
        
      - id: ground_type
        type: b4
        
      - id: unknown1
        type: b4
        
      - id: ground_height
        type: b4
        
enums:
  terrain_enum:
    0: unplaceable
    1: doodad
    2: basic