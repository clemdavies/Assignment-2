#include "DateTime.h"

DateTime::DateTime()
{
  date = new Date();
  time = new Time();
}

DateTime::~DateTime()
{
  delete date;
  delete time;
}

bool DateTime::operator==(const DateTime& DT)
{
  bool isEqual = true;
  if(this == &DT)return isEqual;

  if(*date != *(DT.getDate()) ||
     *time != *(DT.getTime()) )
    isEqual = false;

  return isEqual;
}


DateTime::DateTime(Date &initDate,Time &initTime)
{
  date = new Date(initDate);
  time = new Time(initTime);
}

DateTime::DateTime(unsigned initDay, unsigned initMonth, unsigned initYear, unsigned initHour, unsigned initMinute, unsigned initSecond)
{
  date = new Date(initDay,initMonth,initYear);
  time = new Time(initHour,initMinute,initSecond);
}
DateTime::DateTime(const DateTime &srcDT)
{
  date = new Date(*srcDT.date);
  time = new Time(*srcDT.time);
}

DateTime& DateTime::operator=(const DateTime &srcDT)
{
  if(this == &srcDT)
    return *this;

  date = new Date(*srcDT.date);
  time = new Time(*srcDT.time);

  return *this;
}

void DateTime::setDate(Date &newDate)
{
  delete date;
  date = new Date(newDate);
}

const Date* DateTime::getDate() const
{
  return date;
}

void DateTime::setTime(Time &newTime)
{
  delete time;
  time = new Time(newTime);
}

const Time* DateTime::getTime() const
{
  return time;
}


std::ostream & operator << (std::ostream &output, DateTime &DT)
{
  output << (*(DT.getDate())) << " " << (*(DT.getTime()));
  return output;
}
