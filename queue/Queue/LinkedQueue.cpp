//
// Created by Wang wei on 2017/10/3.
//

#include "LinkedQueue.h"

template <class T>
LinkedQueue<T>::LinkedQueue() {
    size = 0;
    front = rear = NULL;
}

template <class T>
LinkedQueue<T>::~LinkedQueue() {
    Clear();
}

template <class T>
void LinkedQueue<T>::Clear() {
    LinkNode<T> *temp = front;
    while(front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

template <class T>
void LinkedQueue<T>::enQueue(const T &item) {
    if(front == NULL){
        front = rear = new LinkNode<T>;
        front->data = item;
    } else {
        rear->next = new LinkNode<T>;
        rear = rear->next;
        rear->data = item;
    }
    ++size;
}

template <class T>
bool LinkedQueue<T>::deQueue(T &item) {
    if(size == 0){
        cout<<"队列为空"<<endl;
        return false;
    } else {
        LinkNode<T> *temp = front;
        front = front->next;
        delete temp;
        return true;
    }
}

template <class T>
bool LinkedQueue<T>::getFront(T &item) {
    if(size == 0){
        cout<<"队列为空";
        return false;
    } else {
        item = front->data;
        return true;
    }
}

template <class T>
void LinkedQueue<T>::showQueue() {
    if(size == 0)
        cout<<"队列为空"<<endl;
    else{
        LinkNode<T> *temp = front;
        while(temp->next != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
        cout<<endl;
    }
}
