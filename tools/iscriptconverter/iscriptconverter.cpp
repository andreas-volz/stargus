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

  IScript iscript(iscript_bin);
  iscript.parseIScript();

  std::vector<Opcode> &opcode_vector = iscript.getOpcodeVector();
  std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map = iscript.getIScriptSCPEHeaderMap();

  IScriptConverter iscript_converter;
  iscript_converter.setHumanReadable(human_readable);
  iscript_converter.saveConverted(iscript_txt, iscript_scpe_header_map, opcode_vector);

  return 0;
}
