#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// project
#include "PaletteTest.h"
#include "StringUtil.h"

// system
#include <algorithm>
#include <iostream>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(PaletteTest);

void PaletteTest::setUp()
{

}

void PaletteTest::tearDown()
{

}

void PaletteTest::test1_rotate_basic()
{
  vector<int> original {0, 1, 2,
                        3, 4, 5,
                        6, 7, 8};
  vector<int> target   {0, 1, 2,
                        5, 3, 4, /* those are rotated about +1 */
                        6, 7, 8};
  vector<int> rotated(original);

  int start = 3;
  int end = 5;
  int amount = 1;

  shift(start, end, amount, original, rotated);

  /*cout << endl;
  cout << "original: "; printVector(original);
  cout << "rotated: "; printVector(rotated);
  cout << "target: "; printVector(target);
  cout << endl;*/

  CPPUNIT_ASSERT(rotated == target);
}

void PaletteTest::test2_rotate_more()
{
  vector<int> original {0, 1,
                        2, 3, 4, 5, 6,
                        7, 8};
  vector<int> target   {0, 1,
                        4, 5, 6, 2, 3,  /* those are rotated about +3 */
                        7, 8};
  vector<int> rotated(original);

  int start = 2;
  int end = 6;
  int amount = 3;

  shift(start, end, amount, original, rotated);

  /*cout << endl;
  cout << "original: "; printVector(original);
  cout << "rotated: "; printVector(rotated);
  cout << "target: "; printVector(target);
  cout << endl;*/

  CPPUNIT_ASSERT(rotated == target);
}

void PaletteTest::test3_rotate_much()
{
  vector<int> original {0, 1,
                        2, 3, 4, 5, 6,
                        7, 8};
  vector<int> rotated(original);

  int start = 2;
  int end = 6;
  int amount = 30;

  shift(start, end, amount, original, rotated);

  // don't really care about the result, just ensure not to crash after rotation more then vector length
  CPPUNIT_ASSERT(true);
}

void PaletteTest::shift(unsigned int start, unsigned int end, unsigned int amount, const std::vector<int> &original, std::vector<int> &rotated)
{
  // Ensure amount is within the bounds of the subarray
  int subarray_size = end - start + 1;
  amount = amount % subarray_size;

  // makes a temporal copy of a part of the vector
  vector<int> temp(rotated.begin() + start, rotated.begin() + end + 1);
  rotate(temp.rbegin(), temp.rbegin() + amount, temp.rend());

  // Copy the rotated part back into the original vector
  copy(temp.begin(), temp.end(), rotated.begin() + start);
}
