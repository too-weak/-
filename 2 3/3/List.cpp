//
// Created by Wang wei on 2017/9/19.
//

#include "List.h"

template <class T>
void List<T>::reverse() {
    Node *he = head, *pre = NULL, *next = NULL;
    while(he != NULL){
        next = he->next;
        he->next = pre;
        pre = he;
        he = next;
    }
    head = pre;
}

template <class T>
void List<T>::show() {
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
void List<T>::append(T ele) {
    Node* temp = new Node(ele);
    if(!head){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

template <class T>
void List<T>::clear() {
    Node* p = head;
    while(p){
        Node* q = p->next;
        delete p;
        p = q;
    }
    free(p);
}
