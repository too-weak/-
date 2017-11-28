#ifndef BANKQUEUINGSYSTEM_SIMULATER_H
#define BANKQUEUINGSYSTEM_SIMULATER_H

#include <queue>
#include <list>
#include "NormalUser.h"
#include "VIPUser.h"
#include "OfficialUser.h"
#include "NormalBankWindow.h"
#include "VIPBankWindow.h"
#include "OfficialBankWindow.h"
using namespace std;

class Simulater{
 public:
  int num;
  int time;
  queue<NormalUser> NormalUserQueue;
  queue<VIPUser> VIPUserQueue;
  queue<OfficialUser> OfficialUserQueue;
  list<NormalBankWindow> nbw;
  list<VIPBankWindow> vbw;
  list<OfficialBankWindow> obw;
  void customerEnter(int *p);
  void simulateCustomerEnter();
  void simulateCallCustomer();
  void Simulate();
    void showAll(int now);
};

#endif
