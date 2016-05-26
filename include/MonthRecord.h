#ifndef MONTHRECORD_H
#define MONTHRECORD_H

#include <map>
#include "DayRecord.h"
#include "DateTime.h"


class MonthRecord
{
  public:
    MonthRecord();
    virtual ~MonthRecord();

    void addSolarRadiation(const DateTime &datetime,const float sr);
    void addWindSpeed(const Date &date,const float ws);

    float getMaximumWindSpeed();
    float getAverageWindSpeed();
    int getTotalSolarRadiation();

  private:
    std::map<unsigned,DayRecord*> records;
    float maximumWindSpeed;
    float averageWindSpeed;
    int totalSolarRadiation;
};

#endif // MONTHRECORD_H
