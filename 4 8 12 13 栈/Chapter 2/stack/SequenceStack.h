//
// Created by Wang wei on 2017/9/26.
//

#ifndef STACK_SEQUENCESTACK_H
#define STACK_SEQUENCESTACK_H

#include <iostream>
using namespace std;

template <class T>
class SequenceStack {
private:
    int maxSize;
    int top;
    T *st;
public:
    SequenceStack(int size);
    SequenceStack();
    ~SequenceStack();
    void clear();
    bool Push(const T item);
    bool Pop();
    bool Top(T& item);
};


#endif //STACK_SEQUENCESTACK_H
