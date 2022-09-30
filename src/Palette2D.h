/*
 * Palette2D.h
 *
 *      Author: Andreas Volz
 */

#ifndef PALETTE2D_H
#define PALETTE2D_H

// project
#include "Color.h"
#include "Palette.h"

// system
#include <vector>
#include <array>

class Palette2D
{
public:
  Palette2D(int size);

  Palette2D(std::shared_ptr<DataChunk> rawPalette);

  virtual ~Palette2D();

  const Color &at(int x, int y) const;

  Color &at(int x, int y);

  int getSize();

  bool write(const std::string &filename);

private:
  std::vector<Palette> mColorPalette2D;
  int mSize;
};

#endif /* PALETTE2D_H */
