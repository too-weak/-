//
// Created by Wang wei on 2017/9/26.
//

#ifndef STACK_CHAINSTACK_H
#define STACK_CHAINSTACK_H

#include <iostream>
#include "Node.h"
#include "Node.cpp"
using namespace std;

template <class T>
class ChainStack {
    int size;
    Node<T> *top;
public:
    ChainStack();
    ~ChainStack();
    void clear();
    void push(T item);
    bool pop();
    bool Top(T& item);
};


#endif //STACK_CHAINSTACK_H
