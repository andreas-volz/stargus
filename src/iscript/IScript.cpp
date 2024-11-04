/*
 * IScript.cpp
 *
 *      Author: Andreas Volz
 */

/* project */
#include "IScript.h"
#include "Hurricane.h"

/* system */
#include <algorithm>

using namespace std;

IScript::IScript(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile) :
  Converter(hurricane),
  m_stream(hurricane->extractStream(arcfile)),
  m_version(IScriptVersion::STARCRAFT)
{
}


IScript::~IScript()
{
}

/* the iscript.bin has its header table at the start of the iscript,
   so we need to jump over this part in all version. In Starcraft jump
   to this position from behind. In Broodwar read the first offset address
   and jump to the entree headers table.
 */
const uint16_t ORIG_STARCRAFT_HEADER_TABLE_SIZE = 0x558;

uint32_t entree_table_start = 0;

const std::map<unsigned int, unsigned int> ANIMATION_TYPE_MAPPING = {
    {0, 2},
    {1, 2},
    {2, 4},
    {12, 14},
    {13, 14},
    {14, 16},
    {15, 16},
    {20, 22},
    {21, 22},
    {23, 24},
    {24, 26},
    {26, 28},
    {27, 28},
    {28, 28},
    {29, 28}
};

void IScript::parseOpcodeBlock(uint16_t start_offset)
{
  m_stream->seekg(start_offset);

  bool processing = true;
  while (processing)
  {
    Opcode opcode;
    opcode.code = read_u1_type(m_stream);

    /*
     * add the current file offset to a index list to later reference the jump offsets to this point.
     */
    uint16_t offset = m_stream->tellg();
    offset -= sizeof(uint8_t); // subtract sizeof(uint8_t) as opcode is yet read.

    // Based on the opcode, read the corresponding args
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
        opcode.args = empty_type{};
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
        opcode.args = read_u1_type(m_stream);
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
        opcode.args = read_u2_type(m_stream);
      }
      break;

      case opcode_t::IMGULNEXTID:
      case opcode_t::SETPOS:
      {
        opcode.args = read_pos_type(m_stream);
      }
      break;

      case opcode_t::WAITRAND:
      {
        opcode.args = read_waitrand_type(m_stream);
      }
      break;

      case opcode_t::IMGOL:
      case opcode_t::IMGUL:
      case opcode_t::IMGOLUSELO:
      case opcode_t::IMGULUSELO:
      {
        opcode.args = read_imgl_type(m_stream);
      }
      break;

      case opcode_t::GRDSPROL:
      case opcode_t::SPROL:
      case opcode_t::HIGHSPROL:
      case opcode_t::LOWSPRUL:
      case opcode_t::SPRULUSELO:
      case opcode_t::SPRUL:
      {
        opcode.args = read_sprl_type(m_stream);
      }
      break;

      case opcode_t::SPROLUSELO:
      {
        opcode.args = read_sprov_type(m_stream);
      }
      break;

      case opcode_t::ATTACKMELEE:
      case opcode_t::PLAYSNDRAND:
      {
        opcode.args = read_playsounds_type(m_stream);
      }
      break;

      case opcode_t::PLAYSNDBTWN:
      {
        opcode.args = read_playsndbtwn_type(m_stream);
      }
      break;

      case opcode_t::RANDCONDJMP:
      {
        opcode.args = read_randcondjmp_type(m_stream);
      }
      break;

      case opcode_t::TRGTRANGECONDJMP:
      {

        opcode.args = read_trgtrangecondjmp_type(m_stream);
      }
      break;

      case opcode_t::TRGTARCCONDJMP:
      case opcode_t::CURDIRECTCONDJMP:
      {
        opcode.args = read_trgcondjmp_type(m_stream);
      }
      break;

      default:
        std::cerr << "Unknown opcode: " << hex << static_cast<int>(opcode.code.value()) << std::endl;
        break;
    }

    /*
     * some special handling to continue counting all jump offsets
     */
    switch(opcode.code.value())
    {
      case opcode_t::GOTO:
      case opcode_t::CALL:
      case opcode_t::PWRUPCONDJMP:
      case opcode_t::LIFTOFFCONDJMP:
      {
        variant args = opcode.args;
        u2_type native_args = get<u2_type>(args);
        m_jump_offsets.insert(native_args.value());
      }
      break;
      case opcode_t::RANDCONDJMP:
      {
        variant args = opcode.args;
        randcondjmp_type native_args = get<randcondjmp_type>(args);
        m_jump_offsets.insert(native_args.offset.value());
      }
      break;
      case opcode_t::TRGTRANGECONDJMP:
      {
        variant args = opcode.args;
        trgtrangecondjmp_type native_args = get<trgtrangecondjmp_type>(args);
        m_jump_offsets.insert(native_args.offset.value());
      }
      break;
      case opcode_t::TRGTARCCONDJMP:
      case opcode_t::CURDIRECTCONDJMP:
      {
        variant args = opcode.args;
        trgcondjmp_type native_args = get<trgcondjmp_type>(args);
        m_jump_offsets.insert(native_args.offset.value());
      }
      break;
      default:
        break;
    }

    m_opcode_map.insert(pair(offset, opcode));

    switch(opcode.code.value())
    {
      case opcode_t::GOTO:
      case opcode_t::END:
        processing = false;
        break;
      default:
        break;
    }
  }

}


void IScript::parseSCPEHeader()
{
  std::vector<uint16_t> scpe_opcode_offset_list;

  uint16_t address = m_stream->tellg();
  uint16_t iscript_id = m_offset_iscript_mapping[address];

  scpe_header_type scpe_header = read_scpe_header_type(m_stream);

  // Check if the magic number is correct (little-endian)
  if (scpe_header.magic.value() != 0x45504353) // Magic number: 'S' 'C' 'P' 'E' in little-endian
  {
    throw std::runtime_error("Invalid block magic number!");
  }

  //std::cout << "Animation Type: " << dec << static_cast<int>(scpe_header.animation_type.value()) << endl;

  unsigned int scpe_header_animation_blocks = 0;
  if (auto search = ANIMATION_TYPE_MAPPING.find(scpe_header.animation_type.value()); search != ANIMATION_TYPE_MAPPING.end())
  {
    scpe_header_animation_blocks = search->second;
  }

  for (unsigned int i = 0; i < scpe_header_animation_blocks; i++)
  {
    u2_type scpe_opcode_offset;
    scpe_opcode_offset = read_u2_type(m_stream);
    scpe_opcode_offset_list.push_back(scpe_opcode_offset.value());

    // add all direct jump offsets into the countainer set to generate jump labels later
    m_global_offsets.insert(scpe_opcode_offset.value());
  }

  m_iscript_scpe_header_map.insert(pair(iscript_id, scpe_opcode_offset_list));
}

void IScript::detectDataVersion()
{
  u2_type header_table_pointer = read_u2_type(m_stream);
  u2_type version_tag = read_u2_type(m_stream);

  if(version_tag.value() == 0x0000)
  {
    m_version = IScriptVersion::BROODWAR;
  }
  else
  {
    m_version = IScriptVersion::STARCRAFT;
  }

  if(m_version == IScriptVersion::STARCRAFT)
  {
    // seek to the end to get the file length
    m_stream->seekg(0, ios_base::end);
    auto length = m_stream->tellg();

    entree_table_start = length - std::streamoff(ORIG_STARCRAFT_HEADER_TABLE_SIZE);
  }
  else if(m_version == IScriptVersion::BROODWAR)
  {
    entree_table_start = header_table_pointer.value();
  }

  /*
   * from here start the parsing of the entree table at the end of iscript.bin
   */
  m_stream->seekg(entree_table_start);
}

void IScript::parseEntreeOffsetList()
{
  // Read entries until the sentinel value 0xFFFF 0x0000 is found
  while (true)
  {
    entree_offset_type entry;
    entry = read_entree_offset_type(m_stream);

    // Check for the end of the entries
    if (entry.iscript_id.value() == 0xFFFF && entry.offset.value() == 0x0000)
    {
      break; // Stop reading when the sentinel value is found
    }

    // fill hashmap for accessing offset by the iscript
    //m_iscript_offset_mapping.insert(pair<uint16_t, uint16_t>(entry.iscript_id.value(), entry.offset.value()));

    // fill hashmap for accessing iscript by the offset
    m_offset_iscript_mapping.insert(pair<uint16_t, uint16_t>(entry.offset.value(), entry.iscript_id.value()));

    // Store the entry if valid
    m_entree_offsets.push_back(entry);
  }
}

void IScript::rewriteSCPEHeaderOffsets()
{
  for(auto &m_iscript_scpe_header_it : m_iscript_scpe_header_map)
  {
    std::vector<uint16_t> &iscript_scpe_header = m_iscript_scpe_header_it.second;
    for(uint16_t &opcode_offset : iscript_scpe_header)
    {
      auto it = m_opcode_offset_index_map.find(opcode_offset);
      if(it != m_opcode_offset_index_map.end())
      {
        opcode_offset = it->second;
      }
    }
  }
}

void IScript::rewriteOpcodeOffsets()
{
  for(Opcode &opcode: m_opcode_vector)
  {
    switch(opcode.code.value())
    {
      case opcode_t::GOTO:
      case opcode_t::CALL:
      case opcode_t::PWRUPCONDJMP:
      case opcode_t::LIFTOFFCONDJMP:
      {
        variant<u1_type, u2_type, pos_type, waitrand_type, imgl_type, sprl_type, sprov_type,
        playsndbtwn_type, playsounds_type, randcondjmp_type, trgtrangecondjmp_type,
        trgcondjmp_type, empty_type>& args = opcode.args;
        u2_type& native_args = get<u2_type>(args);
        auto it = m_opcode_offset_index_map.find(native_args.value());
        if(it != m_opcode_offset_index_map.end())
        {
          native_args.value(it->second);
        }
      }
      break;
      case opcode_t::RANDCONDJMP:
      {
        variant<u1_type, u2_type, pos_type, waitrand_type, imgl_type, sprl_type, sprov_type,
        playsndbtwn_type, playsounds_type, randcondjmp_type, trgtrangecondjmp_type,
        trgcondjmp_type, empty_type>& args = opcode.args;
        randcondjmp_type& native_args = get<randcondjmp_type>(args);
        auto it = m_opcode_offset_index_map.find(native_args.offset.value());
        if(it != m_opcode_offset_index_map.end())
        {
          native_args.offset.value(it->second);
        }
      }
      break;
      case opcode_t::TRGTRANGECONDJMP:
      {
        variant<u1_type, u2_type, pos_type, waitrand_type, imgl_type, sprl_type, sprov_type,
        playsndbtwn_type, playsounds_type, randcondjmp_type, trgtrangecondjmp_type,
        trgcondjmp_type, empty_type>& args = opcode.args;
        trgtrangecondjmp_type& native_args = get<trgtrangecondjmp_type>(args);
        auto it = m_opcode_offset_index_map.find(native_args.offset.value());
        if(it != m_opcode_offset_index_map.end())
        {
          native_args.offset.value(it->second);
        }
      }
      break;
      case opcode_t::TRGTARCCONDJMP:
      case opcode_t::CURDIRECTCONDJMP:
      {
        variant<u1_type, u2_type, pos_type, waitrand_type, imgl_type, sprl_type, sprov_type,
        playsndbtwn_type, playsounds_type, randcondjmp_type, trgtrangecondjmp_type,
        trgcondjmp_type, empty_type>& args = opcode.args;
        trgcondjmp_type& native_args = get<trgcondjmp_type>(args);
        auto it = m_opcode_offset_index_map.find(native_args.offset.value());
        if(it != m_opcode_offset_index_map.end())
        {
          native_args.offset.value(it->second);
        }
      }
      break;
      default:
        break;
    }
  }
}

void IScript::parseIScript()
{
  detectDataVersion();

  parseEntreeOffsetList();

  for(auto entree_offset : m_entree_offsets)
  {
    m_stream->seekg(entree_offset.offset.value());

    parseSCPEHeader();
  }

  // read all global offsets that are direct called from the animation headers
  for(auto start_offset : m_global_offsets)
  {
    if(start_offset != 0)
    {
      parseOpcodeBlock(start_offset);
    }
  }

  // remove the global offsets from the jump offset container, because they're yet read
  for (const auto& offset : m_global_offsets)
  {
    m_jump_offsets.erase(offset);
  }

  // read all jump offsets which are called from goto/call/... and not read before
  for(auto start_offset : m_jump_offsets)
  {
    parseOpcodeBlock(start_offset);
  }

  /*
   * insert all Opcodes into a vector and build a offset map for later offset to index rewrite
   */
  unsigned int i = 0;
  for(auto opcode_it : m_opcode_map)
  {
    uint16_t offset = opcode_it.first;
    Opcode opcode = opcode_it.second;
    m_opcode_vector.push_back(opcode);
    m_opcode_offset_index_map.insert(pair(offset, i));
    i++;
  }

  rewriteSCPEHeaderOffsets();
  rewriteOpcodeOffsets();
}

IScript::IScriptVersion IScript::getDataVersion()
{
  return m_version;
}

std::vector<Opcode> &IScript::getOpcodeVector()
{
  return m_opcode_vector;
}

std::map<uint16_t, std::vector<uint16_t>> &IScript::getIScriptSCPEHeaderMap()
{
  return m_iscript_scpe_header_map;
}

/**
 * @param consume if false seek back after magic is found
 */
/*bool IScript::checkMagic(uint32_t magic, bool consume)
{
  u4_type read_magic;
  read_magic.read(m_stream);

  // seek back after read
  if(!consume)
  {
    std::streampos currentPos = m_stream->tellg();
    m_stream->seekg(currentPos - std::streamoff(sizeof(read_magic.value())));
  }

  if (read_magic.value() == magic)
  {
    return true;
  }
  return false;
}

bool IScript::checkEndMagic()
{
  uint32_t magic = 0x0000FFFF;
  return checkMagic(magic, false);
}

bool IScript::checkSCPEMagic()
{
  uint32_t magic = 0x45504353; // Magic number: 'S' 'C' 'P' 'E' in little-endian
  return checkMagic(magic, false);
}*/
