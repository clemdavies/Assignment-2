#ifndef TIME_H
#define TIME_H

#include <ostream>

  /**
   * @class Time
   * @brief Stores a 24hr representation of time.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   */
class Time
{
  public:

      /** @brief Creates a new Time object, setting hour,minute,second to 0;
       */
    Time();

      /** @brief Creates a new Time object, setting hour,minute,second to parameters.
       *  @param Initial Hour value to store
       *  @param Initial Minute value to store
       *  @param Initial Second value to store
       */
    Time(unsigned initHour,unsigned initMinute, unsigned initSecond);

      /** @brief Destroys Time object.
       */
    virtual ~Time();

    bool operator==(const Time& T) const;

      /** @brief Stores value in Hour.
       *  @param New Hour value to store
       */
    void setHour(unsigned newHour);

      /** @brief Returns stored value for Hour.
       *  @return Value of Hour.
       */
    unsigned getHour() const;


      /** @brief Stores value in Minute.
       *  @param New Minute value to store
       */
    void setMinute(unsigned newMinute);

      /** @brief Returns stored value for Minute.
       *  @return Value of Minute.
       */
    unsigned getMinute() const;


      /** @brief Stores value in Second.
       *  @param New Second value to store
       */
    void setSecond(unsigned newSecond);

      /** @brief Returns stored value for Second.
       *  @return Value of Second.
       */
    unsigned getSecond() const;

  protected:

  private:
      /** @brief Stores value of Hour, from 0-23.
       */
    unsigned hour;

      /** @brief Stores value of Minute, from 0-59.
       */
    unsigned minute;

      /** @brief Stores value of Second, from 0-59.
       */
    unsigned second;

};

std::ostream & operator << (std::ostream &output, const Time &T);

bool operator!=(const Time& LT,const Time& RT);

#endif // TIME_H
