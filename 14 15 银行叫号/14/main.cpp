#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<queue<int>> vec;
  int n, i;
  queue<int> result, temp;
  for(int i = 0; i < 10; ++i){
    vec.push_back(queue<int>());
  }
  cout<<"请输入要输入的数的个数：";
  cin>>n;
  while(n){
    cin>>i;
    if(i >= 0 && i <= 9)
      vec[i].push(i);
    --n;
  }
  for(int i = 0; i < 10; ++i) {
      if (!vec[i].empty()) {
          temp = vec[i];
          if(!temp.empty()){
              cout<<"队列"<<i<<": ";
              while (!temp.empty()) {
                  cout<<temp.front()<<" ";
                  temp.pop();
              }
          }
      }
  }
    return 0;
}
