#ifndef YEARRECORD_H
#define YEARRECORD_H

#include <map>
#include "MonthRecord.h"
#include "Date.h"
#include "Time.h"

class YearRecord
{
  public:
    YearRecord();
    virtual ~YearRecord();

    void addSolarRadiation(const Date &date,const Time &time,const float sr);
    void addWindSpeed(const Date &date,const Time &time,const float sr);

  private:
    std::map<unsigned,MonthRecord*> records;
};

#endif // YEARRECORD_H
