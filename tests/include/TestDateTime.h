#ifndef TESTDATETIME_H
#define TESTDATETIME_H

#include "TestingTools.h"
#include "DateTime.h"
#include "Date.h"
#include "Time.h"

class TestDateTime
{
  public:
    TestDateTime( TestingTools &initTools );
    virtual ~TestDateTime();

    void all();

    void objectParamConstructor();
    void primitiveParamConstructor();

    void setGetDate();
    void setGetTime();

    void assignmentOperator();

  protected:
  private:
    TestingTools * tools;
};

#endif // TESTDATETIME_H
