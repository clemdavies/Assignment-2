#ifndef YEARRECORD_H
#define YEARRECORD_H

#include <map>
#include "MonthRecord.h"
#include "DateTime.h"

class YearRecord
{
  public:
    YearRecord();
    virtual ~YearRecord();

    void addSolarRadiation(const DateTime &datetime,const float sr);
    void addWindSpeed(const Date &date,const float ws);

  private:
    std::map<unsigned,MonthRecord*> records;
};


#endif // YEARRECORD_H
