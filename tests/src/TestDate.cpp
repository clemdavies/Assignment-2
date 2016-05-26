#include "TestDate.h"

TestDate::TestDate(TestingTools& initTools)
{
  tools = &initTools;
  tools->setClassName("Date");
}

TestDate::~TestDate()
{

}


void TestDate::all()
{
  emptyConstructor();
  paramConstructor();
  copyConstructor();
  setGetDay();
  setGetMonth();
  setGetYear();
  assignmentOperator();
}

void TestDate::emptyConstructor()
{
  tools->setFunctionName("emptyConstructor");

  {
    Date instance;
    instance.getDay();

    tools->assertEquals(instance.getDay(),(unsigned)1);
    tools->assertEquals(instance.getMonth(),(unsigned)1);
    tools->assertEquals(instance.getYear(),(unsigned)1970);
  }

}

void TestDate::paramConstructor()
{
  tools->setFunctionName("paramConstructor");

  {
    Date instance(1,1,1970);
    tools->assertEquals(instance.getDay(),(unsigned)1);
    tools->assertEquals(instance.getMonth(),(unsigned)1);
    tools->assertEquals(instance.getYear(),(unsigned)1970);
  }
  {
    Date instance(31,12,2014);
    tools->assertEquals(instance.getDay(),(unsigned)31);
    tools->assertEquals(instance.getMonth(),(unsigned)12);
    tools->assertEquals(instance.getYear(),(unsigned)2014);
  }
  {
    Date instance(31,2,2008);
    tools->assertEquals(instance.getDay(),(unsigned)29);
    tools->assertEquals(instance.getMonth(),(unsigned)2);
    tools->assertEquals(instance.getYear(),(unsigned)2008);
  }
  {
    Date instance(31,2,2007);
    tools->assertEquals(instance.getDay(),(unsigned)28);
    tools->assertEquals(instance.getMonth(),(unsigned)2);
    tools->assertEquals(instance.getYear(),(unsigned)2007);
  }
  {
    Date instance(200,1,1955);
    tools->assertEquals(instance.getDay(),(unsigned)31);
    tools->assertEquals(instance.getMonth(),(unsigned)1);
    tools->assertEquals(instance.getYear(),(unsigned)1955);
  }
  {
    Date instance(36,2,2008);
    tools->assertEquals(instance.getDay(),(unsigned)29);
    tools->assertEquals(instance.getMonth(),(unsigned)2);
    tools->assertEquals(instance.getYear(),(unsigned)2008);
  }

}

void TestDate::copyConstructor()
{
  tools->setFunctionName("copyConstructor");
  {
    Date instance1;
    Date instance2(instance1);
    tools->assertEquals(instance1.getDay(),instance2.getDay());
    tools->assertEquals(instance1.getMonth(),instance2.getMonth());
    tools->assertEquals(instance1.getYear(),instance2.getYear());
  }
  {
    Date instance1(36,2,2008);
    Date instance2(instance1);
    tools->assertEquals(instance1.getDay(),instance2.getDay());
    tools->assertEquals(instance1.getMonth(),instance2.getMonth());
    tools->assertEquals(instance1.getYear(),instance2.getYear());
  }
}

void TestDate::setGetDay()
{
  tools->setFunctionName("setGetDay");

  {
    Date instance;
    tools->assertEquals(instance.getDay(),(unsigned)1);
  }

  {
    Date instance;
    instance.setDay(5);
    tools->assertEquals(instance.getDay(),(unsigned)5);
  }

  {
    Date instance;
    instance.setDay(36);
    tools->assertEquals(instance.getDay(),(unsigned)31);
    instance.setMonth(2);
    tools->assertEquals(instance.getDay(),(unsigned)28);
    instance.setYear(2008);
    tools->assertEquals(instance.getDay(),(unsigned)28);
    instance.setDay(36);
    tools->assertEquals(instance.getDay(),(unsigned)29);
    instance.setYear(2009);
    tools->assertEquals(instance.getDay(),(unsigned)28);
  }

  {
    Date instance;
    instance.setDay(15);
    instance.setMonth(2);
    tools->assertEquals(instance.getDay(),(unsigned)15);
    instance.setYear(2008);
    tools->assertEquals(instance.getDay(),(unsigned)15);
  }

}

void TestDate::setGetMonth()
{
  tools->setFunctionName("setGetMonth");

  {
    Date instance;
    tools->assertEquals(instance.getMonth(),(unsigned)1);
    instance.setMonth(5);
    tools->assertEquals(instance.getMonth(),(unsigned)5);
    instance.setMonth(13);
    tools->assertEquals(instance.getMonth(),(unsigned)12);
    instance.setMonth(0);
    tools->assertEquals(instance.getMonth(),(unsigned)1);
  }

}

void TestDate::setGetYear()
{
  tools->setFunctionName("setGetYear");

  {
    Date instance;
    tools->assertEquals(instance.getYear(),(unsigned)1970);
    instance.setYear(2008);
    tools->assertEquals(instance.getYear(),(unsigned)2008);
  }

  {
    Date instance(28,2,2007);
    tools->assertEquals(instance.getYear(),(unsigned)2007);
  }

}

void TestDate::assignmentOperator()
{
  tools->setFunctionName("assignmentOp");
  {
    Date date;
    Date instance = date;
    unsigned t1 = 1970,
             t2 = 1;
    tools->assertEquals(instance.getYear(),t1);
    tools->assertEquals(instance.getMonth(),t2);
    tools->assertEquals(instance.getDay(),t2);
  }
  {
    unsigned t1 = 2016,
             t2 = 4,
             t3 = 21;
    Date date(t3,t2,t1);
    Date instance = date;
    tools->assertEquals(instance.getYear(),t1);
    tools->assertEquals(instance.getMonth(),t2);
    tools->assertEquals(instance.getDay(),t3);
  }
}

