#include <iostream>
using namespace std;

int *Next(string p);
int KMPStrMatching(string T, string P, int *N, int startIndex);

int main(){
  string str1, str2;
  int index;
  int *next = NULL;
  cin>>str1;
  cin>>str2;
  index = KMPStrMatching(str1, str2, Next(str2), 0);
  if(index != -1)
    cout<<index<<endl;
  else
    cout<<"不匹配"<<endl;
  return 0;
}

int *Next(string p){
  int m = p.length();
  if(m == 0)
    return NULL;
  int *N = new int[m];
  if(N == 0)
    return NULL;
  N[0] = 0;
  for(int i = 1; i < m; ++i){
    int k = N[i - 1];
    while(k > 0 && p[i] != p[k])
      k = N[k - 1];
    if(p[i] == p[k])
      N[i] = k + 1;
    else
      N[i] = 0;
  }
  return N;
}

int KMPStrMatching(string T, string P, int *N, int startIndex){
  int lastIndex = T.length() - startIndex;
  int tLength = T.length();
  int pLength = P.length();
  if(lastIndex - startIndex < 0)
    return -1;
  int i = startIndex;
  int j = 0;
  for(;i < tLength; ++i){
    while(P[j] != T[i] && j > 0)
      j = N[j-1];
    if(P[j] == T[i])
      ++j;
    if(j == pLength)
      return (i-j+1);
  }
  return -1;
}
