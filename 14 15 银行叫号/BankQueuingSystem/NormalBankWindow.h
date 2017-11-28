#ifndef BANKQUEUINGSYSTEM_NORMALBANKWINDOW_H
#define BANKQUEUINGSYSTEM_NORMALBANKWINDOW_H

#include "BankWindow.h"
#include "BankWindow.cpp"

class NormalBankWindow: public BankWindow{
 public:
 NormalBankWindow(int ID):BankWindow(ID){
    type = '0';
    isBusy = false;
  }
};

#endif
