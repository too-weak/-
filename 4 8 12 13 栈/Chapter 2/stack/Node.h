//
// Created by Wang wei on 2017/9/26.
//

#ifndef STACK_NODE_H
#define STACK_NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T> *prev;
    Node(T info);
};


#endif //STACK_NODE_H
