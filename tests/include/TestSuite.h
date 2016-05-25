#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <TestingTools.h>
#include <TestNode.h>
#include <TestBinarySearchTree.h>

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

  private:
    TestingTools tools;
};

#endif // TESTSUITE_H
