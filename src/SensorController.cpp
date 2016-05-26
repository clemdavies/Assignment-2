#include "SensorController.h"


SensorController::SensorController(const char * initIndexFileName,const char * initOutputFileName)
{
  indexFileName = initIndexFileName;
  outputFileName = initOutputFileName;
}

SensorController::~SensorController(){}

void SensorController::setIndexFileName(const char * newIndexFileName)
{
  indexFileName = newIndexFileName;
}

const char * SensorController::getIndexFileName() const
{
  return indexFileName;
}

void SensorController::setOutputFileName(const char * newOutputFileName)
{
  outputFileName = newOutputFileName;
}

const char * SensorController::getOutputFileName() const
{
  return outputFileName;
}

void SensorController::readInputFiles()
{
  ifstream indexFile( indexFileName );
  if(!indexFile) return;
  char ch_input[200];
  const char * inputFileName;
  while(indexFile.peek() != EOF)
  {
    indexFile.getline(ch_input,200,'\n');
    inputFileName = ch_input;
    readInputFile(inputFileName);
  }
}


void SensorController::readInputFile(const char * inputFileName)
{

  cout << inputFileName << endl;
  ifstream inFile ( inputFileName );
  if(!inFile) return;
  inFile.ignore(1000,'\n');
  cout << "processing" << endl;

  DateTime * dateTime;
  YearRecord * yearRecord;
  MonthRecord * monthRecord;
//  IntervalRecord * intervalRecord;
  unsigned day,month,year,hour,minute;
  unsigned second = 0;
  float windSpeed;
  int solarRadiation;

  unsigned lastYear = 0;
  unsigned lastMonth = 0;

  while(inFile.peek() != EOF)
  {
    inFile >> day;
    inFile.ignore(10,'/');
    inFile >> month;
    inFile.ignore(10,'/');
    inFile >> year;
    inFile >> hour;
    inFile.ignore(10,':');
    inFile >> minute;
    dateTime = new DateTime(day,month,year,hour,minute,second);

    for(unsigned i = 0; i < 10; i++) inFile.ignore(100,',');

    inFile >> windSpeed;
    inFile.ignore(100,',');
    inFile >> solarRadiation;
    inFile.ignore(100,'\n');

//    intervalRecord = new IntervalRecord(*dateTime);
//    intervalRecord->setWindSpeed(windSpeed);
//    intervalRecord->setSolarRadiation(solarRadiation);
  }// end while


}

void SensorController::displayMaximumWindSpeed(unsigned year,unsigned month)
{



}

void SensorController::displayAverageWindSpeed(unsigned year)
{



}

void SensorController::displayTotalSolarRadiation(unsigned year)
{



}

void SensorController::printAverageWindSpeedAndTotalSolarRadiation(unsigned year)
{



}

void SensorController::displayPeakSolarRadiationTimes(Date date)
{



}

