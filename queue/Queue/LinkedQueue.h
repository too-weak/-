//
// Created by Wang wei on 2017/10/3.
//

#ifndef QUEUE_LINKEDQUEUE_H
#define QUEUE_LINKEDQUEUE_H

#include <iostream>
#include "LinkNode.h"
using namespace std;

template <class T>
class LinkedQueue {
private:
    int size;
    LinkNode<T> *front, *rear;
public:
    LinkedQueue();
    ~LinkedQueue();
    void Clear();
    void enQueue(const T &item);
    bool deQueue(T &item);
    bool getFront(T &item);
    void showQueue();
};


#endif //QUEUE_LINKEDQUEUE_H
