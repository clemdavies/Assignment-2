#include "TestTime.h"

TestTime::TestTime(TestingTools &initTools)
{
  tools = &initTools;
  tools->setClassName("Time");
}

TestTime::~TestTime()
{
  //dtor
}


void TestTime::all()
{
  emptyConstructor();
  paramConstructor();
  setGetHour();
  setGetMinute();
  setGetSecond();
  assignmentOperator();
}

void TestTime::emptyConstructor()
{
  tools->setFunctionName("emptyConstructor");
    unsigned u1 = 0;
  {
    Time instance;
    tools->assertEquals(instance.getHour(),u1);
    tools->assertEquals(instance.getMinute(),u1);
    tools->assertEquals(instance.getSecond(),u1);
  }


}
void TestTime::paramConstructor()
{
  tools->setFunctionName("paramConstructor");
  {
    unsigned u1 = 0;
    Time instance(u1,u1,u1);
    tools->assertEquals(instance.getHour(),u1);
    tools->assertEquals(instance.getMinute(),u1);
    tools->assertEquals(instance.getSecond(),u1);
  }
  {
    unsigned u1 = 10;
    unsigned u2 = 20;
    unsigned u3 = 30;
    Time instance(u1,u2,u3);
    tools->assertEquals(instance.getHour(),u1);
    tools->assertEquals(instance.getMinute(),u2);
    tools->assertEquals(instance.getSecond(),u3);
  }
  {
    unsigned u1 = 60;
    unsigned u2 = 23;
    unsigned u3 = 59;
    Time instance(u1,u1,u1);
    tools->assertEquals(instance.getHour(),u2);
    tools->assertEquals(instance.getMinute(),u3);
    tools->assertEquals(instance.getSecond(),u3);
  }
  {
    unsigned u1 = 23;
    unsigned u2 = 59;
    Time instance(u1,u2,u2);
    tools->assertEquals(instance.getHour(),u1);
    tools->assertEquals(instance.getMinute(),u2);
    tools->assertEquals(instance.getSecond(),u2);
  }
}
void TestTime::setGetHour()
{
  tools->setFunctionName("setGetHour");
  {
    unsigned u1 = 0;
    unsigned u2 = 12;
    unsigned u3 = 23;
    unsigned u4 = 24;
    Time instance;
    instance.setHour(u1);
    tools->assertEquals(instance.getHour(),u1);
    instance.setHour(u2);
    tools->assertEquals(instance.getHour(),u2);
    instance.setHour(u3);
    tools->assertEquals(instance.getHour(),u3);
    instance.setHour(u4);
    tools->assertEquals(instance.getHour(),u3);
  }


}
void TestTime::setGetMinute()
{
  tools->setFunctionName("setGetMinute");
  {
    unsigned u1 = 0;
    unsigned u2 = 10;
    unsigned u3 = 59;
    unsigned u4 = 60;
    Time instance;
    instance.setMinute(u1);
    tools->assertEquals(instance.getMinute(),u1);
    instance.setMinute(u2);
    tools->assertEquals(instance.getMinute(),u2);
    instance.setMinute(u3);
    tools->assertEquals(instance.getMinute(),u3);
    instance.setMinute(u4);
    tools->assertEquals(instance.getMinute(),u3);
  }


}
void TestTime::setGetSecond()
{
  tools->setFunctionName("setGetSecond");
  {
    unsigned u1 = 0;
    unsigned u2 = 10;
    unsigned u3 = 59;
    unsigned u4 = 60;
    Time instance;
    instance.setSecond(u1);
    tools->assertEquals(instance.getSecond(),u1);
    instance.setSecond(u2);
    tools->assertEquals(instance.getSecond(),u2);
    instance.setSecond(u3);
    tools->assertEquals(instance.getSecond(),u3);
    instance.setSecond(u4);
    tools->assertEquals(instance.getSecond(),u3);
  }
}

void TestTime::assignmentOperator()
{
  tools->setFunctionName("assignmentOp");
  {
    unsigned t1 = 23,
             t2 = 12,
             t3 = 58;
    Time time(t1,t2,t3);
    Time instance = time;

    tools->assertEquals(instance.getHour(),t1);
    tools->assertEquals(instance.getMinute(),t2);
    tools->assertEquals(instance.getSecond(),t3);


  }
}
