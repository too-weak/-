#include <iostream>
using namespace std;

int Strcmp(const string &s, const string &t);

int main(){
  string str1, str2;
  cin>>str1;
  cin>>str2;
  if(Strcmp(str1, str2) == -1)
    cout<<"小于"<<endl;
  else if (Strcmp(str1, str2) == 0)
    cout<<"相等"<<endl;
  else
    cout<<"大于"<<endl;
  return 0;
}

int Strcmp(const string& s, const string& t){
  int sLength = s.length();
  int tLength = t.length();
  if(sLength != tLength)
    return false;
  for(int i = 0; i < sLength; ++i)
    if(s[i] != t[i]){
      if(s[i] > t[i])
	return 1;
      else
	return -1;
    }
  return 0;
  
}
