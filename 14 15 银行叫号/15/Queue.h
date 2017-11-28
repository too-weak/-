//
// Created by Wang wei on 2017/10/13.
//

#ifndef INC_15_QUEUE_H
#define INC_15_QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class Queue{
 public:
  T *queue;
  int front;
  int rear;
  int size;
  bool tag;
  Queue(const int s);
  ~Queue();
  void Clear();
  bool enQueue(const T& item);
  bool deQueue(T& item);
  bool getFront(T& item);
  bool empty();
  void showAll();
};

#endif //INC_15_QUEUE_H
