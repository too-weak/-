#ifndef BANKQUEUINGSYSTEM_OFFICIALBANKWINDOW_H
#define BANKQUEUINGSYSTEM_OFFICIALBANKWINDOW_H

#include "BankWindow.h"
//#include "BankWindow.cpp"

class OfficialBankWindow: public BankWindow{
 public:
 OfficialBankWindow(int ID):BankWindow(ID){
    type = '0';
    isBusy = false;
  }
};

#endif
