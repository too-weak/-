#ifndef PARKINGLOT_CAR_H
#define PARKINGLOT_CAR_H

#include <iostream>
using namespace std;

class Car{
  private:
    int movedTimes;
    string plate;
    
  public:
  Car(string p):plate(p){movedTimes = 0;}
    void move();
    string leave();
    string getPlate();
};

#endif
