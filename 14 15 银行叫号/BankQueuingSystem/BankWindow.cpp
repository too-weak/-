//
// Created by Wang wei on 2017/10/13
//

#include "BankWindow.h"

void BankWindow::handleUser(const User &user){
  isBusy = !isBusy;
  client = user;
}

void BankWindow::handleUser(){
  isBusy = !isBusy;
}
