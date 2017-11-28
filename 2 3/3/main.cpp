#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main() {
    List<int> list;
    int in = 0;
    for(int counter = 0; counter < 10; ++counter){
        cin>>in;
        list.append(in);
    }
    list.show();
    list.reverse();
    list.show();
    return 0;
}