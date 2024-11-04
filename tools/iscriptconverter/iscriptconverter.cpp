/* project */
#include "Breeze.h"
#include "Storm.h"
#include "Casc.h"
#include "FileUtil.h"
#include "iscript/IScript.h"
#include "iscript/IScriptConverter.h"
#include "optparser.h"
#include "Logger.h"
#include "StringUtil.h"

/* system */
#include <string>
#include <stdexcept>

using namespace std;

static Logger logger("startool.iscriptconverter");

// some global variables
bool human_readable = false;
string backend;
string archive;
string archive_file;
string destination_directory;

bool CheckCASCDataFolder(const std::string &dir)
{
  return FileExists(dir + "/.build.info");
}

shared_ptr<Hurricane> selectChoosenBackend()
{
  shared_ptr<Hurricane> hurricane;

  cerr << "Backend: " << backend << endl;
  if(to_lower(backend) == "breeze")
  {
    hurricane = make_shared<Breeze>(archive);
  }
  else if(to_lower(backend) == "storm")
  {
    hurricane = make_shared<Storm>(archive);
  }
  else if(to_lower(backend) == "casc")
  {
#ifdef HAVE_CASC
    if(CheckCASCDataFolder(archive))
    {
      hurricane = make_shared<Casc>(archive);
    }
    else
    {
      cerr << "Error: 'archive' is not a CASC archive!" << endl;
    }
#else
    cerr << "Error: No CASC support compiled into sauwetter!" << endl;
    exit(1);
#endif
  }

  return hurricane;
}

enum optionIndex
{
  UNKNOWN, HELP, HUMANREADABLE, BACKEND
};
const option::Descriptor usage[] =
{
  {
    UNKNOWN, 0, "", "", option::Arg::None, "USAGE: iscriptconverter [options] archive destination-directory\n\n"
    "Options:"
  },
  { HELP, 0, "h", "help", option::Arg::None, "  --help, -h  \t\tPrint usage and exit" },
  { HUMANREADABLE, 0, "r", "human-readable", Arg::None, "  --human-readable, -r  \t\tGenerate output with human readable names (e.g. for debugging or analysis)" },
  { BACKEND, 0, "b", "backend", Arg::Required, "  --backend, -b  \t\tChoose a backend (storm=St*arcr*ft1/Br**dwar;casc=Remastered;breeze=Folder)" },
  {
    UNKNOWN, 0, "", "", option::Arg::None,
    "\narchive \t\tDestination to the archive (mpq, casc or dummy folder) based on backend.\n"
    "\ndestination-directory \t\tWhere to save the extracted file with same relative path.\n\n"
    "(Hint: The exporter expects the input in \"scripts/iscript.bin\")"
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

  if(options[BACKEND].count() > 0)
  {
    backend = options[BACKEND].arg;
  }
  else
  {
    cerr << "Error: 'backend' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  // parse options
  for (option::Option *opt = options[UNKNOWN]; opt; opt = opt->next())
    std::cout << "Unknown option: " << opt->name << "\n";

  for (int i = 0; i < parse.nonOptionsCount(); ++i)
  {
    switch (i)
    {
    case 0:
      archive = parse.nonOption(i);
      break;
    case 1:
      destination_directory = parse.nonOption(i);
      break;
    default:
      break;
    }
  }

  if (archive.empty())
  {
    cerr << "Error: 'archive' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  if (destination_directory.empty())
  {
    cerr << "Error: 'destination_directory' not given!" << endl << endl;
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

  shared_ptr<Hurricane> hurricane = selectChoosenBackend();

  string iscript_bin = "scripts\\iscript.bin";
  IScript iscript(hurricane, iscript_bin);
  iscript.parseIScript();

  std::vector<Opcode> &opcode_vector = iscript.getOpcodeVector();
  std::map<uint16_t, std::vector<uint16_t>> &iscript_scpe_header_map = iscript.getIScriptSCPEHeaderMap();

  IScriptConverter iscript_converter;
  iscript_converter.setHumanReadable(human_readable);
  string iscript_txt = destination_directory + "/iscript.txt";
  iscript_converter.saveConverted(iscript_txt, iscript_scpe_header_map, opcode_vector);

  return 0;
}
