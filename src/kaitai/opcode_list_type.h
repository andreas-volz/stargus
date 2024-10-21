/*
 * opcode_list_type.h
 *
 *      Author: Andreas Volz
 */

#ifndef OPCODE_LIST_TYPE_H
#define OPCODE_LIST_TYPE_H

#include "kaitaistruct.h"

// system
#include <set>
#include <vector>
#include <map>

  // forward declarations
class iscript_bin_t;

class  opcode_list_type_t : public kaitai::kstruct
{
public:
  opcode_list_type_t(kaitai::kstruct* p__parent, iscript_bin_t* p__root, kaitai::kstream* p__io);
  ~opcode_list_type_t();

  std::vector<kaitai::kstruct*>* read_list(std::set<uint16_t> scpe_offset_table);
  std::vector<uint16_t> get_opcode_offsets();

private:
  void _read();
  void _clean_up();

  std::set<uint16_t> m_scpe_offset_table;
  iscript_bin_t* m__root;
  kaitai::kstruct* m__parent;
  std::streampos m_pos;

  std::vector<kaitai::kstruct*>* m_opcode_list;
  std::vector<uint16_t> m_opcode_offsets;
};

#endif /* OPCODE_LIST_TYPE_H */
