#ifndef TESTTIME_H
#define TESTTIME_H

#include "TestingTools.h"
#include "Time.h"

class TestTime
{
  public:
    TestTime(TestingTools &tools);
    virtual ~TestTime();

    void all();

    void emptyConstructor();
    void paramConstructor();
    void setGetHour();
    void setGetMinute();
    void setGetSecond();
    void assignmentOperator();

  protected:

  private:
    TestingTools * tools;
};

#endif // TESTTIME_H
