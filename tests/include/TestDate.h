#ifndef TESTDATE_H
#define TESTDATE_H

#include "TestingTools.h"

#include "Date.h"

  /**
   * @class TestDate
   * @brief unit tests the Date class using TestingTools.
   *
   * @author Clem Davies
   * @version 01
   * @date 07/04/2016
   *
   */
class TestDate
{
  public:
    TestDate(TestingTools &initTools);
    virtual ~TestDate();

    void all();

    void emptyConstructor();
    void paramConstructor();
    void copyConstructor();
    void setGetDay();
    void setGetMonth();
    void setGetYear();

    void assignmentOperator();

  protected:
  private:
    TestingTools * tools;
};

#endif // TESTDATE_H
