//
// Created by Wang wei on 2017/10/13
//

#ifndef BANKQUEUINGSYSTEM_VIPUSER_H
#define BANKQUEUINGSYSTEM_VIPUSER_H

#include "User.h"

class VIPUser: public User{
 public:
 VIPUser(int ID, int arrTime){
     id = ID;
     arriveTime = arrTime;
    type = '1';
  }
};

#endif //BANKQUEUINGSYSTEM_VIPUSER_H
