#include <iostream>
#include "DLList.h"
#include "DLList.cpp"
using namespace std;

#define TYPE int

int main() {
    int numOfEle = 0;
    TYPE* arr = (TYPE*)malloc(numOfEle*(sizeof(TYPE)));
    TYPE temp;
    TYPE x;
    cout<<"输入元素的数量"<<endl;
    cin>>numOfEle;
    for(int i = 0; i < numOfEle; ++i){
        cin>>temp;
        arr[i] = temp;
    }
    DLList<TYPE> *list = new DLList<TYPE>(arr, numOfEle);
    list->show();
    cout<<"请输入要删除的元素x："<<endl;
    cin>>x;
    list->deleteX(x);
    list->show();
    return 0;
}