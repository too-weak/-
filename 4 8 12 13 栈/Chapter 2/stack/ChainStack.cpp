//
// Created by Wang wei on 2017/9/26.
//

#include "ChainStack.h"

template <class T>
ChainStack<T>::ChainStack() {
    top = NULL;
    size = 0;
}

template <class T>
ChainStack<T>::~ChainStack() {
    clear();
}

template <class T>
void ChainStack<T>::clear() {
    while(top != NULL){
        Node<T> *temp = top;
        top = top->prev;
        delete temp;
    }
    size = 0;
}

template <class T>
void ChainStack<T>::push(const T item) {
    Node<T> *temp = new Node<T>(item);
    temp->prev = top;
    top = temp;
    ++size;
}

template <class T>
bool ChainStack<T>::pop() {
    Node<T> *temp = top;
    if(size == 0)
        return false;
    top = top->prev;
    delete temp;
    --size;
    return true;
}

template <class T>
bool ChainStack<T>::Top(T& item) {
    if(size == 0){
        cout<<"栈为空，不能读取"<<endl;
        return false;
    }
    else{
        item = top->data;
        return true;
    }
}
