#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// System


// Project
#include "PcxTest.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(PcxTest);

void PcxTest::setUp()
{

}

void PcxTest::tearDown()
{

}

void PcxTest::test1_SaveIndexedPalettePNG()
{
  string test_data_dir = "test/module/data/";
  string load_pcx_name = "PcxTest_red_zergb.pcx";
  string save_pal_name = "red_zergb.pal";
  string save_png_name = "red_zergb.png";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(test_data_dir);

  Pcx pcx1(breeze, load_pcx_name);
  pcx1.savePNG(save_png_name);
  std::shared_ptr<Palette> pal = pcx1.getPalette();
  pal->getDataChunk()->write(save_pal_name);

  CPPUNIT_ASSERT(compareFiles(save_pal_name, test_data_dir + "/PcxTest_" + save_pal_name));
  CPPUNIT_ASSERT(compareFiles(save_png_name, test_data_dir + "/PcxTest_" + save_png_name));

  std::remove(save_pal_name.c_str());
  std::remove(save_png_name.c_str());
}

void PcxTest::test2_copyIndexPaletteIconColor()
{
  string test_data_dir = "test/module/data/";
  string load_pcx_name = "PcxTest_red_zergb.pcx";
  string save_pal_name = "red_zergb.pal";
  string save_png_name = "red_zergb.png";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(test_data_dir);

  Pcx pcx1(breeze, load_pcx_name);
  pcx1.savePNG(save_png_name);
  std::shared_ptr<Palette> pal = pcx1.getPalette();
  pal->getDataChunk()->write(save_pal_name);

  CPPUNIT_ASSERT(compareFiles(save_pal_name, test_data_dir + "/PcxTest_" + save_pal_name));
  CPPUNIT_ASSERT(compareFiles(save_png_name, test_data_dir + "/PcxTest_" + save_png_name));

  std::remove(save_pal_name.c_str());
  std::remove(save_png_name.c_str());
}
