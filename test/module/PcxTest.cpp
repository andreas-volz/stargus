#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// System


// Project
#include "PcxTest.h"
#include "platform.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(PcxTest);

const std::string PcxTest::TEST_DATA_DIR("test/module/data/");
const std::string PcxTest::TEST_OUTPUT_DIR("test/module/output/");

void PcxTest::setUp()
{

}

void PcxTest::tearDown()
{

}

void PcxTest::test1_SaveIndexedPalettePNG()
{
  string load_pcx_name = "PcxTest_red_zergb.pcx";
  string save_pal_name = "red_zergb.pal";
  string save_png_name = "red_zergb.png";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  Pcx pcx1(breeze, load_pcx_name);
  pcx1.savePNG(TEST_OUTPUT_DIR + save_png_name);
  std::shared_ptr<Palette> pal = pcx1.getPalette();
  pal->createDataChunk()->write(TEST_OUTPUT_DIR + save_pal_name);

  CPPUNIT_ASSERT(compareFiles(TEST_OUTPUT_DIR + save_pal_name, TEST_DATA_DIR + "/PcxTest_" + save_pal_name));
  CPPUNIT_ASSERT(compareFiles(TEST_OUTPUT_DIR + save_png_name, TEST_DATA_DIR + "/PcxTest_" + save_png_name));

  fs::remove(TEST_OUTPUT_DIR + save_pal_name.c_str());
  fs::remove(TEST_OUTPUT_DIR + save_png_name.c_str());
}

void PcxTest::test2_mapIndexPalette()
{
  string load_pcx_name = "PcxTest_ticon.pcx";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  Pcx pcx1(breeze);

  for(unsigned int index = 0; index < 6; index++)
  {
    string save_pal_name = string("ticon_") + to_string(index) + ".pal";
    string save_png_name = string("ticon_") + to_string(index) + ".png";

    pcx1.load(load_pcx_name);
    pcx1.savePNG(TEST_OUTPUT_DIR + save_png_name);
    std::shared_ptr<Palette> pal = pcx1.mapIndexPalette(8, 1, index);
    pal->createDataChunk()->write(TEST_OUTPUT_DIR + save_pal_name);

    CPPUNIT_ASSERT(compareFiles(TEST_OUTPUT_DIR + save_pal_name, TEST_DATA_DIR + "/PcxTest_" + save_pal_name));
    CPPUNIT_ASSERT(compareFiles(TEST_OUTPUT_DIR + save_png_name, TEST_DATA_DIR + "/PcxTest_" + save_png_name));

    fs::remove(TEST_OUTPUT_DIR + save_pal_name.c_str());
    fs::remove(TEST_OUTPUT_DIR + save_png_name.c_str());
  }
}

