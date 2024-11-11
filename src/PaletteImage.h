/*
 * PaletteImage.h
 *
 *      Author: Andreas Volz
 */

#ifndef PALETTEIMAGE_H
#define PALETTEIMAGE_H

// Project
#include "DataChunk.h"
#include "Size.h"
#include "Pos.h"

// System

/**
 * A PaletteImage could hold a number of Integers of fixed size width*height that describe a Palette based image.
 * The Image itself needs always an associated Palette in one of the savers (e.g. PngExporter).
 */
class PaletteImage
{
public:
  /**
   * Construct with specific size but zero data to fill byte by byte
   * It allows random access to fill the elements with data as the internal vector is constructed at that size
   */
  PaletteImage(const Size &size);

  /**
   * Construct with specific size but fill in one chunk
   */
  PaletteImage(const DataChunk &datachunk, const Size &size);

  PaletteImage(const PaletteImage &paletteImage, const std::vector<std::pair<unsigned char, unsigned char>> &replacer);

  virtual ~PaletteImage();

  /**
   * @return the internal std::vector<unsigned char> implementation. Handle carefully!!
   */
  virtual const unsigned char* getRawDataPointer() const;

  virtual const Size getSize() const;

  /**
   * Get or set a pixel with palette index based on l-value or r-value (and provide a const variant)
   * Just like a vector at() usage
   */
  virtual unsigned char &at(size_t pos);
  virtual const unsigned char &at(size_t pos) const;

  /**
   * set or get a pixel based on l-value/r-value implementation (and provide a const variant)
   */
  virtual unsigned char &at(const Pos &pos);
  virtual const unsigned char &at(const Pos &pos) const;

  virtual const Pos indexToPosition(size_t index) const;

  virtual size_t positionToIndex(const Pos &pos) const;

  /**
   * Fills the complete image with a specific index color from the Palette.
   * This has no real use case in the Exporter just for easier testing the class.
   */
  virtual void fill(unsigned char color_index);

  bool operator== (const PaletteImage& image_cmp);

  /**
   * Search if the image uses a specific palette index in it's data.
   */
  bool hasPaletteIndex(unsigned char index);

  /**
   * Search if at least one palette index in the range between [start_index; end_index] is used in the data.
   * This is helpful to identify if an image would be influenced by a specific palette cycle animation or not.
   */
  bool hasPaletteIndexRange(unsigned char start_index, unsigned char end_index);

private:
  std::vector<unsigned char> mData;
  Size mSize;
};

#endif /* PALETTEIMAGE_H */
