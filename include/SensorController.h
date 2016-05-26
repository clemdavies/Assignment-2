#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include <iostream>
#include <fstream>

#include "SensorRecord.h"
#include "YearRecord.h"
#include "MonthRecord.h"
#include "DayRecord.h"

#include "Date.h"
//#include "DateTime.h"
//#include "DateFormat.h"


using namespace std;

  /**
   * @class SensorController
   * @brief Controls file I/O.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   */
class SensorController
{
  public:
      /**
       * @brief Constructor taking two cstrings for file IO operations.
       * @param The name of the index file to read.
       * @param The name of the output file to write to.
       */
    SensorController(const char * initIndexFileName,const char * initOutputFileName);

      /**
       * @brief The destructor.
       */
    virtual ~SensorController();

      /**
       * @brief Sets the input file name.
       * @param The name of the input file.
       */
    void setIndexFileName(const char * newIndexFileName);

      /**
       * @brief Retrieves the name of the input file.
       * @return The name of the input file.
       */
    const char * getIndexFileName() const;

      /**
       * @brief Sets the output file name.
       * @param The name of the output file.
       * @return
       */
    void setOutputFileName(const char * newOutputFileName);

      /**
       * @brief Retrieves the name of the output file.
       * @return The name of the output file.
       */
    const char * getOutputFileName() const;

      /**
       * @brief Processes the index file calling readInputFile for each file name inside.
       */
    void readInputFiles();

      /**
       * @brief Displays the maximum wind speed for given month in given year to screen.
       * @param The year to display for.
       * @param The month to display for.
       */
    void displayMaximumWindSpeed(unsigned year,unsigned month);

      /**
       * @brief Displays the average wind speed for each month in given year to screen.
       * @param The year to display for.
       */
    void displayAverageWindSpeed(unsigned year);

      /**
       * @brief Displays the total solar radiation for each month in given year to screen.
       * @param The year to display for.
       */
    void displayTotalSolarRadiation(unsigned year);

      /**
       * @brief Prints the average wind speed and total solar radiation for each month in given year to outputFile.
       * @param The year to display.
       */
    void printAverageWindSpeedAndTotalSolarRadiation(unsigned year);

      /**
       * @brief Displays the peak solar radiation value in W/m^2 with list of times occurred.
       * @param The day to retrieve peak solar radiation for.
       */
    void displayPeakSolarRadiationTimes(Date date);


  protected:
  private:

      /**
       * @brief Processes the input file and stores records into objects.
       * @param The path to the input file to read.
       */
    void readInputFile(const char * inputFileName);

      /**
       * @brief Default constructor.
       */
    SensorController();

      /**
       * @brief Container object that holds all TimeRecord ,DayRecord, MonthRecord, and YearRecord objects.
       */
    SensorRecord sensorRecords;

      /**
       * @brief The path to the index file.
       */
    const char * indexFileName;

      /**
       * @brief The path to the output file.
       */
    const char * outputFileName;
};

#endif // SENSORCONTROLLER_H
