#ifndef TESTDATEFORMAT_H
#define TESTDATEFORMAT_H

#include "TestingTools.h"
#include "DateFormat.h"

#include <string>

using namespace std;

class TestDateFormat
{
  public:
    TestDateFormat(TestingTools &initTools);
    virtual ~TestDateFormat();

    void all();

    void paramConstructor();
    void setGetDate();
    void getMonthName();

  protected:

  private:
    TestingTools * tools;
};

#endif // TESTDATEFORMAT_H
