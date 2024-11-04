/*
 * opcode_types.cpp
 *
 *      Author: Andreas Volz
 */

#include "opcode_types.h"

using namespace std;

// Helper function to detect system endianness
bool is_little_endian()
{
    uint16_t test = 0x0001;
    return *reinterpret_cast<uint8_t*>(&test) == 0x01;
}

uint8_t to_host_endian(uint8_t val)
{
  return val;
}

// Helper function to convert from little-endian to host-endian
uint16_t to_host_endian(uint16_t val)
{
  if (!is_little_endian())
  {
      // If the system is big-endian, swap the byte order
      return (val >> 8) | (val << 8);
  }
  return val; // Already little-endian, no need to convert
}

// Helper function to convert from little-endian to host-endian for uint32_t
uint32_t to_host_endian(uint32_t val)
{
  if (!is_little_endian())
  {
      // If the system is big-endian, swap the byte order
      return ((val >> 24) & 0x000000FF) |
             ((val >> 8)  & 0x0000FF00) |
             ((val << 8)  & 0x00FF0000) |
             ((val << 24) & 0xFF000000);
  }
  return val; // Already little-endian, no need to convert
}

scpe_header_type read_scpe_header_type(std::shared_ptr<std::istream> stream)
{
  scpe_header_type scpe_header;
  scpe_header.magic = read_u4_type(stream);
  scpe_header.animation_type = read_u1_type(stream);
  scpe_header.padding[0] = read_u1_type(stream);
  scpe_header.padding[1] = read_u1_type(stream);
  scpe_header.padding[2] = read_u1_type(stream);
  return scpe_header;
}

entree_offset_type read_entree_offset_type(std::shared_ptr<std::istream> stream)
{
  entree_offset_type entree_offset;
  entree_offset.iscript_id = read_u2_type(stream);
  entree_offset.offset = read_u2_type(stream);
  return entree_offset;
}

pos_type read_pos_type(std::shared_ptr<std::istream> stream)
{
  pos_type pos;
  pos.x.read(stream);
  pos.y.read(stream);
  return pos;
}

u4_type read_u4_type(std::shared_ptr<std::istream> stream)
{
  u4_type u4;
  u4.read(stream);
  return u4;
}

u2_type read_u2_type(std::shared_ptr<std::istream> stream)
{
  u2_type u2;
  u2.read(stream);
  return u2;
}

u1_type read_u1_type(std::shared_ptr<std::istream> stream)
{
  u1_type u1;
  u1.read(stream);
  return u1;
}

waitrand_type read_waitrand_type(std::shared_ptr<std::istream> stream)
{
  waitrand_type waitrand;
  waitrand.ticks1 = read_u1_type(stream);
  waitrand.ticks2 = read_u1_type(stream);
  return waitrand;
}

imgl_type read_imgl_type(std::shared_ptr<std::istream> stream)
{
  imgl_type imgl;
  imgl.image = read_u2_type(stream);
  imgl.pos = read_pos_type(stream);
  return imgl;
}

sprl_type read_sprl_type(std::shared_ptr<std::istream> stream)
{
  sprl_type sprl;
  sprl.sprite = read_u2_type(stream);
  sprl.pos = read_pos_type(stream);
  return sprl;
}

sprov_type read_sprov_type(std::shared_ptr<std::istream> stream)
{
  sprov_type sprov;
  sprov.sprite = read_u2_type(stream);
  sprov.overlay = read_u1_type(stream);
  return sprov;
}

playsndbtwn_type read_playsndbtwn_type(std::shared_ptr<std::istream> stream)
{
  playsndbtwn_type playsndbtwn;
  playsndbtwn.firstsound = read_u2_type(stream);
  playsndbtwn.lastsound = read_u2_type(stream);
  return playsndbtwn;
}

playsounds_type read_playsounds_type(std::shared_ptr<std::istream> stream)
{
  playsounds_type playsounds;
  playsounds.num_sound = read_u1_type(stream);
  playsounds.sounds.resize(playsounds.num_sound.value());
  for (auto& sound : playsounds.sounds)
  {
    sound = read_u2_type(stream);
  }
  return playsounds;
}

randcondjmp_type read_randcondjmp_type(std::shared_ptr<std::istream> stream)
{
  randcondjmp_type randcondjmp;
  randcondjmp.randchance = read_u1_type(stream);
  randcondjmp.offset = read_u2_type(stream);
  return randcondjmp;
}

trgtrangecondjmp_type read_trgtrangecondjmp_type(std::shared_ptr<std::istream> stream)
{
  trgtrangecondjmp_type trgtrangecondjmp;
  trgtrangecondjmp.distance = read_u2_type(stream);
  trgtrangecondjmp.offset = read_u2_type(stream);
  return trgtrangecondjmp;
}

trgcondjmp_type read_trgcondjmp_type(std::shared_ptr<std::istream> stream)
{
  trgcondjmp_type trgcondjmp;
  trgcondjmp.angle1 = read_u2_type(stream);
  trgcondjmp.angle2 = read_u2_type(stream);
  trgcondjmp.offset = read_u2_type(stream);
  return trgcondjmp;
}
