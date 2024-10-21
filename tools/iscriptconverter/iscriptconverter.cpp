/* project */
#include "FileUtil.h"
#include "iscript/IScript.h"
#include "iscript/IScriptConverter.h"
#include "optparser.h"
#include "Logger.h"

/* system */
#include <string>
#include <stdexcept>

using namespace std;

static Logger logger("startool.iscriptconverter");

bool human_readable = false;
string iscript_bin;
string iscript_txt;

/** option parser **/
struct Arg: public option::Arg
{
  static void printError(const char *msg1, const option::Option &opt, const char *msg2)
  {
    fprintf(stderr, "%s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
  }

  static option::ArgStatus Unknown(const option::Option &option, bool msg)
  {
    if (msg)
      printError("Unknown option '", option, "'\n");

    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Required(const option::Option &option, bool msg)
  {
    if (option.arg != 0)
      return option::ARG_OK;

    if (msg)
      printError("Option '", option, "' requires an argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus NonEmpty(const option::Option &option, bool msg)
  {
    if (option.arg != 0 && option.arg[0] != 0)
      return option::ARG_OK;

    if (msg)
      printError("Option '", option, "' requires a non-empty argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Numeric(const option::Option &option, bool msg)
  {
    char *endptr = 0;
    if (option.arg != 0 && strtol(option.arg, &endptr, 10))
    {
    };
    if (endptr != option.arg && *endptr == 0)
      return option::ARG_OK;

    if (msg)
      printError("Option '", option, "' requires a numeric argument\n");
    return option::ARG_ILLEGAL;
  }
};

enum optionIndex
{
  UNKNOWN, HELP, HUMANREADABLE
};
const option::Descriptor usage[] =
{
  {
    UNKNOWN, 0, "", "", option::Arg::None, "USAGE: iscriptconverter [options] /path/to/iscript.bin /path/to/iscript.txt\n\n"
    "Options:"
  },
  { HELP, 0, "h", "help", option::Arg::None, "  --help, -h  \t\tPrint usage and exit" },
  { HUMANREADABLE, 0, "r", "human-readable", Arg::None, "  --human-readable, -r  \t\tGenerate output with human readable names (e.g. for debugging or analysis)" },
  {
    UNKNOWN, 0, "", "", option::Arg::None,
    "\niscript.bin \t\tThe binary input iscript.bin format with all animation Opcodes.\n"
    "\niscript.txt \t\tThe converted output iscript.txt with easy to parse numbers or (for debugging) a human readable version.\n"

  },
  { 0, 0, 0, 0, 0, 0 }
};

int parseOptions(int argc, const char **argv)
{
  argc -= (argc > 0);
  argv += (argc > 0); // skip program name argv[0] if present
  option::Stats stats(usage, argc, argv);
  std::unique_ptr<option::Option[]> options(new option::Option[stats.options_max]), buffer(new option::Option[stats.buffer_max]);
  option::Parser parse(usage, argc, argv, options.get(), buffer.get());

  if (parse.error())
    exit(0);

  if (options[HELP])
  {
    option::printUsage(std::cout, usage);
    exit(0);
  }

  if (options[HUMANREADABLE])
  {
    human_readable = true;
  }

  // parse options
  for (option::Option *opt = options[UNKNOWN]; opt; opt = opt->next())
    std::cout << "Unknown option: " << opt->name << "\n";

  for (int i = 0; i < parse.nonOptionsCount(); ++i)
  {
    switch (i)
    {
    case 0:
      iscript_bin = parse.nonOption(i);
      break;
    case 1:
      iscript_txt = parse.nonOption(i);
      break;
    default:
      break;
    }
  }

  if (iscript_bin.empty())
  {
    cerr << "Error: 'iscript.bin' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  if (iscript_txt.empty())
  {
    cerr << "Error: 'iscript.txt' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  return 0;
}

int main(int argc, const char **argv)
{
#ifdef HAVE_LOG4CXX
  if (FileExists("logging.prop"))
  {
    log4cxx::PropertyConfigurator::configure("logging.prop");
  }
  else
  {
    logger.off();
  }
#endif // HAVE_LOG4CXX

  parseOptions(argc, argv);

  bool iscript_bin_exists = FileExists(iscript_bin);
  if(!iscript_bin_exists)
  {
    cerr << "iscript.bin not existing - exit!" << endl;
    exit(1);
  }

  // STARCRAFT
  //std::string filename = "/home/andreas/Games/DOS/Starcraft/Original_Backup/starcraft_install.exe_MPQ_stardat.mpq/scripts/iscript.bin";

  // BROODWAR
  //std::string filename = "/home/andreas/Games/DOS/Starcraft/Original_Backup/broodwar_install.exe_MPQ_broodat.mpq/scripts/iscript.bin";

  IScript iscript(iscript_bin);
  iscript.parseIScript();

  std::vector<Opcode> &opcode_vector = iscript.getOpcodeVector();
  std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map = iscript.getIScriptSCPEHeaderMap();

  IScriptConverter iscript_converter;
  iscript_converter.setHumanReadable(human_readable);
  string header_string = iscript_converter.convertSCPEHeaderMap(iscript_scpe_header_map);
  string opcode_string = iscript_converter.convertOpcodeVector(opcode_vector);

  cout << header_string;
  cout << opcode_string;

  return 0;
}
