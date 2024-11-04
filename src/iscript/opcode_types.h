/*
 * opcode_types.h
 *
 *      Author: Andreas Volz
 */

#ifndef OPCODE_TYPES_H
#define OPCODE_TYPES_H

/* system */
#include <cstdint>
#include <variant>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

enum opcode_t
{
    PLAYFRAM = 0x00,            ///< <frame#>: # displays a particular frame, adjusted for direction.
    PLAYFRAMTILE = 0x01,        ///< <frame#>: # displays a particular frame dependent on tileset.
    SETHORPOS = 0x02,           ///< <x>: # sets the current horizontal offset of the current image overlay.
    SETVERTPOS = 0x03,          ///< <y>: # sets the vertical position of an image overlay.
    SETPOS = 0x04,              ///< <x> <y>: # sets the current horizontal and vertical position of the current image overlay.
    WAIT = 0x05,                ///< <#ticks>: # pauses script execution for a specific number of ticks.
    WAITRAND = 0x06,            ///< <#ticks1> <#ticks2>: # pauses script execution for a random number of ticks given two possible wait times.
    GOTO = 0x07,                ///< labelname>: # unconditionally jumps to a specific code block.
    IMGOL = 0x08,               ///< <image#> <x> <y>: # displays an active image overlay at an animation level higher than the current image overlay at a specified offset position.
    IMGUL = 0x09,               ///< <image#> <x> <y>: # displays an active image overlay at an animation level lower than the current image overlay at a specified offset position.
    IMGOLORIG = 0x0A,           ///< <image#>: # displays an active image overlay at an animation level higher than the current image overlay at the relative origin offset position.
    SWITCHUL = 0x0B,            ///< <image#>: # only for powerups. Hypothesised to replace the image overlay that was first created by the current image overlay.
    UNKNOWN_0C = 0x0C,          ///< no parameters: # unknown.
    IMGOLUSELO = 0x0D,          ///< <image#> <x> <y>: # displays an active image overlay at an animation level higher than the current image overlay, using a LO* file to determine the offset position.
    IMGULUSELO = 0x0E,          ///< <image#> <x> <y>: # displays an active image overlay at an animation level lower than the current image overlay, using a LO* file to determine the offset position.
    SPROL = 0x0F,               ///< <sprite#> <x> <y>: # spawns a sprite one animation level above the current image overlay at a specific offset position.
    HIGHSPROL = 0x10,           ///< <sprite#> <x> <y>: # spawns a sprite at the highest animation level at a specific offset position.
    LOWSPRUL = 0x11,            ///< <sprite#> <x> <y>: # spawns a sprite at the lowest animation level at a specific offset position.
    UFLUNSTABLE = 0x12,         ///< <flingy#: # creates an flingy with restrictions; supposedly crashes in most cases.
    SPRULUSELO = 0x13,          ///< <sprite#> <x> <y>: # spawns a sprite one animation level below the current image overlay at a specific offset position. The new sprite inherits the direction of the current sprite. Requires LO* file for unknown reason.
    SPRUL = 0x14,               ///< <sprite#> <x> <y>: # spawns a sprite one animation level below the current image overlay at a specific offset position. The new sprite inherits the direction of the current sprite.
    SPROLUSELO = 0x15,          ///< sprite#> <overlay#>: # spawns a sprite one animation level above the current image overlay, using a specified LO* file for the offset position information. The new sprite inherits the direction of the current sprite.
    END = 0x16,                 ///< no parameters: # destroys the current active image overlay, also removing the current sprite if the image overlay is the last in one in the current sprite.
    SETFLIPSTATE = 0x17,        ///< <flipstate>: # sets flip state of the current image overlay.
    PLAYSND = 0x18,             ///< <sound#>: # plays a sound.
    PLAYSNDRAND = 0x19,         ///< <#sounds> <sound#> <...>: # plays a random sound from a list.
    PLAYSNDBTWN = 0x1A,         ///< <firstsound#> <lastsound#>: # plays a random sound between two inclusive sfxdata.dat entry IDs.
    DOMISSILEDMG = 0x1B,        ///< no parameters: # causes the damage of a weapon flingy to be applied according to its weapons.dat entry.
    ATTACKMELEE = 0x1C,         ///< <#sounds> <sound#> <...>: # applies damage to target without creating a flingy and plays a sound.
    FOLLOWMAINGRAPHIC = 0x1D,   ///< no parameters: # causes the current image overlay to display the same frame as the parent image overlay.
    RANDCONDJMP = 0x1E,         ///< <randchance#> <labelname>: # random jump, chance of performing jump depends on the parameter.
    TURNCCWISE = 0x1F,          ///< <turnamount>: # turns the flingy counterclockwise by a particular amount.
    TURNCWISE = 0x20,           ///< <turnamount>: # turns the flingy clockwise by a particular amount.
    TURN1CWISE = 0x21,          ///< no parameters: # turns the flingy clockwise by one direction unit.
    TURNRAND = 0x22,            ///< <turnamount>: # turns the flingy a specified amount in a random direction, with a heavy bias towards turning clockwise.
    SETSPAWNFRAME = 0x23,       ///< <direction>: # in specific situations, performs a natural rotation to the given direction.
    SIGORDER = 0x24,            ///< <signal#>: # allows the current unit's order to proceed if it has paused for an animation to be completed.
    ATTACKWITH = 0x25,          ///< <ground = 1, air = 2>: # attack with either the ground or air weapon depending on a parameter.
    ATTACK = 0x26,              ///< no parameters: # attack with either the ground or air weapon depending on target.
    CASTSPELL = 0x27,           ///< no parameters: # identifies when a spell should be cast in a spellcasting animation. The spell is determined by the unit's current order.
    USEWEAPON = 0x28,           ///< <weapon#>: # makes the unit use a specific weapons.dat ID on its target.
    MOVE = 0x29,                ///< <movedistance>: # sets the unit to move forward a certain number of pixels at the end of the current tick.
    GOTOREPEATATTK = 0x2A,      ///< no parameters: # signals to StarCraft that after this point, when the unit's cooldown time is over, the repeat attack animation can be called.
    ENGFRAME = 0x2B,            ///< <frame#>: # plays a particular frame, often used in engine glow animations.
    ENGSET = 0x2C,              ///< <frameset#>: # plays a particular frame set, often used in engine glow animations.
    UNKNOWN_2D = 0x2D,          ///< no parameters: # hypothesised to hide the current image overlay until the next animation.
    NOBRKCODESTART = 0x2E,      ///< no parameters: # holds the processing of player orders until a nobrkcodeend is encountered.
    NOBRKCODEEND = 0x2F,        ///< no parameters: # allows the processing of player orders after a nobrkcodestart instruction.
    IGNOREREST = 0x30,          ///< no parameters: # conceptually, this causes the script to stop until the next animation is called.
    ATTKSHIFTPROJ = 0x31,       ///< <distance>: # creates the weapon flingy at a particular distance in front of the unit.
    TMPRMGRAPHICSTART = 0x32,   ///< no parameters: # sets the current image overlay state to hidden.
    TMPRMGRAPHICEND = 0x33,     ///< no parameters: # sets the current image overlay state to visible.
    SETFLDIRECT = 0x34,         ///< <direction>: # sets the current direction of the flingy (e.g. used for death animation).
    CALL = 0x35,                ///< <labelname>: # calls a code block.
    RETURN = 0x36,              ///< no parameters: # returns from call.
    SETFLSPEED = 0x37,          ///< <speed>: # sets the flingy.dat speed of the current flingy.
    CREATEGASOVERLAYS = 0x38,   ///< <gasoverlay#>: # creates gas image overlays at offsets specified by LO* files.
    PWRUPCONDJMP = 0x39,        ///< <labelname>: # jumps to a code block if the current unit is a powerup and it is currently picked up.
    TRGTRANGECONDJMP = 0x3A,    ///< <distance> <labelname>: # jumps to a block depending on the distance to the target.
    TRGTARCCONDJMP = 0x3B,      ///< <angle1> <angle2> <labelname>: # jumps to a block depending on the current angle of the target.
    CURDIRECTCONDJMP = 0x3C,    ///< <angle1> <angle2> <labelname>: # only for units. Jump to a code block if the current sprite is facing a particular direction.
    IMGULNEXTID = 0x3D,         ///< <x> <y>: # displays an active image overlay at the shadow animation level at a specified offset position. The image overlay that will be displayed is the one that is after the current image overlay in images.dat.
    UNKNOWN_3E = 0x3E,          ///< no parameters: # unknown.
    LIFTOFFCONDJMP = 0x3F,      ///< <labelname>: # jumps to a code block when the current unit that is a building that is lifted off.
    WARPOVERLAY = 0x40,         ///< <frame#>: # hypothesised to display the current image overlay's frame clipped to the outline of the parent image overlay.
    ORDERDONE = 0x41,           ///< <signal#>: # most likely used with orders that continually repeat, like the Medic's healing and the Valkyrie's afterburners (which no longer exist), to clear the sigorder flag to stop the order.
    GRDSPROL = 0x42,            ///< <sprite#> <x> <y>: # spawns a sprite one animation level above the current image overlay at a specific offset position, but only if the current sprite is over ground-passable terrain.
    UNKNOWN_43 = 0x43,          ///< no parameters: # unknown.
    DOGRDDAMAGE = 0x44          ///< no parameters: # applies damage like domissiledmg when on ground-unit-passable terrain.
};

bool is_little_endian();
uint8_t to_host_endian(uint8_t val);
uint16_t to_host_endian(uint16_t val);
uint32_t to_host_endian(uint32_t val);

template <typename T> class generic_type
{
public:
  void read(std::shared_ptr<std::istream> stream)
  {
    stream->read(reinterpret_cast<char*>(&m_value), sizeof(m_value));
    m_value = to_host_endian(m_value);
  }

  T value() const
  {
    return m_value;
  }

  void value(T value)
  {
    m_value = value;
  }

protected:
  T m_value;
};


// Define empty type for instructions with no arguments
struct empty_type {};

// Define u1, u2, and pos types
struct u1_type : public generic_type<uint8_t>
{
};

struct u2_type : public generic_type<uint16_t>
{
};

struct u4_type : public generic_type<uint32_t>
{
};

struct scpe_header_type {
  u4_type magic;        // 4-byte magic number
  u1_type animation_type; // 1-byte unsigned integer
  u1_type padding[3];    // 3 bytes of padding
};

struct entree_offset_type
{
  u2_type iscript_id; // 2-byte unsigned integer
  u2_type offset;      // 2-byte unsigned integer
};

struct pos_type { // oh, this is potential conflicting with istream, rename or take care at least
  u1_type x;
  u1_type y;
};

// waitrand_type struct
struct waitrand_type {
  u1_type ticks1;
  u1_type ticks2;
};

// imgl_type struct
struct imgl_type {
  u2_type image;
  pos_type pos;
};

// sprl_type struct
struct sprl_type {
  u2_type sprite;
  pos_type pos;
};

// sprov_type struct
struct sprov_type {
  u2_type sprite;
  u1_type overlay;
};

// playsndbtwn_type struct
struct playsndbtwn_type {
  u2_type firstsound;
  u2_type lastsound;
};

// playsounds_type struct
struct playsounds_type {
  u1_type num_sound;
  std::vector<u2_type> sounds;
};

// randcondjmp_type struct
struct randcondjmp_type {
  u1_type randchance;
  u2_type offset;
};

// trgtrangecondjmp_type struct
struct trgtrangecondjmp_type {
  u2_type distance;
  u2_type offset;
};

// trgcondjmp_type struct
struct trgcondjmp_type {
  u2_type angle1;
  u2_type angle2;
  u2_type offset;
};


// Structure to represent an opcode
struct Opcode {
  u1_type code;
  std::variant<u1_type, u2_type, pos_type, waitrand_type, imgl_type, sprl_type, sprov_type,
               playsndbtwn_type, playsounds_type, randcondjmp_type, trgtrangecondjmp_type,
               trgcondjmp_type, empty_type> args;
};



pos_type read_pos_type(std::shared_ptr<std::istream> stream);
u4_type read_u4_type(std::shared_ptr<std::istream> stream);
u2_type read_u2_type(std::shared_ptr<std::istream> stream);
u1_type read_u1_type(std::shared_ptr<std::istream> stream);

waitrand_type read_waitrand_type(std::shared_ptr<std::istream> stream);
imgl_type read_imgl_type(std::shared_ptr<std::istream> stream);
sprl_type read_sprl_type(std::shared_ptr<std::istream> stream);
sprov_type read_sprov_type(std::shared_ptr<std::istream> stream);
playsndbtwn_type read_playsndbtwn_type(std::shared_ptr<std::istream> stream);
playsounds_type read_playsounds_type(std::shared_ptr<std::istream> stream);
randcondjmp_type read_randcondjmp_type(std::shared_ptr<std::istream> stream);
trgtrangecondjmp_type read_trgtrangecondjmp_type(std::shared_ptr<std::istream> stream);
trgcondjmp_type read_trgcondjmp_type(std::shared_ptr<std::istream> stream);

entree_offset_type read_entree_offset_type(std::shared_ptr<std::istream> stream);
scpe_header_type read_scpe_header_type(std::shared_ptr<std::istream> stream);

#endif /* OPCODE_TYPES_H */
