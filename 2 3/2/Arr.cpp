//
// Created by Wang wei on 2017/9/19.
//

#include "Arr.h"

template <class T>
Arr<T>::Arr() {
    T in;
    for(int i = 0; i < length; ++i){
        cin>>in;
        arr[i] = in;
    }
}

template <class T>
T Arr<T>::DeleteMin() {
    if(length == 0)
        return -1;
    T min = arr[0];
    int index = 0, counter = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
            ++counter;
        }
    }
    for(int i = 0; i < length; ++i){
        if(arr[i] == min){
            ++counter;
            arr[i] = arr[length - 1];
        }
    }
    arr[index] = arr[length - 1];
    return min;
}

template <class T>
bool Arr<T>::DeleteX(T x) {
    if(length == 0)
        return false;
    int numOfX = 0;
    for(int i = 0; i < length; i++){
        if(arr[i] == x)
            ++numOfX;
        else
            arr[i-numOfX] = arr[i];
    }
    length -= numOfX;
    return true;
}

template <class T>
bool Arr<T>::DeleteSToT(T s, T t) {
    if(length == 0)
        return false;
    int numOfEle = 0;
    for(int i = 0; i < length; ++i){
        if(arr[i] >= s && arr[i] <= t)
            ++numOfEle;
        else
            arr[i-numOfEle] = arr[i];
    }
    length -= numOfEle;
    return true;
}

template <class T>
void Arr<T>::show() {
    for(int i = 0; i < length; ++i){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
