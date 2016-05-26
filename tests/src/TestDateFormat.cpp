#include "TestDateFormat.h"

TestDateFormat::TestDateFormat(TestingTools &initTools)
{
  tools = &initTools;
  tools->setClassName("DateFormat");
}

TestDateFormat::~TestDateFormat()
{
  //dtor
}


void TestDateFormat::all()
{
  paramConstructor();
  setGetDate();
  getMonthName();
}

void TestDateFormat::paramConstructor()
{
  tools->setFunctionName("paramConstructor");
  {
    Date date;
    DateFormat instance(date);
    tools->assertTypeEquals(*instance.getDate(),date);
    tools->assertEquals(instance.getDate()->getMonth(),date.getMonth());
    tools->assertEquals(instance.getMonthName(),string("January"));
  }
  {
    Date date(10,6,1998);
    DateFormat instance(date);
    tools->assertEquals(instance.getDate()->getMonth(),date.getMonth());
    tools->assertEquals(instance.getMonthName(),string("June"));
  }
}

void TestDateFormat::setGetDate()
{
  tools->setFunctionName("setGetDate");
  {
    Date date;
    DateFormat instance(date);

    tools->assertEquals(instance.getDate()->getYear(),date.getYear());
    tools->assertEquals(instance.getDate()->getMonth(),date.getMonth());
    tools->assertEquals(instance.getDate()->getDay(),date.getDay());
  }


}

void TestDateFormat::getMonthName()
{

  tools->setFunctionName("getMonthName");
  {
    Date date;
    DateFormat instance(date);
    string january = "January";
    string jan = "Jan";
    tools->assertEquals(instance.getMonthName(), january );
    tools->assertEquals(instance.getMonthName(true), jan );
  }
  {
    Date date;
    date.setMonth(2);
    DateFormat instance(date);

    tools->assertEquals(instance.getMonthName(), string("February") );
    tools->assertEquals(instance.getMonthName(true), string("Feb") );

    date.setMonth(10);
    tools->assertEquals(instance.getMonthName(), string("October") );
    tools->assertEquals(instance.getMonthName(true), string("Oct") );
  }

}


