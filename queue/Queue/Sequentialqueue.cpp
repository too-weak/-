//
// Created by Wang wei on 2017/10/3.
//

#include "Sequentialqueue.h"

template <class T>
Sequentialqueue<T>::Sequentialqueue(int size) {
    maxSize = size + 1;
    queue = new T[maxSize];
    front = rear = 0;
}

template <class T>
Sequentialqueue<T>::~Sequentialqueue() {
    delete[] queue;
}

template <class T>
void Sequentialqueue<T>::Clear() {
    front = rear;
}

template <class T>
bool Sequentialqueue<T>::enQueue(const T &item) {
    if((rear+1) % maxSize == front){
        cout<<"队列已满，溢出"<<endl;
        return false;
    }
    queue[rear] = item;
    rear = (rear+1) % maxSize;
    return true;
}

template <class T>
bool Sequentialqueue<T>::deQueue(T &item) {
    if(front == rear){
        cout<<"队列为空"<<endl;
        return false;
    }
    item = queue[front];
    front = (front+1) % maxSize;
    return false;
}

template <class T>
bool Sequentialqueue<T>::getFront(T &item) {
    if(front == rear){
        cout<<"队列为空"<<endl;
        return false;
    }
    item = queue[front];
    return true;
}

template <class T>
void Sequentialqueue<T>::showQueue() {
    if(front == rear)
        cout<<"队列为空"<<endl;
    else {
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
            cout << queue[i] << " ";
        }
        cout<<endl;
    }
}
