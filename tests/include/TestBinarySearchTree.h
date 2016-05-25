#ifndef TESTBINARYSEARCHTREE_H
#define TESTBINARYSEARCHTREE_H

#include "TestingTools.h"
#include "BinarySearchTree.h"
#include "Node.h"

#include "Date.h"

#include <sstream>

class TestBinarySearchTree
{
  public:
    TestBinarySearchTree(TestingTools &initTools);
    virtual ~TestBinarySearchTree();

    void all();

    void construction();

    void insertNodes();
    void removeNodes();
    void processNodes();
    void search();

    template <class T>
    static void nodePrint(T &data);

  protected:
  private:
    TestingTools *tools;
    static stringstream printString;

    void clearSStreams(stringstream &sstream);
};

#endif // TESTBINARYSEARCHTREE_H
