//
// Created by Wang wei on 2017/10/3.
//

#ifndef QUEUE_LINKNODE_H
#define QUEUE_LINKNODE_H

#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    LinkNode<T> *next;
    T data;
    LinkNode(){next = NULL;}
};


#endif //QUEUE_LINKNODE_H
