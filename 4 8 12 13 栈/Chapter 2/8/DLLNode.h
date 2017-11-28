//
// Created by Wang wei on 2017/9/23.
//

#ifndef SHANGJI_DLLNODE_H
#define SHANGJI_DLLNODE_H

#include <iostream>
using namespace std;

template  <class T>
class DLLNode {
public:
    T data;
    DLLNode<T> *next;
    DLLNode<T> *prev;
    DLLNode(T info, DLLNode<T> *prevVal = NULL, DLLNode<T> *nextVal = NULL);
};


#endif //SHANGJI_DLLNODE_H
