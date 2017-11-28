//
// Created by Wang wei on 2017/9/19.
//

#ifndef INC_2_ARR_H
#define INC_2_ARR_H

#include <iostream>
using namespace std;

#define SIZE 4

template <class T>
class Arr {
private:
    T arr[SIZE];
    int length = SIZE;
public:
    Arr();
    T DeleteMin();
    bool DeleteX(T x);
    bool DeleteSToT(T s, T t);
    void show();
};


#endif //INC_2_ARR_H
