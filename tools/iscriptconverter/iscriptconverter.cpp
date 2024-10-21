#include <string>
#include <stdexcept>

using namespace std;

/* project */
#include "iscript/IScript.h"
#include "iscript/IScriptConverter.h"

int main()
{
  try
  {
    // STARCRAFT
    std::string filename = "/home/andreas/Games/DOS/Starcraft/Original_Backup/starcraft_install.exe_MPQ_stardat.mpq/scripts/iscript.bin";

    // BRODOWAR
    //std::string filename = "/home/andreas/Games/DOS/Starcraft/Original_Backup/broodwar_install.exe_MPQ_broodat.mpq/scripts/iscript.bin";

    IScript iscript(filename);
    iscript.parseIScript();

    std::vector<Opcode> &opcode_vector = iscript.getOpcodeVector();
    std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map = iscript.getIScriptSCPEHeaderMap();

    IScriptConverter iscript_converter;
    iscript_converter.setHumanReadable(false);
    iscript_converter.convertSCPEHeaderMap(iscript_scpe_header_map);
    iscript_converter.convertOpcodeVector(opcode_vector);

  } catch (const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << '\n';
  }
  return 0;
}
