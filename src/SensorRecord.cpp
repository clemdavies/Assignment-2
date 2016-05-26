#include "SensorRecord.h"

SensorRecord::SensorRecord()
{
  //ctor
}

SensorRecord::~SensorRecord()
{
  //dtor
}


void SensorRecord::addSolarRadiation(const DateTime &datetime,const float sr)
{
  if(records.count(datetime.getDate()->getYear()) <= 0)
    records[datetime.getDate()->getYear()] = new YearRecord();

  records[datetime.getDate()->getYear()]->addSolarRadiation(datetime,sr);
}

void SensorRecord::addWindSpeed(const Date &date,const float ws)
{
  if(records.count(date.getYear()) <= 0)
    records[date.getYear()] = new YearRecord();

  records[date.getYear()]->addWindSpeed(date,ws);
}
