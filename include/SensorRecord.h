#ifndef SENSORRECORD_H
#define SENSORRECORD_H

#include <map>
#include "YearRecord.h"
#include "Date.h"
#include "Time.h"

class SensorRecord
{
  public:
    SensorRecord();
    virtual ~SensorRecord();

    void addSolarRadiation(const Date &date,const Time &time,const float sr);
    void addWindSpeed(const Date &date,const Time &time,const float ws);

  private:
    std::map<unsigned,YearRecord*> records;
};

#endif // SENSORRECORD_H
