#include "Queue.h"
#include "Queue.cpp"

int main() {
    Queue<int> queue(10);
    for(int i = 0; i < 10; ++i)
      queue.enQueue(i);
    queue.showAll();
    int t;
    for(int i = 0; i < 10; ++i){
        queue.deQueue(t);
    }
    queue.showAll();
//    cout<<endl<<t<<endl;
    return 0;
}


