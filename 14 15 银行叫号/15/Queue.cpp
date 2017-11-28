//
// Created by Wang wei on 2017/10/13.
//

#include "Queue.h"

template <class T>
Queue<T>::Queue(const int s){
  front = rear = 0;
  size = s;
  queue = new T[s];
  tag = 0;
}

template <class T>
Queue<T>::~Queue(){
  Clear();
}

template <class T>
void Queue<T>::Clear(){
  delete[] queue;
}

template <class T>
bool Queue<T>::enQueue(const T& item){
  if(front == rear && tag == 1){
    cout<<"队列已满。"<<endl;
//    tag = 1;
    return false;
  }
  queue[rear] = item;
  rear = (rear + 1) % size;
  tag = 1;
  return true;
}

template <class T>
bool Queue<T>::deQueue(T &item){
  if(front == rear && tag == 0){
    cout<<"队列为空"<<endl;
//    tag = 0;
    return false;
  }
  item = queue[front];
  front = (front + 1) % size;
  tag = 0;
  return true;
}

template <class T>
bool Queue<T>::getFront(T &item){
  if(front != rear && tag != 0){
    item = queue[front];
    return true;
  } else
    return true;
}

template <class T>
bool Queue<T>::empty(){
  return front == rear && tag == 0;
}

template <class T>
void Queue<T>::showAll(){
    if(front == rear && tag == 1){
        for(int i = front+1; i % size != rear; i = (i+1) % size){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    } else {
        for (int i = front; i % size != rear; i = (i + 1) % size) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
