//
// Created by Wang wei on 2017/10/13
//

#ifndef BANKQUEUINGSYSTEM_OFFICIALUSER_H
#define BANKQUEUINGSYSTEM_OFFICIALUSER_H

#include "User.h"

class OfficialUser:public User{
 public:
 OfficialUser(int ID, int arrTime){
     id = ID;
     arriveTime = arrTime;
    type = '2';
  }
};

#endif //BANKQUEUINGSYSTEM_OFFICIALUSER_H
