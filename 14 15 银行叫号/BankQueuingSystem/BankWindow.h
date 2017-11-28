//
// Created by Wang wei on 2017/10/13
//

#ifndef BANKQUEUINGSYSTEM_BANKWINDOW_H
#define BANKQUEUINGSYSTEM_BANKWINDOW_H

#include "User.h"

class BankWindow{
 public:
  bool isBusy;
  int id;
  User client;
  wchar_t type;
  void handleUser(const User &user);
  void handleUser();
  BankWindow(int ID){
      id = ID;
      isBusy = false;

  }
};

#endif //BANKQUEUINGSYSTEM_BANKWINDOW_H
