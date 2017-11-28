#ifndef BANKQUEUINGSYSTEM_VIPBANKWINDOW_H
#define BANKQUEUINGSYSTEM_VIPBANKWINDOW_H

#include "BankWindow.h"
//#include "BankWindow.cpp"

class VIPBankWindow: public BankWindow{
 public:
 VIPBankWindow(int ID):BankWindow(ID){
    type = '0';
    isBusy = false;
  }
};

#endif
