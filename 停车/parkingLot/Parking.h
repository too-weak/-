#ifndef PARKINGLOT_PARKING_H
#define PARKINGLOT_PARKING_H

#include <stack>
#include "Car.h"
#include "Car.cpp"

class Parking{
  private:
    stack<Car*> Park;
    stack<Car*> temp;
    int capacity;
    int num;
    string record;
  public:
    Parking();
    bool CarArrives(Car* car);
    void CarLeaves(const string& plate);
    bool CarAction(const string& plate, const string& action);
    string showAll();
    //void CarMoves(const Car* car);
};

#endif
