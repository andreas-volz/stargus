/*
 * IScriptConverter.h
 *
 *      Author: Andreas Volz
 */

#ifndef ISCRIPTCONVERTER_H
#define ISCRIPTCONVERTER_H

/* project */
#include "opcode_types.h"

/* system */
#include <string>
#include <map>
#include <vector>

class IScriptConverter
{
public:
  IScriptConverter();
  virtual ~IScriptConverter();

  void convertSCPEHeaderMap(const std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map);
  void convertSCPEHeader(uint16_t iscript_id, const std::vector<uint16_t> &iscript_scpe_header);

  void convertOpcodeVector(const std::vector<Opcode> &opcode_vector);
  const std::string convertOpcode(const Opcode &opcode);

  /**
   * @param clear_names sets the flag if the generated out should have resolved clear names (helpful for debugging or human reading).
   *        The default case for machine usage should be to not have clear names.
   */
  void setHumanReadable(bool human_readable);
  bool getHumanReadable();

private:
  bool m_human_readable;
};

#endif /* ISCRIPTCONVERTER_H */
