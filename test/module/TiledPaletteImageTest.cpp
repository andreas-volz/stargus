#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// Project
#include "TiledPaletteImageTest.h"
#include "../src/tileset/TiledPaletteImage.h"
#include "../src/PngExporter.h"
#include "Palette.h"

// System

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(TiledPaletteImageTest);

void TiledPaletteImageTest::setUp()
{

}

void TiledPaletteImageTest::tearDown()
{

}

void TiledPaletteImageTest::test1_tileStrategyCompare()
{
  string test_data_dir = "test/module/data/";
  string save_num_name_png = "TiledPaletteImageTest1_num.png";
  string save_pos_name_png = "TiledPaletteImageTest_pos.png";

  Palette pal;

  // define the colors
  Color black(0, 0, 0);
  Color red(255, 0, 0);
  Color green(0, 255, 0);
  Color blue(0, 0, 255);
  Color yellow(255, 255, 0);

  // add the colors in the palette
  pal.at(0) = black;
  pal.at(1) = red;
  pal.at(2) = green;
  pal.at(3) = blue;
  pal.at(4) = yellow;

  PaletteImage red_image(Size(8, 8));
  red_image.fill(1);

  PaletteImage green_image(Size(8, 8));
  green_image.fill(2);

  PaletteImage blue_image(Size(8, 8));
  blue_image.fill(3);

  PaletteImage yellow_image(Size(8, 8));
  yellow_image.fill(4);

  tileset::TiledPaletteImage tiled_image_num(Size(2, 2), Size(8, 8));
  tileset::TiledPaletteImage tiled_image_pos(Size(2, 2), Size(8, 8));

  // fill the tiled image with the little tiles by incrementing number
  tiled_image_num.copyTile(red_image, 0);
  tiled_image_num.copyTile(green_image, 1);
  tiled_image_num.copyTile(blue_image, 2);
  tiled_image_num.copyTile(yellow_image, 3);

  // fill the tiled image with the little tiles by specifying the tile position
  tiled_image_pos.copyTile(red_image, Pos(0, 0));
  tiled_image_pos.copyTile(green_image, Pos(1, 0));
  tiled_image_pos.copyTile(blue_image, Pos(0, 1));
  tiled_image_pos.copyTile(yellow_image, Pos(1, 1));

  // export the PNGs for visual test feedback
  //PngExporter::save(save_num_name_png, tiled_image_num, pal, 255);
  //PngExporter::save(save_pos_name_png, tiled_image_pos, pal, 255);

  // this test just checks if adding the tiles by #num or Pos gives us the same result
  CPPUNIT_ASSERT(tiled_image_num == tiled_image_pos);

  //std::remove(save_num_name_png.c_str());
  //std::remove(save_pos_name_png.c_str());
}

