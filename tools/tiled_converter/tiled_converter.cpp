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
#include "Chk.h"
#include "tileset/TilesetHub.h"

/* system */
#include <string>
#include <stdexcept>

using namespace std;

static Logger logger("startool.tiled_converter");

// some global variables
bool pretty = true;
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
  UNKNOWN, HELP, PRETTY, BACKEND
};
const option::Descriptor usage[] =
{
  {
    UNKNOWN, 0, "", "", option::Arg::None, "USAGE: tiled_converter [options] archive destination-directory\n\n"
    "Options:"
  },
  { HELP, 0, "h", "help", option::Arg::None, "  --help, -h  \t\tPrint usage and exit" },
  { PRETTY, 0, "p", "pretty", Arg::Required, "  --pretty=[yes/no], -p  \t\tPretty print the formated JSON file (default: yes)" },
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

  if ( options[PRETTY].count() > 0 )
  {
    if (string(options[PRETTY].arg) == "yes")
    {
      pretty = true;
    }
    else if (string(options[PRETTY].arg) == "no")
    {
      pretty = false;
    }
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

  archive = "/home/andreas/Games/DOS/Starcraft/Original_Backup/starcraft_install.exe_MPQ_stardat.mpq/tileset";
  shared_ptr<Hurricane> hurricane = selectChoosenBackend();

  Storage tilesets;
  tilesets.setDataPath("/home/andreas/tmp");
  tilesets.setDataType("tilesets");
  tileset::TilesetHub tilesethub(hurricane, "platform");
  tilesethub.generateTilesetJson(tilesets("platform.tsj"));

  /*** Chk ***/

  archive = "/home/andreas/src/git/stargus/chk";
  shared_ptr<Hurricane> hurricane2 = selectChoosenBackend();

  // TODO: just use this while development. Later it's more difficult with scm files...
  string chk_file = "scenario.chk";

  Chk chk(hurricane2);
  chk.convert(chk_file, tilesethub, tilesets("platform.tmj"));



  return 0;
}
