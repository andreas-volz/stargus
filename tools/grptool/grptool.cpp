/*
 * grptool.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include "optparser.h"
#include "libgrp/libgrp.hpp"
#include "Logger.h"
#include "FileUtil.h"
#include "Breeze.h"
#include "NoValidPaletteException.h"
#include "Palette2D.h"
#include "Storage.h"

// system
#include <iostream>
#include <memory>

using namespace std;

/**
 * Description
 */

static Logger logger("grptool");

// some global variables
string palette_file;
string grp_file;
bool duplicates = true;
bool single_stiched = true;
int image_per_row = 10;
bool rgba = false;
string destination_directory;




enum optionIndex
{
  UNKNOWN, HELP, PALETTE, DUPLICATES, IMAGE_ROW, SINGLE_FRAMES, RGBA
};
const option::Descriptor usage[] =
{
  {
    UNKNOWN, 0, "", "", option::Arg::None, "USAGE: grptool [options] grp-file destination-directory\n\n"
    "Options:"
  },
  { HELP, 0, "h", "help", option::Arg::None, "  --help, -h  \t\tPrint usage and exit" },
  { RGBA, 0, "r", "rgba", option::Arg::None, "  --rgba, -r  \t\tForce RGBA PNG export for 8-bit palettes" },
  { DUPLICATES, 0, "d", "duplicates", Arg::Required, "  --duplicates yes|no, -d yes|no  \t\tgenerate duplicate frames (default: yes)" },
  { PALETTE, 0, "p", "palette", Arg::Required, "  --palette, -p  \t\tSpecify the path to a palette file" },
  { IMAGE_ROW, 0, "i", "image-row", Arg::Numeric, "  --image-row, -i  \t\tIf stitching is enabled, how many images should be saved per row (default: 10)" },
  { SINGLE_FRAMES, 0, "s", "single-frames", Arg::None, "  --single-frames, -s  \t\tExport each frame into one image (default: all stitched together)" },
  {
    UNKNOWN, 0, "", "", option::Arg::None,
    "\ngrp-file \t\tThe GRP file which should be converted.\n"
    "\ndestination-directory \t\tWhere to save the extracted file with same relative path.\n"

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

  if ( options[DUPLICATES].count() > 0 )
  {
    if(string(options[DUPLICATES].arg) == "no")
    {
      duplicates = false;
    }
    else
    {
      duplicates = true;
    }
  }

  if(options[IMAGE_ROW].count() > 0)
  {
    image_per_row = stoi(options[IMAGE_ROW].arg);
  }

  if(options[SINGLE_FRAMES].count() > 0)
  {
    single_stiched = false;
  }

  if(options[PALETTE].count() > 0)
  {
    palette_file = options[PALETTE].arg;
  }
  else
  {
    cerr << "Error: 'palette' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  if(options[RGBA].count() > 0 )
  {
    rgba = true;
  }

  // parse options

  for (option::Option *opt = options[UNKNOWN]; opt; opt = opt->next())
    std::cout << "Unknown option: " << opt->name << "\n";

  for (int i = 0; i < parse.nonOptionsCount(); ++i)
  {
    switch (i)
    {
    case 0:
      grp_file = parse.nonOption(i);
      break;
    case 1:
      //cerr << "destination-directory #" << i << ": " << parse.nonOption(i) << "\n";
      destination_directory = parse.nonOption(i);
      break;
    default:
      break;
    }
  }

  if (grp_file.empty())
  {
    cout << "Error: 'archive' not given!" << endl << endl;
    option::printUsage(std::cout, usage);
    exit(1);
  }

  if (destination_directory.empty())
  {
    cout << "Error: 'destination_directory' not given!" << endl << endl;
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

   Storage pngStorage;
   CheckPath(destination_directory);
   pngStorage.setDataPath(destination_directory);

  std::shared_ptr<AbstractPalette> myGRPPallete;
  try
  {
    shared_ptr<DataChunk> dc = make_shared<DataChunk>();
    dc->read(palette_file);
    myGRPPallete = AbstractPalette::create(dc);
  }
  catch(NoValidPaletteException &palEx)
  {
    cerr << palEx.what() << endl;
  }

  bool grp_file_exist = FileExists(grp_file);
  if(!grp_file_exist)
  {
    cerr << "GRP file not existing - Exit!" << endl;
    exit(1);
  }

  if(myGRPPallete)
  {
    //myGRPPallete->write("test.pal");

    GRPImage myGRPImage(grp_file, !duplicates);
    myGRPImage.SetColorPalette(myGRPPallete);

    //image_per_row=17 => starcraft
    if(single_stiched)
    {
      myGRPImage.SaveStitchedPNG(pngStorage("output_frame.png"), 0, myGRPImage.getNumberOfFrames(), image_per_row, rgba);
    }
    else
    {
      myGRPImage.SaveSinglePNG(pngStorage("output_frame%d.png"), 0, myGRPImage.getNumberOfFrames(), rgba);
    }

    cout << "Image tilesize width: " << myGRPImage.getMaxImageWidth() << endl;
    cout << "Image tilesize height: " << myGRPImage.getMaxImageHeight() << endl;
  }
  else
  {
    cerr << "Palette not successful loaded - Exit!" << endl;
    exit(1);
  }

  cout << "Application finished!" << endl;

  return 0;
}
