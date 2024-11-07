#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// System
#include <zlib.h>

// Project
#include "BreezeTest.h"
#include "platform.h"
#include "TestHelpers.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(BreezeTest);

const std::string BreezeTest::TEST_DATA_DIR("test/module/data/");
const std::string BreezeTest::TEST_OUTPUT_DIR("test/module/output/");

void BreezeTest::setUp()
{

}

void BreezeTest::tearDown()
{

}

void BreezeTest::test1_txt_extractMemory()
{
  unsigned char *text_str = NULL;
  size_t bufLen = 0;
  string content_result = "breezetest";
  string arc_file = "breezetest.txt";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  bool result = breeze->extractMemory(arc_file, &text_str, &bufLen);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT((int)bufLen == ((int)content_result.length() + 1)); // calculate +1 because the '\0' counts extra in the raw char* data
  CPPUNIT_ASSERT(string((char *) text_str) != string(content_result));

  CPPUNIT_ASSERT(true);
}

void BreezeTest::test2_txt_extractFile()
{
  string content_result = "breezetest";
  string arc_file = "breezetest.txt";
  string savename = "breezetest_test.txt";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  bool result = breeze->extractFile(arc_file, TEST_OUTPUT_DIR + savename, false);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT(compareFiles(TEST_DATA_DIR + arc_file, TEST_OUTPUT_DIR + savename));

  fs::remove(TEST_OUTPUT_DIR + savename);
}

void BreezeTest::test3_txt_extractFileCompressed()
{
  string content_result = "breezetest";
  string arc_file = "breezetest.txt";
  string savename = "test.txt.gz";
  gzFile gzfile = nullptr;

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  bool result = breeze->extractFile(arc_file, TEST_OUTPUT_DIR + savename, true);

  // read back & compare ->

  gzfile = gzopen((TEST_OUTPUT_DIR + savename).c_str(), "r");

  int err;
  int bytes_read;
  int max_length = 1024;
  unsigned char buffer[max_length];
  bytes_read = gzread(gzfile, buffer, max_length - 1);
  buffer[bytes_read] = '\0';

  if (bytes_read < max_length - 1)
  {
    if (!gzeof(gzfile))
    {
      gzerror(gzfile, & err);
      CPPUNIT_ASSERT(err);
    }
  }

  std::string dest(buffer, buffer + bytes_read-1);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT(content_result == dest);

  fs::remove(TEST_OUTPUT_DIR + savename);
}

void BreezeTest::test4_bigdata_extractFile()
{
  string arcfile = "png-1mb.png";
  string savefile = "png-1mb_copy.png";

  shared_ptr<Breeze> breeze = make_shared<Breeze>(TEST_DATA_DIR);

  bool result = breeze->extractFile(arcfile, TEST_OUTPUT_DIR + savefile, false);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT(compareFiles(TEST_DATA_DIR + arcfile, TEST_OUTPUT_DIR + savefile));

  fs::remove(TEST_OUTPUT_DIR + savefile);
}
