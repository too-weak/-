//
// Created by Wang wei on 2017/9/23.
//

#include "DLLNode.h"

template <class T>
DLLNode<T>::DLLNode(const T info, DLLNode<T> *prevVal, DLLNode<T> *nextVal) {
    data = info;
    prev = prevVal;
    next = nextVal;
}
