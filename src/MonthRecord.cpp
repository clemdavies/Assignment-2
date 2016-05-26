#include "MonthRecord.h"

MonthRecord::MonthRecord()
{
  //ctor
}

MonthRecord::~MonthRecord()
{
  //dtor
}

void MonthRecord::addSolarRadiation(const DateTime &datetime,const float sr)
{
  if(records.count(datetime.getDate()->getDay())<=0)
    records[datetime.getDate()->getDay()] = new DayRecord();

  records[datetime.getDate()->getDay()]->addSolarRadiation(*(datetime.getTime()),sr);
}

void MonthRecord::addWindSpeed(const Date &date,const float ws)
{
  // store windspeed at month

}
