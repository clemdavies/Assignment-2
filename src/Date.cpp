#include "Date.h"
Date::~Date()
{
  clear();
}

bool Date::operator==(const Date& D) const
{
  bool isEqual = true;
  // check for self
  if (this == &D)return isEqual;

  if( year  != D.getYear()  ||
      month != D.getMonth() ||
      day   != D.getDay() )
    isEqual = false;

  return isEqual;
}

bool operator!=(const Date& LD,const Date& RD)
{
  return !(LD==RD);
}


bool Date::operator<(const Date& D) const
{
  if(year < D.year)
    return true;
  else if( year == D.year && month < D.month)
    return true;
  else if(year == D.year && month == D.month && day < D.day)
    return true;
  return  false;
}

void Date::clear()
{
  year = 1970;
  month = 1;
  day = 1;
  isLeap = false;
}

Date::Date()
{
  clear();
}

Date::Date( unsigned initDay, unsigned initMonth, unsigned initYear )
{
  clear();
  setYear(initYear);
  calculateIsLeap();
  setMonth(initMonth);
  setDay(initDay);
}

Date::Date(const Date& srcDate)
{
  day = srcDate.day;
  month = srcDate.month;
  year = srcDate.year;
  isLeap = srcDate.isLeap;
}

Date& Date::operator=(const Date& srcDate)
{
  if(this == &srcDate)
  {
    return *this;
  }
  day = srcDate.day;
  month = srcDate.month;
  year = srcDate.year;
  isLeap = srcDate.isLeap;

  return *this;
}


void Date::setDay( unsigned newDay )
{
  if(newDay == 0)
    day = 1;
  else if( isLeap && month == (unsigned)2 )
    day = ( newDay > daysInMonths[month-1]+1 ) ? daysInMonths[month-1]+1 : newDay;
  else
    day = ( newDay > daysInMonths[month-1] ) ? daysInMonths[month-1] : newDay;
}

unsigned Date::getDay() const
{
  return day;
}

void Date::setMonth( unsigned newMonth )
{
  unsigned oldMonth = month;
  if(newMonth == 0)
    month = 1;
  else
    month = ( newMonth > 12 ) ? 12 : newMonth;

  if(daysInMonths[month] != daysInMonths[oldMonth])
    setDay(day);
}

unsigned Date::getMonth() const
{
  return month;
}

void Date::setYear( unsigned newYear )
{
  year = newYear;
  bool wasLeap = isLeap;
  calculateIsLeap();
  if(wasLeap != isLeap && month == (unsigned)2)
    setDay(day);
}

unsigned Date::getYear() const
{
  return year;
}

void Date::calculateIsLeap()
{
  if (year%100 == 0 && year%400 != 0)
    isLeap = false;
  else
    isLeap = year%4 == 0;
}

std::ostream & operator << (std::ostream &output, const Date &D)
{
  output << D.getDay() << "/" << D.getMonth() << "/" << D.getYear();
  return output;
}
