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
