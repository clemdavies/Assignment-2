#include "TestDateTime.h"

TestDateTime::TestDateTime(TestingTools &initTools)
{
  tools = &initTools;
  tools->setClassName("DateTime");
}

TestDateTime::~TestDateTime()
{
  //dtor
}


void TestDateTime::all()
{
  objectParamConstructor();
  primitiveParamConstructor();
  setGetDate();
  setGetTime();
  assignmentOperator();
}

void TestDateTime::objectParamConstructor()
{
  tools->setFunctionName("objectParamConstructor");
  {
    Date date;
    Time time;
    DateTime instance(date,time);
    tools->assertEquals(instance.getDate()->getYear(),date.getYear());
    tools->assertEquals(instance.getDate()->getMonth(),date.getMonth());
    tools->assertEquals(instance.getDate()->getDay(),date.getDay());
    tools->assertEquals(instance.getTime()->getHour(),time.getHour());
    tools->assertEquals(instance.getTime()->getMinute(),time.getMinute());
    tools->assertEquals(instance.getTime()->getSecond(),time.getSecond());
  }
  {
    Date date(21,4,2016);
    Time time(8,25,33);
    DateTime instance(date,time);
    tools->assertEquals(instance.getDate()->getYear(),date.getYear());
    tools->assertEquals(instance.getDate()->getMonth(),date.getMonth());
    tools->assertEquals(instance.getDate()->getDay(),date.getDay());
    tools->assertEquals(instance.getTime()->getHour(),time.getHour());
    tools->assertEquals(instance.getTime()->getMinute(),time.getMinute());
    tools->assertEquals(instance.getTime()->getSecond(),time.getSecond());
  }


}
void TestDateTime::primitiveParamConstructor()
{
  tools->setFunctionName("primitiveParamConstructor");
  {
    unsigned ye = 2016,
             mo = 4,
             da = 21,
             ho = 8,
             mi = 26,
             se = 34;

    DateTime instance(21,4,2016,8,26,34);
    tools->assertEquals(instance.getDate()->getYear(),ye);
    tools->assertEquals(instance.getDate()->getMonth(),mo);
    tools->assertEquals(instance.getDate()->getDay(),da);
    tools->assertEquals(instance.getTime()->getHour(),ho);
    tools->assertEquals(instance.getTime()->getMinute(),mi);
    tools->assertEquals(instance.getTime()->getSecond(),se);
  }
  {
    unsigned ye = 1970,
             mo = 1,
             da = 1,
             ho = 0,
             mi = 0,
             se = 0;

    DateTime instance(1,1,1970,0,0,0);
    tools->assertEquals(instance.getDate()->getYear(),ye);
    tools->assertEquals(instance.getDate()->getMonth(),mo);
    tools->assertEquals(instance.getDate()->getDay(),da);
    tools->assertEquals(instance.getTime()->getHour(),ho);
    tools->assertEquals(instance.getTime()->getMinute(),mi);
    tools->assertEquals(instance.getTime()->getSecond(),se);
  }


}

void TestDateTime::setGetDate()
{
  tools->setFunctionName("setGetDate");
  {
    unsigned ye = 1970,
             mo = 1,
             da = 1,
             ho = 0;
    Date date;
    Time time;
    DateTime instance(date,time);

    tools->assertEquals(instance.getDate()->getYear(),ye);
    tools->assertEquals(instance.getDate()->getMonth(),mo);
    tools->assertEquals(instance.getDate()->getDay(),da);
    tools->assertEquals(instance.getTime()->getHour(),ho);
  }
  {
    unsigned ye = 2016,
             mo = 4,
             da = 21;
    Date d1;
    Time t1;
    Date date(21,4,2016);
    DateTime instance(d1,t1);
    instance.setDate(date);

    tools->assertEquals(instance.getDate()->getYear(),ye);
    tools->assertEquals(instance.getDate()->getMonth(),mo);
    tools->assertEquals(instance.getDate()->getDay(),da);
  }


}

void TestDateTime::setGetTime()
{
  tools->setFunctionName("setGetTime");
  {
    unsigned ho = 12,
             mi = 33,
             se = 56;

    Date d1;
    Time t1;
    Time time(12,33,56);
    DateTime instance(d1,t1);
    instance.setTime(time);

    tools->assertEquals(instance.getTime()->getHour(),ho);
    tools->assertEquals(instance.getTime()->getMinute(),mi);
    tools->assertEquals(instance.getTime()->getSecond(),se);
  }


}

void TestDateTime::assignmentOperator()
{
  tools->setFunctionName("assignOp");
  {
    unsigned ye = 2016,
             mo = 12,
             da = 4,
             ho = 17,
             mi = 9,
             se = 44;

    DateTime datetime(da,mo,ye,ho,mi,se);
    DateTime instance = datetime;

    tools->assertEquals(instance.getDate()->getYear(),ye);
    tools->assertEquals(instance.getDate()->getMonth(),mo);
    tools->assertEquals(instance.getDate()->getDay(),da);
    tools->assertEquals(instance.getTime()->getHour(),ho);
    tools->assertEquals(instance.getTime()->getMinute(),mi);
    tools->assertEquals(instance.getTime()->getSecond(),se);
  }

}
