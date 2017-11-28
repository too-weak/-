#include <iostream>
#include "Arr.h"
#include "Arr.cpp"
using namespace std;

int main() {
    Arr<int > array;
    array.show();
    array.DeleteMin();
    array.show();
    int tar = 0;
    cout<<"请输入要删除的值:"<<endl;
    cin>>tar;
    array.DeleteX(tar);
    array.show();
    int s, t;
    cout<<"请输入要删除的范围:"<<endl;
    cin>>s;
    cin>>t;
    array.DeleteSToT(s, t);
    array.show();
    return 0;
}