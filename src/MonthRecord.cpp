#include "MonthRecord.h"

MonthRecord::MonthRecord()
{
  //ctor
}

MonthRecord::~MonthRecord()
{
  //dtor
}

void MonthRecord::addSolarRadiation(const Date &date,const Time &time,const float sr)
{
  if(records.count(date.getDay())<=0)
    records[date.getDay()] = new DayRecord();

  records[date.getDay()]->addSolarRadiation(time,sr);
}

void MonthRecord::addWindSpeed(const Date &date,const Time &time,const float sr)
{

}
