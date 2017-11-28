//
// Created by Wang wei on 2017/9/26.
//

#include "SequenceStack.h"

template <class T>
SequenceStack<T>::SequenceStack(int size) {
    maxSize = size;
    top = -1;
    st = new T[size];
}

template <class T>
SequenceStack<T>::SequenceStack() {
    top = -1;
}

template <class T>
SequenceStack<T>::~SequenceStack() {
    delete[] st;
}

template <class T>
void SequenceStack<T>::clear() {
    top = -1;
}

template <class T>
bool SequenceStack<T>::Push(const T item) {
    if(top == maxSize - 1)
        return false;
    else {
        st[++top] = item;
        return true;
    }
}

template <class T>
bool SequenceStack<T>::Pop() {
    if(top == -1)
        return false;
    else {
        --top;
        return true;
    }
}

template <class T>
bool SequenceStack<T>::Top(T& item) {
    if(top == -1){
        cout<<"栈为空，不能读取"<<endl;
        return false;
    }
    else {
        item = st[top];
        return true;
    }
}
