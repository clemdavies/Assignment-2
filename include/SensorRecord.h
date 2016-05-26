#ifndef SENSORRECORD_H
#define SENSORRECORD_H

#include <map>
#include "YearRecord.h"
#include "DateTime.h"

class SensorRecord
{
  public:
    SensorRecord();
    virtual ~SensorRecord();

    void addSolarRadiation(const DateTime &datetime,const float sr);
    void addWindSpeed(const Date &date,const float ws);

  private:
    std::map<unsigned,YearRecord*> records;
};

#endif // SENSORRECORD_H
