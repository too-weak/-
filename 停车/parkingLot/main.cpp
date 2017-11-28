#include <iostream>
#include <vector>
#include <fstream>
#include "Parking.h"
#include "Parking.cpp"
using namespace std;

int main(){
    vector<string> cars;
    vector<string> actions;
    int CarNums;
    string temp;
    string record;
    ifstream infile("data.txt");
    ofstream ofile("output.txt");
    Parking parking;
    while(!infile.eof()){
	infile>>temp;
	cars.push_back(temp);
	temp.clear();
	infile>>temp;
	actions.push_back(temp);
	temp.clear();
    }
    CarNums = cars.size();
    for(int i = 0; i < CarNums; ++i){
	parking.CarAction(cars[i], actions[i]);
    }
    record = parking.showAll();
    cout<<record;
    ofile<<record;
    return 0;
}
