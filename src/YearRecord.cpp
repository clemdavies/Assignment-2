#include "YearRecord.h"

YearRecord::YearRecord()
{
  //ctor
}

YearRecord::~YearRecord()
{
  //dtor
}

void YearRecord::addSolarRadiation(const Date &date,const Time &time,const float sr)
{
  if(records.count(date.getMonth()) <= 0)
    records[date.getMonth()] = new MonthRecord();

  records[date.getMonth()]->addSolarRadiation(date,time,sr);
}

void YearRecord::addWindSpeed(const Date &date,const Time &time,const float sr)
{

}
