#ifndef DATEFORMAT_H
#define DATEFORMAT_H

#include "string"

#include "Date.h"

  /**
   * @class DateFormat
   * @brief Formats a Date object for output.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   */
class DateFormat
{
  public:

      /** @brief Creates a DateFormat object for using with Date parameter.
       * @param Date object reference.
       */
    DateFormat(const Date &initDate);

      /** @brief Destructor does not destroy anything.
       */
    virtual ~DateFormat();

      /** @brief Determines the name of the month from the month value.
       * @param Boolean value of whether to abbreviate the return value.
       * @return The name of the month.
       */
    std::string getMonthName( bool abbreviated = false );

      /** @brief Stores a pointer to the Date object.
       * @param The Date object reference.
       */
    void setDate(const Date &date);

      /** @brief Returns the Date object pointer.
       * @return The Date object pointer.
       */
    const Date *getDate() const;

  protected:
  private:
      /** @brief Default constructor for DateFormat.
       */
    DateFormat();

    /** @brief Pointer of Date object to format.
     */
    const Date *date;

      /** @brief Array of names for each month.
       */
    const std::string months[12] = {"January",
                                    "February",
                                    "March",
                                    "April",
                                    "May",
                                    "June",
                                    "July",
                                    "August",
                                    "September",
                                    "October",
                                    "November",
                                    "December"};
};

#endif // DATEFORMAT_H
