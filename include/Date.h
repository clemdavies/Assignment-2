#ifndef DATE_H
#define DATE_H

#include <ostream>

  /**
   * @class Date
   * @brief Stores a date from day month year.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   */
class Date
{
  public:
      /** @brief Constructs Date object setting day/month/year to 1/1/1970
       */
    Date();

      /** @brief Constructs Date object using params as values for day, month, year.
       *  @param unsigned value for day
       *  @param unsigned value for month
       *  @param unsigned value for year
       */
    Date( unsigned initDay, unsigned initMonth, unsigned initYear );

      /** @brief Destructor for Date object.
       */
    virtual ~Date();

    bool operator==(const Date& D) const;
    bool operator<(const Date& D) const;

      /** @brief Copy constructor, creates a copy of a Date object.
       *  @param Date object to copy from.
       */
    Date(const Date& srcDate);

      /** @brief Assignment Copy, assigns a copy of Date object.
       * @param Date object to copy from.
       * @return Newly created date object.
       */
    Date& operator=(const Date& srcDate);

      /** @brief returns value for day.
       * @return Value of day.
       */
    unsigned getDay() const;

      /** @brief returns value of month.
       * @return value of month.
       */
    unsigned getMonth() const;

      /** @brief returns value of year.
       * @return value of year.
       */
    unsigned getYear() const;

      /** @brief sets value of day.
       * @param new day value.
       */
    void setDay( unsigned newDay );

      /** @brief sets value of month.
       * @param new value of month
       */
    void setMonth( unsigned newMonth );

      /** @brief sets value of year.
       * @param new value for year.
       */
    void setYear( unsigned newYear );



  protected:
  private:

    /** @brief Sets member variables to initial values.
     */
    void clear();

    /** @brief Determines if the current year is a leap year or not, stores result in isLeap.
     */
    void calculateIsLeap();

      /** @brief The day of the month.
       */
    unsigned day;

      /** @brief The month of the year.
       */
    unsigned month;

      /** @brief The year.
       */
    unsigned year;

      /** @brief Boolean value if current year is leap year or not.
        */
    bool isLeap;

      /** @brief Array of number of days in each month, leap year exclusive.
       */
    const unsigned daysInMonths[12] = {31,
                                       28,
                                       31,
                                       30,
                                       31,
                                       30,
                                       31,
                                       31,
                                       30,
                                       31,
                                       30,
                                       31};

};

std::ostream & operator << (std::ostream &output, const Date &D);

bool operator!=(const Date& LD, const Date& RD);

#endif // DATE_H
