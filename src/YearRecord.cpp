#include "YearRecord.h"

YearRecord::YearRecord()
{
  //ctor
}

YearRecord::~YearRecord()
{
  //dtor
}

void YearRecord::addSolarRadiation(const DateTime &datetime,const float sr)
{
  if(records.count(datetime.getDate()->getMonth()) <= 0)
    records[datetime.getDate()->getMonth()] = new MonthRecord();

  records[datetime.getDate()->getMonth()]->addSolarRadiation(datetime,sr);
}

void YearRecord::addWindSpeed(const Date &date,const float ws)
{
  if(records.count(date.getMonth()) <= 0)
    records[date.getMonth()] = new MonthRecord();

  records[date.getMonth()]->addWindSpeed(date,ws);
}
