#include "Time.h"

Time::Time()
{
  hour = 0;
  minute = 0;
  second = 0;
}

Time::Time(unsigned initHour,unsigned initMinute, unsigned initSecond)
{
  setHour(initHour);
  setMinute(initMinute);
  setSecond(initSecond);
}

Time::~Time()
{
  //dtor
}

bool Time::operator==(const Time& T) const
{
  bool isEqual = true;
  // check for self
  if (this == &T)return isEqual;

  if( hour   != T.getHour()   ||
      minute != T.getMinute() ||
      second != T.getSecond() )
    isEqual = false;

  return isEqual;
}

bool operator!=(const Time& LT,const Time& RT)
{
  return !(LT==RT);
}

void Time::setHour(unsigned newHour)
{
  hour = (newHour > 23) ? 23 : newHour;
}
unsigned Time::getHour() const
{
  return hour;
}

void Time::setMinute(unsigned newMinute)
{
  minute = (newMinute > 59) ? 59 : newMinute;
}
unsigned Time::getMinute() const
{
  return minute;
}

void Time::setSecond(unsigned newSecond)
{
  second = (newSecond > 59) ? 59 : newSecond;
}
unsigned Time::getSecond() const
{
  return second;
}

std::ostream & operator << (std::ostream &output, const Time &T)
{
  output << T.getHour() << ":" << T.getMinute() << ":" << T.getSecond();
  return output;
}
