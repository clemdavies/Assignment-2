#include "DateFormat.h"

DateFormat::DateFormat()
{

}

DateFormat::~DateFormat()
{
  //dtor
}
DateFormat::DateFormat(const Date &initDate)
{
  date = &initDate;
}

void DateFormat::setDate(const Date &newDate)
{
  date = &newDate;
}

const Date *DateFormat::getDate() const
{
  return date;
}


std::string DateFormat::getMonthName( bool abbreviated )
{
  std::string monthName = months[date->getMonth()-1];
  if( abbreviated )
  {
    monthName = monthName.substr(0,3);
  }

  return monthName;
}

