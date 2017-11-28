//
// Created by Wang wei on 2017/9/24.
//

#ifndef INC_4_LIST_H
#define INC_4_LIST_H

#include "Node.h"

template <class T>
class List {
public:
    Node<T> *head;
    Node<T> *tail;
    List();
    List(T *arr, int length);
    void insertData(T x);
    T findTheLargest();
    int numOfNode();
    T getTheAverage();
};


#endif //INC_4_LIST_H
