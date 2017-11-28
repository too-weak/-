//
// Created by Wang wei on 2017/9/23.
//

#ifndef SHANGJI_DLLIST_H
#define SHANGJI_DLLIST_H

#include <iostream>
#include "DLLNode.h"
#include "DLLNode.cpp"

template <class T>
class DLList {
public:
    DLLNode<T> *head, *tail;
    DLLNode<T> *newHead;
public:
    DLList(T* arr, int num);
    void show();
    void deleteX(T x);
};


#endif //SHANGJI_DLLIST_H
