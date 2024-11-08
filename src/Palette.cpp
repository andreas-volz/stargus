/*
 * Palettes.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include <Palette.h>
#include "Logger.h"
#include "NoValidPaletteException.h"

// system
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

static Logger logger = Logger("startool.Palette");

Palette::Palette()
{

}


Palette::Palette(std::shared_ptr<DataChunk> rawPalette)
{
  load(rawPalette);
}

Palette::~Palette()
{
}

void Palette::load(std::shared_ptr<DataChunk> rawPalette)
{
  if(rawPalette->getSize() == 256 * 4) // RGBx/WPE size type
  {
    for(unsigned int i = 0; i < rawPalette->getSize(); i += 4)
    {
      unsigned char red = rawPalette->at(i);
      unsigned char green = rawPalette->at(i+1);
      unsigned char blue = rawPalette->at(i+2);
      // ignore the 4th component, as it is not used as alpha

      Color rgb(red, green, blue);
      at(i/4) = rgb;
    }
  }
  else if(rawPalette->getSize() == 256 * 3) // RGB size type
  {
    for(unsigned int i = 0; i < rawPalette->getSize(); i += 3)
    {
      unsigned char red = rawPalette->at(i);
      unsigned char green = rawPalette->at(i+1);
      unsigned char blue = rawPalette->at(i+2);

      Color rgb(red, green, blue);
      at(i/3) = rgb;
    }
  }
  else
  {
    throw NoValidPaletteException(rawPalette->getSize());
  }
}

std::shared_ptr<DataChunk> Palette::createDataChunk()
{
  std::shared_ptr<DataChunk> datachunk = make_shared<DataChunk>();

  for(auto color_it = mColorPalette.begin(); color_it < mColorPalette.end(); color_it++)
  {
    Color &rgb = *color_it;
    unsigned char red = rgb.getRed();
    unsigned char green = rgb.getGreen();
    unsigned char blue = rgb.getBlue();

    datachunk->addData(&red, 1);
    datachunk->addData(&green, 1);
    datachunk->addData(&blue, 1);
  }

  return datachunk;
}

Color &Palette::at(unsigned int index)
{
  return mColorPalette.at(index);
}

void Palette::shift(unsigned int start, unsigned int end, unsigned int amount)
{
  // Ensure amount is within the bounds of the subarray
  int subarray_size = end - start + 1;
  amount = amount % subarray_size;

  // makes a temporal copy of a part of the vector
  vector<Color> temp(mColorPalette.begin() + start, mColorPalette.begin() + end + 1);
  rotate(temp.rbegin(), temp.rbegin() + amount, temp.rend());

  // Copy the rotated part back into the original vector
  copy(temp.begin(), temp.end(), mColorPalette.begin() + start);
}
