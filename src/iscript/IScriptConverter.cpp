/*
 * IScriptExporter.cpp
 *
 *      Author: Andreas Volz
 */

/* project */
#include "IScriptConverter.h"
#include "IScript.h"
#include "opcode_types.h"

/* system */
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

IScriptConverter::IScriptConverter() :
  m_human_readable(false)
{

}

IScriptConverter::~IScriptConverter()
{

}

const std::string ENDL = "\n";

const std::vector<std::string> OPCODE_COMMAND_MAPPING = {
  "playfram",
  "playframtile",
  "sethorpos",
  "setvertpos",
  "setpos",
  "wait",
  "waitrand",
  "goto",
  "imgol",
  "imgul",
  "imgolorig",
  "switchul",
  "unknown_0c",
  "imgoluselo",
  "imguluselo",
  "sprol",
  "highsprol",
  "lowsprul",
  "uflunstable",
  "spruluselo",
  "sprul",
  "sproluselo",
  "end",
  "setflipstate",
  "playsnd",
  "playsndrand",
  "playsndbtwn",
  "domissiledmg",
  "attackmelee",
  "followmaingraphic",
  "randcondjmp",
  "turnccwise",
  "turncwise",
  "turn1cwise",
  "turnrand",
  "setspawnframe",
  "sigorder",
  "attackwith",
  "attack",
  "castspell",
  "useweapon",
  "move",
  "gotorepeatattk",
  "engframe",
  "engset",
  "unknown_2d",
  "nobrkcodestart",
  "nobrkcodeend",
  "ignorerest",
  "attkshiftproj",
  "tmprmgraphicstart",
  "tmprmgraphicend",
  "setfldirect",
  "call",
  "return",
  "setflspeed",
  "creategasoverlays",
  "pwrupcondjmp",
  "trgtrangecondjmp",
  "trgtarccondjmp",
  "curdirectcondjmp",
  "imgulnextid",
  "unknown_3e",
  "liftoffcondjmp",
  "warpoverlay",
  "orderdone",
  "grdsprol",
  "unknown_43",
  "dogrddamage",
};

const std::vector<std::string> IScriptConverter::ISCRIPT_ANIMATIONTYPE_MAPPING = {
  "Init",
  "Death",
  "GndAttkInit",
  "AirAttkInit",
  "Unused1",
  "GndAttkRpt",
  "AirAttkRpt",
  "CastSpell",
  "GndAttkToIdle",
  "AirAttkToIdle",
  "Unused2",
  "Walking",
  "WalkingToIdle",
  "SpecialState1",
  "SpecialState2",
  "AlmostBuilt",
  "Built",
  "Landing",
  "LiftOff",
  "IsWorking",
  "WorkingToIdle",
  "WarpIn",
  "Unused3",
  "StarEditInit",
  "Disable",
  "Burrow",
  "UnBurrow",
  "Enable"
};

const std::string IScriptConverter::convertOpcodeVector(const std::vector<Opcode> &opcode_vector)
{
  string opcode_string;

   opcode_string += ".opcodestart" + ENDL;

   unsigned int i = 0;
   for(Opcode opcode : opcode_vector)
   {
     if(m_human_readable)
     {
       // for debugging and human readable print the rewritten index address before the opcode
       opcode_string += to_string(i) + ": ";
     }

     opcode_string += convertOpcode(opcode);
     opcode_string += ENDL;

     i++;
   }

   opcode_string += ".opcodeend" + ENDL;

   return opcode_string;
}

const std::string IScriptConverter::convertOpcode(const Opcode &opcode)
{
  string opcode_string;

  if(m_human_readable)
  {
    string code_name = OPCODE_COMMAND_MAPPING[opcode.code.value()];
    opcode_string += code_name;
  }
  else
  {
    opcode_string += to_string(opcode.code.value());
  }
  opcode_string += " ";

  switch (opcode.code.value())
  {
    case opcode_t::ATTACK:
    case opcode_t::ATTKSHIFTPROJ:
    case opcode_t::CASTSPELL:
    case opcode_t::END:
    case opcode_t::DOGRDDAMAGE:
    case opcode_t::DOMISSILEDMG:
    case opcode_t::FOLLOWMAINGRAPHIC:
    case opcode_t::GOTOREPEATATTK:
    case opcode_t::IGNOREREST:
    case opcode_t::NOBRKCODEEND:
    case opcode_t::NOBRKCODESTART:
    case opcode_t::RETURN:
    case opcode_t::TMPRMGRAPHICEND:
    case opcode_t::TMPRMGRAPHICSTART:
    case opcode_t::TURN1CWISE:
    case opcode_t::UNKNOWN_0C:
    case opcode_t::UNKNOWN_2D:
    case opcode_t::UNKNOWN_3E:
    case opcode_t::UNKNOWN_43:
    {
      // empty - print no parameter
    }
    break;

    case opcode_t::ATTACKWITH:
    case opcode_t::CREATEGASOVERLAYS:
    case opcode_t::ENGFRAME:
    case opcode_t::ENGSET:
    case opcode_t::MOVE:
    case opcode_t::ORDERDONE:
    case opcode_t::SETFLDIRECT:
    case opcode_t::SETFLIPSTATE:
    case opcode_t::SETHORPOS:
    case opcode_t::SETVERTPOS:
    case opcode_t::TURNCCWISE:
    case opcode_t::TURNCWISE:
    case opcode_t::TURNRAND:
    case opcode_t::SETSPAWNFRAME:
    case opcode_t::SIGORDER:
    case opcode_t::USEWEAPON:
    case opcode_t::WAIT:
    {
      // u1_type
      variant args = opcode.args;
      u1_type native_args = get<u1_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.value()));
    }
    break;

    case opcode_t::CALL:
    case opcode_t::IMGOLORIG:
    case opcode_t::SWITCHUL:
    case opcode_t::GOTO:
    case opcode_t::LIFTOFFCONDJMP:
    case opcode_t::PLAYFRAM:
    case opcode_t::PLAYFRAMTILE:
    case opcode_t::PLAYSND:
    case opcode_t::PWRUPCONDJMP:
    case opcode_t::SETFLSPEED:
    case opcode_t::UFLUNSTABLE:
    case opcode_t::WARPOVERLAY:
    {
      // u2_type
      variant args = opcode.args;
      u2_type native_args = get<u2_type>(args);
      opcode_string += to_string(native_args.value());
    }
    break;

    case opcode_t::IMGULNEXTID:
    case opcode_t::SETPOS:
    {
      // pos_type
      variant args = opcode.args;
      pos_type native_args = get<pos_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.x.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.y.value()));
    }
    break;

    case opcode_t::WAITRAND:
    {
      // waitrand_type
      variant args = opcode.args;
      waitrand_type native_args = get<waitrand_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.ticks1.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.ticks2.value()));

    }
    break;

    case opcode_t::IMGOL:
    case opcode_t::IMGUL:
    case opcode_t::IMGOLUSELO:
    case opcode_t::IMGULUSELO:
    {
      // imgl_type
      variant args = opcode.args;
      imgl_type native_args = get<imgl_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.image.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.pos.x.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.pos.y.value())) + " ";
    }
    break;

    case opcode_t::GRDSPROL:
    case opcode_t::SPROL:
    case opcode_t::HIGHSPROL:
    case opcode_t::LOWSPRUL:
    case opcode_t::SPRULUSELO:
    case opcode_t::SPRUL:
    {
      // sprl_type
      variant args = opcode.args;
      sprl_type native_args = get<sprl_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.sprite.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.pos.x.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.pos.y.value())) + " ";
    }
    break;

    case opcode_t::SPROLUSELO:
    {
      // sprov_type
      variant args = opcode.args;
      sprov_type native_args = get<sprov_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.sprite.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.overlay.value()));
    }
    break;

    case opcode_t::ATTACKMELEE:
    case opcode_t::PLAYSNDRAND:
    {
      // playsounds_type
      variant args = opcode.args;
      playsounds_type native_args = get<playsounds_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.num_sound.value())) + " ";
      for(auto sound : native_args.sounds)
      {
        opcode_string += to_string(static_cast<unsigned int>(sound.value())) + " ";
      }
    }
    break;

    case opcode_t::PLAYSNDBTWN:
    {
      // playsndbtwn_type
      variant args = opcode.args;
      playsndbtwn_type native_args = get<playsndbtwn_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.firstsound.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.lastsound.value()));
    }
    break;

    case opcode_t::RANDCONDJMP:
    {
      // randcondjmp_type
      variant args = opcode.args;
      randcondjmp_type native_args = get<randcondjmp_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.randchance.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.offset.value()));
    }
    break;

    case opcode_t::TRGTRANGECONDJMP:
    {
      // trgtrangecondjmp_type
      variant args = opcode.args;
      trgtrangecondjmp_type native_args = get<trgtrangecondjmp_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.distance.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.offset.value()));
    }
    break;

    case opcode_t::TRGTARCCONDJMP:
    case opcode_t::CURDIRECTCONDJMP:
    {
      // trgcondjmp_type
      variant args = opcode.args;
      trgcondjmp_type native_args = get<trgcondjmp_type>(args);
      opcode_string += to_string(static_cast<unsigned int>(native_args.angle1.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.angle2.value())) + " "
                     + to_string(static_cast<unsigned int>(native_args.offset.value()));
    }
    break;

    default:
      std::cerr << "Unknown opcode: " << hex << static_cast<int>(opcode.code.value()) << std::endl;
      break;
  }

  return opcode_string;
}

const std::string IScriptConverter::convertSCPEHeaderMap(const std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map)
{
  string header_string;

  for(auto iscript_scpe_header_it : iscript_scpe_header_map)
  {
    uint16_t iscript_id = iscript_scpe_header_it.first;
    std::vector<uint16_t> opcode_offsets = iscript_scpe_header_it.second;

    header_string += convertSCPEHeader(iscript_id, opcode_offsets);
  }
  return header_string;
}

const std::string IScriptConverter::convertSCPEHeader(uint16_t iscript_id, const std::vector<uint16_t> &iscript_scpe_header)
{
  string header_string;

  header_string += ".headerstart" + ENDL;

  header_string += "iscript: " + to_string(iscript_id) + ENDL;

  unsigned int i = 0;

  if(m_human_readable)
  {
    for(auto opcode_offset : iscript_scpe_header)
    {
      string animationtype_name = ISCRIPT_ANIMATIONTYPE_MAPPING[i];

      header_string += animationtype_name + " ";
      header_string += to_string(opcode_offset) + ENDL;

      i++;
    }
  }
  else
  {
    header_string += "animations:";
    for(auto opcode_offset : iscript_scpe_header)
    {
      header_string += " " + to_string(opcode_offset);
    }
    header_string += ENDL;
  }

  header_string += ".headerend" + ENDL + ENDL;

  return header_string;
}

void IScriptConverter::setHumanReadable(bool human_readable)
{
  m_human_readable = human_readable;
}

bool IScriptConverter::getHumanReadable()
{
  return m_human_readable;
}

void IScriptConverter::saveConverted(const std::string &outfile, const std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map, const std::vector<Opcode> &opcode_vector)
{
  try
  {
    std::ofstream file(outfile);

    string output_string = convertSCPEHeaderMap(iscript_scpe_header_map);
    output_string += convertOpcodeVector(opcode_vector);

    file << output_string;
  }
  catch (std::ofstream::failure &e)
  {
    std::cerr << e.what() << std::endl;
  }
}


