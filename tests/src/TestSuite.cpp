#include "TestSuite.h"

TestSuite::TestSuite()
{
  //ctor
}

TestSuite::~TestSuite()
{
  //dtor
}


void TestSuite::all()
{
  testNode();
  testBinarySearchTree();
  testVector();
  testDate();
  testTime();
  testDateTime();
  testDateFormat();

  tools.outputTotals();
  cout << tools.getOutputStream().str() << endl;
}


void TestSuite::testNode()
{
  TestNode test(tools);
  test.all();
}

void TestSuite::testBinarySearchTree()
{
  TestBinarySearchTree test(tools);
  test.all();
}

void TestSuite::testVector()
{
  TestVector test(tools);
  test.all();
}


void TestSuite::testDate()
{
  TestDate test(tools);
  test.all();
}

void TestSuite::testTime()
{
  TestTime test (tools);
  test.all();
}

void TestSuite::testDateTime()
{
  TestDateTime test(tools);
  test.all();
}

void TestSuite::testDateFormat()
{
  TestDateFormat test(tools);
  test.all();
}
