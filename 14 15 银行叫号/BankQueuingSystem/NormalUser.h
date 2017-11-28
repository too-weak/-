//
// Created by Wang wei on 2017/10/13
//

#ifndef BANKQUEUINGSYSTEM_NORMALUSER_H
#define BANKQUEUINGSYSTEM_NORMALUSER_H

#include "User.h"

class NormalUser: public User{
 public:
 NormalUser(int ID, int arrTime){
     id = ID;
     arriveTime = arrTime;
    type = '0';
  }
};

#endif //BANKQUEUINGSYSTEM_NORMALUSER_H
