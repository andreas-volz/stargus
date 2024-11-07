#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// System
#include <zlib.h>

// Project
#include "StormTest.h"
#include "platform.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(StormTest);

const std::string StormTest::TEST_DATA_DIR("test/module/data/");
const std::string StormTest::TEST_OUTPUT_DIR("test/module/output/");

void StormTest::setUp()
{

}

void StormTest::tearDown()
{

}

void StormTest::test1_mpq_txt_extractMemory()
{
  unsigned char *text_str = NULL;
  size_t bufLen = 0;
  string content_result = "stormtest";
  string mpq_arc_file = "test.txt";

  shared_ptr<Storm> storm = make_shared<Storm>(TEST_DATA_DIR + "StormTest_test1_mpq_txt.mpq");

  bool result = storm->extractMemory(mpq_arc_file, &text_str, &bufLen);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT((int)bufLen == ((int)content_result.length() + 1)); // calculate +1 because the '\0' counts extra in the raw char* data
  CPPUNIT_ASSERT(string((char *) text_str) != string(content_result));

  free(text_str);
}

void StormTest::test2_mpq_txt_extractFile()
{
  string content_result = "stormtest";
  string mpq_arc_file = "test.txt";
  string savename = "test.txt";

  shared_ptr<Storm> storm = make_shared<Storm>(TEST_DATA_DIR + "StormTest_test1_mpq_txt.mpq");

  bool result = storm->extractFile(mpq_arc_file, TEST_OUTPUT_DIR + savename, false);

  CPPUNIT_ASSERT(result == true);
  CPPUNIT_ASSERT(content_result == getStringFromFile(TEST_OUTPUT_DIR + savename));

  fs::remove(TEST_OUTPUT_DIR + savename);
}

void StormTest::test3_mpq_txt_extractFileCompressed()
{
  string content_result = "stormtest";
  string mpq_arc_file = "test.txt";
  string savename = "test.txt.gz";
  gzFile gzfile = nullptr;

  shared_ptr<Storm> storm = make_shared<Storm>(TEST_DATA_DIR + "StormTest_test1_mpq_txt.mpq");

  bool result = storm->extractFile(mpq_arc_file, TEST_OUTPUT_DIR + savename, true);

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
