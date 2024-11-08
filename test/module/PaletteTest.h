#ifndef PALETTE_TEST_H
#define PALETTE_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

// project

// system
#include <string.h>
#include <cstdio>
#include <vector>

class PaletteTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE(PaletteTest);

  CPPUNIT_TEST(test1_rotate_basic);
  CPPUNIT_TEST(test2_rotate_more);
  CPPUNIT_TEST(test3_rotate_much);

  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

protected:
  /**
   * basic test to rotate a sub part of a vector<int>
   * this is the foundation of the real palette shift algorithm
   */
  void test1_rotate_basic();

  /**
   * little more advanced test to rotate a sub part of a vector<int>
   * this is the foundation of the real palette shift algorithm
   */
  void test2_rotate_more();

  void test3_rotate_much();


private:
  /**
   * Perform a rotation of rotated by `amount` to the right within the range [start, end]
   * It makes a temporal copy of a part of the vector
   */
  void shift(unsigned int start, unsigned int end, unsigned int amount, const std::vector<int> &original, std::vector<int> &rotated);
};

#endif // PALETTE_TEST_H
