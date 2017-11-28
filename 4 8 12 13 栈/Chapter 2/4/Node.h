//
// Created by Wang wei on 2017/9/24.
//

#ifndef INC_4_NODE_H
#define INC_4_NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
};


#endif //INC_4_NODE_H
