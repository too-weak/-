//
// Created by Wang wei on 2017/9/19.
//

#ifndef INC_3_LIST_H
#define INC_3_LIST_H

#include <iostream>
using namespace std;

template <class T>
class List {
public:
    List(){head = tail = NULL;}
    ~List(){clear();}
    void reverse();
    void append(T ele);
    void show();
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& d):data(d), next(NULL){}
    };
    Node *head, *tail;
    void clear();
    void create();
};


#endif //INC_3_LIST_H
