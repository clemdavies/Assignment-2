#ifndef DAYRECORD_H
#define DAYRECORD_H

#include "Time.h"
#include "BinarySearchTree.h"

class DayRecord
{
  public:
    DayRecord();
    virtual ~DayRecord();

    void addSolarRadiation(const Time &time,const float sr);
    void addWindSpeed(const Time &time,const float ws);

  private:
    BinarySearchTree<float> solarRadiationTree;
    BinarySearchTree<float> windSpeedTree;
};

#endif // DAYRECORD_H
