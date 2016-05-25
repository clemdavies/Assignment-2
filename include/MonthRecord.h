#ifndef MONTHRECORD_H
#define MONTHRECORD_H

#include <map>
#include "DayRecord.h"
#include "Date.h"
#include "Time.h"


class MonthRecord
{
  public:
    MonthRecord();
    virtual ~MonthRecord();

    void addSolarRadiation(const Date &date,const Time &time,const float sr);
    void addWindSpeed(const Date &date,const Time &time,const float sr);

  private:
    std::map<unsigned,DayRecord*> records;
};

#endif // MONTHRECORD_H
