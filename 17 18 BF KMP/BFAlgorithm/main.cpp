#include <iostream>
#include <string>
using namespace std;

int BFAlgorithm(string str1, string str2);

int main(){
  string str1, str2;
  int equal;
  cout<<"请输入目标和模式："<<endl;
  cin>>str1;
  cin>>str2;
  equal = BFAlgorithm(str1, str2);
  if(equal != -1)
    cout<<equal<<endl;
  else
    cout<<"未找到所查找模式。"<<endl;
    
  return 0;
}

int BFAlgorithm(string str1, string str2){
  size_t length1 = str1.length(), length2 = str2.length();
  int i = 0, j = 0;
  while(i != length1 && j != length2){
    if(str1[i] == str2[j]){
      ++i;
      ++j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if(i >= j && j == length2)
    return (i-j);
  else
    return -1;
}
