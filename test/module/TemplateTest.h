#ifndef TEMPLATE_TEST_H
#define TEMPLATE_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

// project

// system
#include <string.h>
#include <cstdio>


class TemplateTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE(TemplateTest);

  CPPUNIT_TEST(test1_func);

  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

protected:
  /**
   * Tbd
   */
  void test1_func();


private:

};

#endif // TEMPLATE_TEST_H
