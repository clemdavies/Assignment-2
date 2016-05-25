#include "SensorRecord.h"

SensorRecord::SensorRecord()
{
  //ctor
}

SensorRecord::~SensorRecord()
{
  //dtor
}


void SensorRecord::addSolarRadiation(const Date &date,const Time &time,const float sr)
{
  if(records.count(date.getYear()) <= 0)
    records[date.getYear()] = new YearRecord();

  records[date.getYear()]->addSolarRadiation(date,time,sr);
}

void SensorRecord::addWindSpeed(const Date &date,const Time &time,const float sr)
{

}
