/*
 * opcode_list_type.cpp
 *
 *      Author: Andreas Volz
 */

#include "opcode_list_type.h"
#include "iscript_bin.h"
#include "StringUtil.h"

#include <iostream>

using namespace std;

opcode_list_type_t::opcode_list_type_t(kaitai::kstruct* p__parent, iscript_bin_t* p__root, kaitai::kstream* p__io) :
  kaitai::kstruct(p__io),
  m__root(p__root),
  m__parent(p__parent),
  m_pos(m__io->pos()),
  m_opcode_list(nullptr)
{

}

opcode_list_type_t::~opcode_list_type_t()
{
  _clean_up();
}

std::vector<kaitai::kstruct*>* opcode_list_type_t::read_list(std::unordered_set<uint16_t> scpe_offset_table)
{
  if (m_opcode_list)
  {
    return m_opcode_list;
  }
  else
  {
    m_opcode_list = new std::vector<kaitai::kstruct*>();
  }

  m_scpe_offset_table = scpe_offset_table;

  std::streampos _pos = m__io->pos();
  m__io->seek(m_pos);
  try
  {
    _read();
  }
  catch(...)
  {
    _clean_up();
    throw;
  }
  m__io->seek(_pos);

  return m_opcode_list;
}

void opcode_list_type_t::_read()
{
  int scpe_opcode_offset = 0;
  bool end_criteria = false;
  do
  {
    auto io_size = m__io->size();
    //cout << endl << "before read::code: " << hex << io_size << endl;

    iscript_bin_t::opcode_type_t *opcode = new iscript_bin_t::opcode_type_t(m__io, m__parent, m__root);
    //cout << "_read::code: " << hex << opcode->code() << endl;


    /*if(opcode->code()==iscript_bin_t::OPCODE_PLAYFRAM)
    {
      cout << "playframe: ";
      iscript_bin_t::u2_type_t *casted_args = static_cast<iscript_bin_t::u2_type_t *>(opcode->args());
      cout << casted_args->value() << endl;
      cout << endl;
      if(casted_args->value() == 0xa0)
      {
        cout << "hit breakboint" << endl;
      }
    }*/

    // set next offset position
    scpe_opcode_offset = m__io->pos();

    /*
     * calculate the stream end position and substract the size of 0xFF 0xFF 0x00 0x00 from it
     * this allows below to stop parsing before the file ends
     */
    int end_position = io_size - scpe_opcode_offset - 2;
    /*cout << "end_position: " << end_position << endl;

    cout << "scpe_opcode_offset: " << scpe_opcode_offset << endl;
    cout << "m_scpe_offset_table.size(): " << m_scpe_offset_table.size() << endl;

    cout << "offset: ";
    for(auto offset : m_scpe_offset_table)
    {
      cout << offset << " ";
    }*/

    auto iscript_id_found = m_scpe_offset_table.find(scpe_opcode_offset);
    if(iscript_id_found != m_scpe_offset_table.end() || end_position == 0)
    {
      end_criteria = true;
      //cout << endl << "end_criteria=true" << endl;
    }

    /*
     * TODO: hmmm, is there a better way than stopping at these codes?
     */
    // for now stop when special opcode is found
    if(opcode->code() == iscript_bin_t::opcode_t::OPCODE_GOTO)
    {
      end_criteria = true;
    }
    if(opcode->code() == iscript_bin_t::opcode_t::OPCODE_END)
    {
      end_criteria = true;
    }
    if(opcode->code() == iscript_bin_t::opcode_t::OPCODE_RETURN)
    {
      end_criteria = true;
    }

    m_opcode_list->push_back(opcode);
  }
  while(!end_criteria);
}

void opcode_list_type_t::_clean_up()
{
  // crash at end -> memory bug?
  delete m_opcode_list;
}
