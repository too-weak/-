#include <iostream>
#include "SequenceStack.h"
#include "SequenceStack.cpp"
#include "ChainStack.h"
#include "ChainStack.cpp"
using namespace std;

int main() {
    SequenceStack<int> seq(10);
    ChainStack<int> cha;
    int temp = 0;
    int value;
    for(int i = 0; i < 10; ++i){
        cin>>temp;
        seq.Push(temp);
    }
    for(int i = 0; i < 10; ++i){
        cin>>temp;
        cha.push(temp);
    }
    seq.Top(value);
    cout<<value<<endl;
    cha.Top(value);
    cout<<value<<endl;
    return 0;
}