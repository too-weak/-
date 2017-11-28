#include "Parking.h"

Parking::Parking(){
    capacity = 5;
    num = 0;
}

bool Parking::CarAction(const string& plate, const string& action){
    if(action == "arrives"){
	    Car* car = new Car(plate);
	    return CarArrives(car);
    }
    else{
	    CarLeaves(plate);
        return true;
    }
}

bool Parking::CarArrives(Car* car){
    if(num < capacity){
	    Park.push(car);
        ++num;
        return true;
    } else {
        record += "Sorry " + car->getPlate() + ", the lot is full" + '\n';
        return false;
    }
}

void Parking::CarLeaves(const string& plate){
    if(num > 0){
    while(Park.top()->getPlate() != plate){
	temp.push(Park.top());
	Park.top()->move();
	Park.pop();
    }

    record += Park.top()->leave();
    Park.pop();
    while(!temp.empty()){
	Park.push(temp.top());
	temp.pop();
    }
        --num;
    }
}
string Parking::showAll() {
    while(!Park.empty()){
        record += Park.top()->leave();
        Park.pop();
    }
    record += '\n';
    return record;
}
