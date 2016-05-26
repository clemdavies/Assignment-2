#include <iostream>
#include "TestSuite.h"
#include "SensorController.h"

using namespace std;

int main()
{
//  TestSuite tests;
//  tests.all();
//  return 0;
  TestSuite tests;
  tests.all();
  return 0;

  SensorController controller("input/index.txt","output/WindandSolar.csv");
  controller.readInputFiles();


  return 0;
}
