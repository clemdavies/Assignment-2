#ifndef TESTNODE_H
#define TESTNODE_H

#include "TestingTools.h"

#include "Node.h"
#include "Date.h"

class TestNode
{
  public:
    TestNode(TestingTools &initTools);
    virtual ~TestNode();

    void all();

    void creation();
    void nesting();

  private:
    TestingTools *tools;
};

#endif // TESTNODE_H
