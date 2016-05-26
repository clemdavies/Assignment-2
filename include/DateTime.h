#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"
#include "Time.h"

#include <ostream>

  /**
   * @class DateTime
   * @brief Stores a Date object and Time object.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   */
class DateTime
{
  public:

      /** @brief Default Constructor
       */
    DateTime();

      /** @brief Sets value of DateTime.
       * @param Date object.
       * @param Time object.
       */
    DateTime(Date &initDate,Time &initTime);

      /** @brief Sets value of DateTime.
       * @param Initial value for day.
       * @param Initial value for month.
       * @param Initial value for year.
       * @param Initial value for hour.
       * @param Initial value for minute.
       * @param Initial value for second.
       */
    DateTime(unsigned initDay, unsigned initMonth, unsigned initYear, unsigned initHour, unsigned initMinute, unsigned initSecond);

      /** @brief Copies DateTime object.
       * @param Reference to DateTime object to copy from.
       */
    DateTime(const DateTime &srcDT);

      /** @brief Copies DateTime object using the assignment operator.
       * @param Reference to DateTime object to copy from.
       * @return Reference to newly created DateTime object.
       */
    DateTime& operator=(const DateTime &srcDT);

      /** @brief Destroys Date and Time object.
       */
    virtual ~DateTime();

      /** @brief sets value of Date.
       * @param new value for Date.
       */
    void setDate(Date &newDate);

      /** @brief gets pointer of Date.
       * @return pointer for Date.
       */
    const Date* getDate() const;

      /** @brief sets value of time.
       * @param new value for time.
       */
    void setTime(Time &newTime);

      /** @brief gets pointer of time.
       * @return pointer for time.
       */
    const Time* getTime() const;

    bool operator==(const DateTime& DT);

  protected:
  private:

      /** @brief Pointer to Date object.
       */
    Date *date;

      /** @brief Pointer to Time object.
       */
    Time *time;
};

std::ostream & operator << (std::ostream &output, DateTime &DT);

#endif // DATETIME_H
