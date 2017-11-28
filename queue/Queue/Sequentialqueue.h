//
// Created by Wang wei on 2017/10/3.
//

#ifndef QUEUE_SEQUENTIALQUEUE_H
#define QUEUE_SEQUENTIALQUEUE_H

#include <iostream>
using namespace std;

template <class T>
class Sequentialqueue {
private:
    int maxSize;
    int front;
    int rear;
    T *queue;
public:
    Sequentialqueue(int size);
    ~Sequentialqueue();
    void Clear();
    bool enQueue(const T &item);
    //返回队头元素并删除该元素
    bool deQueue(T &item);
    bool getFront(T &item);
    void showQueue();
};


#endif //QUEUE_SEQUENTIALQUEUE_H
