/*
 * IScript.h
 *
 *      Author: Andreas Volz
 */

#ifndef ISCRIPT_H
#define ISCRIPT_H

/* project */
#include "opcode_types.h"
#include "Converter.h"

/* systen */
#include <map>
#include <set>


class IScript : public Converter
{
public:
  IScript(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile);
  virtual ~IScript();

  /**
   * Function to read and parse the iscript.bin file
   */
  void parseIScript();

  enum IScriptVersion
  {
    STARCRAFT,
    BROODWAR
  };

  enum AnimationType
  {
    Init, // Initial animation
    Death, // Death animation
    GndAttkInit, // Initial ground attack animation
    AirAttkInit, // Initial air attack animation
    Unused1, // Unknown/unused animation
    GndAttkRpt, // Repeated ground attack animation
    AirAttkRpt, // Repeated air attack animation
    CastSpell, // Spell casting animation
    GndAttkToIdle, // Animation for returning to an idle state after a ground attack
    AirAttkToIdle, // Animation for returning to an idle state after an air attack
    Unused2, // Unknown/unused animation
    Walking, // Walking/moving animation
    WalkingToIdle, // Animation for returning to an idle state after walking/moving
    SpecialState1, // Some sort of category of special animations, in some cases an in-transit animation, sometimes used for special orders, sometimes having to do with the animation when something finishes morphing, or the first stage of a construction animation
    SpecialState2, // Some sort of category of special animations, in some cases a burrowed animation, sometimes used for special orders, sometimes having to do with the animation when canceling a morph, or the second stage of a construction animation
    AlmostBuilt, // An animation for one part of the building process
    Built, // Final animation before finishing being built
    Landing, // Landing animation
    LiftOff, // Lifting off animation
    IsWorking, // Animation for when researching an upgrade/technology or training/building units and some other animations for some sort of work being done
    WorkingToIdle, // Animation for returning to an idle state after IsWorking
    WarpIn, // Warping in animation
    Unused3, // Unknown/unused animation
    StarEditInit, // Previously called InitTurret, this is actually an alternate initial animation for StarEdit a.k.a. the Campaign Editor
    Disable, // Animation for becoming disabled, either through the "Set Doodad State" trigger action or by not being in the psi field of any pylons
    Burrow, // Burrowing animation
    UnBurrow, // Unburrowing animation
    Enable // Animation for becoming enabled, either through the "Set Doodad State" trigger action or by being in the psi field of a pylon
  };

  /**
   * @return either STARCRAFT or BROODWAR data version
   */
  IScriptVersion getDataVersion();

  /**
   * @return a vector reference with the global list of all Opcodes. Use getIScriptSCPEHeaderMap() to get the starting point for the needed Animation
   */
  std::vector<Opcode> &getOpcodeVector();

  std::map<uint16_t, std::vector<uint16_t>> &getIScriptSCPEHeaderMap();

private:
  /**
   * detect either STARCRAFT or BROODWAR data version and calculate some other parser starting position based on it
   */
  void detectDataVersion();

  /**
   * parse the SCPE header with information about animation type and global start offsets to Opcode blocks
   */
  void parseSCPEHeader();

  /**
   * parse one block of Opcodes until a jump code is found (e.g. godo/end/...)
   */
  void parseOpcodeBlock(uint16_t start_offset);

  /**
   * parse the entree offsets which contain the offset to all SCPE headers and the iscript id reference
   */
  void parseEntreeOffsetList();

  /**
   * rewrite all SCPE header reference offsets to absolute index values from new m_opcode_vector
   */
  void rewriteSCPEHeaderOffsets();

  /**
   * rewrite all Opcode reference offsets to absolute index values from new m_opcode_vector
   */
  void rewriteOpcodeOffsets();

  /**
   * some magic check functions which were helpful while development. Remove them later if not needed!
   */
  /*bool checkSCPEMagic();
  bool checkEndMagic();
  bool checkMagic(uint32_t magic, bool consume = false);*/


  //std::ifstream m_stream;
  std::shared_ptr<std::istream> m_stream;
  enum IScriptVersion m_version;

  std::vector<entree_offset_type> m_entree_offsets;

  //std::map<uint16_t, uint16_t> m_iscript_offset_mapping;
  std::map<uint16_t, uint16_t> m_offset_iscript_mapping;

  std::set<uint16_t> m_global_offsets;
  std::set<uint16_t> m_jump_offsets;

  std::map<uint16_t, unsigned int> m_opcode_offset_index_map;
  std::map<uint16_t, Opcode> m_opcode_map;

  std::vector<Opcode> m_opcode_vector;
  std::map<uint16_t, std::vector<uint16_t>> m_iscript_scpe_header_map;
};

#endif /* ISCRIPT_H */
