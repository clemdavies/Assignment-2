#include "TestingTools.h"

TestingTools::~TestingTools()
{

};


TestingTools::TestingTools()
{
  resetValues();
};


const std::stringstream & TestingTools::getOutputStream()
{
  return outputStream;
};




void TestingTools::outputTotals()
{
  outputStream << std::endl
               << "TEST TOTALS" << std::endl
               << "Ran: " << totalTestsRan << std::endl
               << "Passed: " << totalTestsPassed << std::endl
               << "Failed: " << totalTestsFailed << std::endl;
  outputFailedFunctions();
};

void TestingTools::description( const char * description )
{
  outputClassName();
  outputFunctionName();
  outputStream << description << std::endl;
};


void TestingTools::setClassName( const char * newClassName )
{
  classNameOutput = false;
  className = newClassName;
};


const char * TestingTools::getClassName()
{
  return className;
}

const char * TestingTools::getFunctionName()
{
  return functionName;
}


void TestingTools::setFunctionName( const char * newFunctionName )
{
  functionNameOutput = false;
  functionName = newFunctionName;
};

bool TestingTools::equalTest(const char * predicted,const char * actual,bool boolSwitch)
{
  bool result = false;
  if( (strcmp(predicted,actual) == 0) == boolSwitch )
    result = true;
  return result;
};

void TestingTools::assertTrue( bool trueValue )
{
  output( trueValue == true,"True" );
};

void TestingTools::assertFalse( bool falseValue )
{
  output( falseValue == false,"False" );
};




void TestingTools::resetValues()
{
  className = "";
  functionName = "";

  PASS_SPACER = "----------";
  FAIL_SPACER = "++++++++++";

  functionNameOutput = false;
  classNameOutput = false;

  totalTestsRan = 0;
  totalTestsPassed = 0;
  totalTestsFailed = 0;

  uniqueClassID = 0;
  uniqueFunctionID = 0;
  lastClassID = 0;
  lastFunctionID = 0;
  testCount = 0;

  outputStream.flush();
};



void TestingTools::iterateTotals(bool result)
{
  totalTestsRan++;
  if(result)
    totalTestsPassed++;
  else
    totalTestsFailed++;
};


void TestingTools::output( bool result, const char * message, const char *operation)
{
  outputClassName();
  outputFunctionName();
  outputStream << message << ": " << "object A " << operation <<  " object B"  << std::endl;
  outputResult(result);
  outputStream << std::endl;
};


void TestingTools::output(bool result,const char * message)
{
  outputClassName();
  outputFunctionName();
  outputStream << message << std::endl;
  outputResult(result);
  outputStream<<std::endl;
};



void TestingTools::appendFailedFunctions()
{
  if(testNumbers.size() == 0 || uniqueClassID != lastClassID){
    lastClassID = uniqueClassID;
    classNames.push_back(className);
    if(testNumbers.size() > 0){
      functionNames.push_back("");
    }
  }

  if(testNumbers.size() == 0 || uniqueFunctionID != lastFunctionID)
  {
    lastFunctionID = uniqueFunctionID;
    functionNames.push_back(functionName);
    if(testNumbers.size() > 0){
      testNumbers.push_back(0);
    }
  }
  testNumbers.push_back(testCount);
};


void TestingTools::outputClassName()
{
  if(!classNameOutput){
    outputStream << std::endl << "CLASS:    "  << className << std::endl;
    classNameOutput = true;
    uniqueClassID++;
  }
};

void TestingTools::outputFunctionName()
{
  if(!functionNameOutput){
    outputStream << std::endl << "FUNCTION: " << functionName << std::endl << std::endl;
    functionNameOutput = true;
    uniqueFunctionID++;
    testCount = 0;
  }
};

void TestingTools::outputResult(bool result)
{
  testCount++;
  iterateTotals(result);
  if(result){
    outputStream << PASS_SPACER << "PASSED" << PASS_SPACER;
  }
  else
  {
    outputStream << FAIL_SPACER << "FAILED" << FAIL_SPACER;
    appendFailedFunctions();
  }
};

void TestingTools::outputFailedFunctions()
{

  unsigned funct_i = 0;
  unsigned class_i = 0;
  bool classOut = false;
  bool functOut = false;
  bool newLine = false;
  unsigned spaceLength = 0;

  for(unsigned test_i = 0; test_i < testNumbers.size() ; test_i++)
  {
    if(testNumbers[test_i] == 0)
    {
      // new function
      functOut = false;
      newLine  = true;
      funct_i++;
      if( strlen(functionNames[funct_i]) == 0 )
      {
      // new class
        classOut = false;
        class_i++;
        funct_i++;
      }
      outputStream << std::endl;
      continue;
    }

    if(!classOut)
    {
      outputStream << classNames[class_i] << "::";
      classOut = true;
      newLine  = false;
      spaceLength = strlen(classNames[class_i]) + 2;
    }
    if(!functOut)
    {
      for(unsigned space_i = 0; newLine && space_i < spaceLength; space_i++)
      {
        outputStream << " ";
      }
      outputStream << functionNames[funct_i];
      functOut = true;
      newLine = false;
    }
    outputStream << ":" << testNumbers[test_i];
  }


};
