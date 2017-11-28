//
// Created by Wang wei on 2017/9/23.
//

#include "DLList.h"

template <class T>
DLList<T>::DLList(T* arr, int num) {
    if(num == 0){
        cout<<"元素数量为0， 不能创建链表"<<endl;
        return;
    }
    DLLNode<T> *temp = NULL;
    head = tail = NULL;
    for(int i = 0; i < num; ++i){
        temp = new DLLNode<T>(arr[i]);
        if(!head){
            head = tail = temp;
            head->prev = tail;
            tail->next = head;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    tail->next = head;
    head->prev = tail;
}

template <class T>
void DLList<T>::show() {
    DLLNode<T> *temp = head;
    if(temp == NULL)
        cout<<"空链表！"<<endl;
    else{
        while(temp != tail){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<"  "<<endl;
    }
}

template <class T>
void DLList<T>::deleteX(T x) {
    DLLNode<T> *temp = head;
    if(!head){
        cout<<"链表为空，不能没有元素x，不能删除"<<endl;
    } else {
        while(temp->data != x && temp != tail){
            temp = temp->next;
        }
        if(temp->data == x){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        } else if(temp == tail) {
            cout << "没有元素x" << endl;
        }
    }
}
