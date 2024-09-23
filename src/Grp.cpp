/*
 * Grp.cpp
 *
 *      Author: Andreas Volz
 */

// Local
#include <PngExporter.h>
#include "Grp.h"
#include "endian.h"
#include "FileUtil.h"
#include "Storm.h"
#include "Logger.h"
#include "StringUtil.h"

// System
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace nlohmann;

static Logger logger = Logger("startool.Grp");

Grp::Grp(std::shared_ptr<Hurricane> hurricane) :
  Converter(hurricane),
  mRGBA(false)
{
}

Grp::Grp(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile) :
  Converter(hurricane),
  mRGBA(false)
{
  load(arcfile);
}

Grp::Grp(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile, std::shared_ptr<AbstractPalette> pal) :
  Converter(hurricane),
  mPal(pal),
  mRGBA(false)
{
  load(arcfile);
}

Grp::~Grp()
{

}

void Grp::setPalette(std::shared_ptr<AbstractPalette> pal)
{
  mPal = pal;

  mGRPImage.SetColorPalette(pal);
}

void Grp::setRGBA(bool rgba)
{
  mRGBA = rgba;
}

bool Grp::getRGBA()
{
  return mRGBA;
}

bool Grp::load(const std::string &arcfile)
{
  //mArcfile = arcfile;

  std::shared_ptr<DataChunk> dcGrp = mHurricane->extractDataChunk(arcfile);

  std::vector<char> GrpVec = dcGrp->getCharVector();

  if(dcGrp)
  {
    mGRPImage.LoadImage(&GrpVec, false);
  }

  return true;
}

bool Grp::save(Storage filename)
{
  bool result = true;

  int IPR = 17;
  int end_frame = mGRPImage.getNumberOfFrames();

  // all IPR < 17 are buildings or similar and stratagus needs them in one image per row
  if(end_frame < IPR)
  {
    IPR = 1;
  }

  mGRPImage.SaveStitchedPNG(filename.getFullPath(), 0, end_frame, IPR, mRGBA);

  // save json file beside each png file with tilesize information in it. The engine needs this information.
  json j_grp_info = json::object({ {"width", mGRPImage.getMaxImageWidth()}, {"height", mGRPImage.getMaxImageHeight()} });
  saveJson(j_grp_info, filename(cutFileEnding(filename.getFilename(), ".png") + ".json"), true);

  return result;
}

Size Grp::getTileSize()
{
  Size size (mGRPImage.getMaxImageWidth(), mGRPImage.getMaxImageHeight());
  return size;
}

void Grp::saveJson(json &j, const std::string &file, bool pretty)
{
  std::ofstream filestream(file);

  if(pretty)
  {
    filestream << std::setw(4) << j;
  }
  else
  {
    filestream << j;
  }
}
