#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include "TestingTools.h"
#include "Vector.h"

class TestVector
{
  public:
    TestVector(TestingTools &toolsRef);
    virtual ~TestVector();

    void all();

    void emptyConstructor();
    void paramConstructor();
    void copyConstructor();
    void assignmentOperator();
    void get();
    void getSize();
    void getMaxSize();
    void insert();
    void clear();
    void empty();
    void increaseSize();

  protected:
  private:
    TestingTools * tools;
};

#endif // TESTVECTOR_H
