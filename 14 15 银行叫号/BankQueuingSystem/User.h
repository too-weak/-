//
// Created by Wang wei on 2017/l0/13
//

#ifndef BANKQUEUINGSYSTEM_USER_H
#define BANKQUEUINGSYSTEM_USER_H

#include <iostream>
using namespace std;

class User{
 public:
  int id;
  int arriveTime;
  int serveTime;
  wchar_t type;
  bool isWait;
  void getServed(){isWait = !isWait;};
  User(){isWait = true;}
};

#endif //BANKQUEUINGSYSTEM_USER_H 
