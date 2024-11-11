/*
 * PaletteImage.cpp
 *
 *      Author: Andreas Volz
 */

// project
#include "PaletteImage.h"

// system
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

PaletteImage::PaletteImage(const DataChunk &datachunk, const Size &size) :
  mData(datachunk.getDataPointer(), datachunk.getDataPointer()+datachunk.getSize()),
  mSize(size)
{
}

PaletteImage::PaletteImage(const Size &size) :
  mData(size.getWidth() * size.getHeight(), 0),
  mSize(size)
{
}
PaletteImage::PaletteImage(const PaletteImage &paletteImage, const std::vector<std::pair<unsigned char, unsigned char>> &replacer) :
    mData(paletteImage.mSize.getWidth() * paletteImage.mSize.getHeight(), 0),
    mSize(paletteImage.mSize)
{
  transform(paletteImage.mData.begin(), paletteImage.mData.end(), mData.begin(), [&replacer](unsigned char c) {
    for(auto r : replacer)
    {
      if(c == r.first)
      {
        return r.second;
      }
    }

    return c;
   });
}

PaletteImage::~PaletteImage()
{

}

const unsigned char* PaletteImage::getRawDataPointer() const
{
  return mData.data();
}

size_t PaletteImage::positionToIndex(const Pos &pos) const
{
  size_t data_pos = 0;

  // if pos is outside image return just 0 as fail safe
  if((pos.getX() < mSize.getWidth()) || (pos.getY() < mSize.getHeight()) || (pos.getX() > 0) || (pos.getY() > 0))
  {
    data_pos = (pos.getY() * mSize.getWidth()) + pos.getX();
  }

  return data_pos;
}

const Pos PaletteImage::indexToPosition(size_t index) const
{
  int y = 0;
  int x = 0;

  // if index is out of data size that return Pos(0, 0) as fail safe
  if(index < mData.size())
  {
    y = index / mSize.getWidth();
    x = index % mSize.getWidth();
  }

  return Pos(x, y);
}

const Size PaletteImage::getSize() const
{
  return mSize;
}

unsigned char &PaletteImage::at(const Pos &pos)
{
  return at(positionToIndex(pos));
}

const unsigned char &PaletteImage::at(const Pos &pos) const
{
  return at(positionToIndex(pos));
}

unsigned char &PaletteImage::at(size_t pos)
{
  return mData.at(pos);
}

const unsigned char &PaletteImage::at(size_t pos) const
{
  return mData.at(pos);
}

void PaletteImage::fill(unsigned char color_index)
{
  for(unsigned int i = 0; i < mData.size(); i++)
  {
    mData.at(i) = color_index;
  }
}

bool PaletteImage::operator== (const PaletteImage& image_cmp)
{
  // if the same object
  if (this == &image_cmp)
  {
    return true;
  }

  // if the size isn't the same no content needs to be checked
  if(image_cmp.getSize() != this->getSize())
  {
    return false;
  }

  // compare the content of the pixel data
  if(image_cmp.mData == this->mData)
  {
    return true;
  }

  return false;
}

bool PaletteImage::hasPaletteIndex(unsigned char index)
{
  bool found_index = false;

  auto it_found = find(mData.begin(), mData.end(), index);
  if(it_found != mData.end())
  {
    found_index = true;
  }

  return found_index;
}

bool PaletteImage::hasPaletteIndexRange(unsigned char start_index, unsigned char end_index)
{
  bool found_index = false;

  for(unsigned char i = start_index; i <= end_index; i++)
  {
    found_index = hasPaletteIndex(i);
    if(found_index)
    {
      break;
    }
  }

  return found_index;
}


