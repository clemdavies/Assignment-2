#include "DayRecord.h"

DayRecord::DayRecord()
{
  //ctor
}

DayRecord::~DayRecord()
{
  //dtor
}

void DayRecord::addSolarRadiation(const Time &time,const float sr)
{
  cout << time <<  " : " << sr << endl;
}

void DayRecord::addWindSpeed(const Time &time,const float ws)
{

}
