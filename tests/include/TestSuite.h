#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "TestingTools.h"
#include "TestNode.h"
#include "TestBinarySearchTree.h"
#include "TestVector.h"
#include "TestDate.h"
#include "TestTime.h"
#include "TestDateTime.h"
#include "TestDateFormat.h"

#include <iostream>
using namespace std;

class TestSuite
{
  public:
    TestSuite();
    virtual ~TestSuite();

    void all();

    void testNode();
    void testBinarySearchTree();
    void testVector();

    void testDate();
    void testTime();
    void testDateTime();
    void testDateFormat();


  private:
    TestingTools tools;
};

#endif // TESTSUITE_H
