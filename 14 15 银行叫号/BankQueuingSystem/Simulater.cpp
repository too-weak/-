#include "Simulater.h"
#define sTime 4
#define dTime 2

void Simulater::Simulate(){
  time = 0;
  int custom[7][3] = {{3,1,1} ,{5,0,0} ,{0,0,0}, {5,1,0}, {0,0,0}, {0,0,0}, {0,0,0}};
  for(int i = 0; i < 3; ++i){
    NormalBankWindow temp(i);
    nbw.push_back(temp);
  }
  VIPBankWindow VIPBW(0);
  vbw.push_back(VIPBW);
  OfficialBankWindow OFFBW(0);
  obw.push_back(OFFBW);

  for(int i = 0; i < 13; ++i){
    if(time%2 == 0)
      customerEnter(custom[i/2]);
    simulateCallCustomer();
    ++time;
      showAll(i);
  }
}

void Simulater::customerEnter(int *p){
  for(int i = 0; i < p[0]; ++i){
    NormalUser temp(++num, time);
    NormalUserQueue.push(temp);
  }
  for(int i = 0; i < p[1]; ++i){
    VIPUser temp(++num, time);
    VIPUserQueue.push(temp);
  }
  for(int i = 0; i < p[2]; ++i){
    OfficialUser temp(++num, time);
    OfficialUserQueue.push(temp);
  }
}

void Simulater::simulateCallCustomer(){
    list<NormalBankWindow>::iterator i;
    list<VIPBankWindow>::iterator j;
    list<OfficialBankWindow>::iterator k;

  for(i = nbw.begin(); i != nbw.end(); ++i){
    if(!((*i).isBusy)){
      if(!NormalUserQueue.empty()){
          (*i).handleUser(NormalUserQueue.front());
          (*i).client.serveTime = time;
	NormalUserQueue.pop();
      } else if(!VIPUserQueue.empty()){
          (*i).handleUser(VIPUserQueue.front());
          (*i).client.serveTime = time;
	VIPUserQueue.pop();
      } else if (!OfficialUserQueue.empty()){
          (*i).handleUser(OfficialUserQueue.front());
          (*i).client.serveTime = time;
	OfficialUserQueue.pop();
      }
    } else if(time - (*i).client.serveTime == sTime){
        (*i).handleUser();
        if(!NormalUserQueue.empty()){
            (*i).handleUser(NormalUserQueue.front());
            (*i).client.serveTime = time;
            NormalUserQueue.pop();
        } else if(!VIPUserQueue.empty()){
            (*i).handleUser(VIPUserQueue.front());
            (*i).client.serveTime = time;
            VIPUserQueue.pop();
        } else if (!OfficialUserQueue.empty()){
            (*i).handleUser(OfficialUserQueue.front());
            (*i).client.serveTime = time;
            OfficialUserQueue.pop();
        }
    }
  }

  j = vbw.begin();
  if(!((*j).isBusy)){
    if(!VIPUserQueue.empty()){
        (*j).handleUser(VIPUserQueue.front());
        (*j).client.serveTime = time;
	VIPUserQueue.pop();
      } else if(!NormalUserQueue.empty()){
        (*j).handleUser(NormalUserQueue.front());
        (*j).client.serveTime = time;
	NormalUserQueue.pop();
      } else if (!OfficialUserQueue.empty()){
        (*j).handleUser(OfficialUserQueue.front());
        (*j).client.serveTime = time;
	OfficialUserQueue.pop();
      }
  } else if(time - (*j).client.serveTime == sTime){
      (*j).handleUser();
      if(!VIPUserQueue.empty()){
          (*j).handleUser(VIPUserQueue.front());
          (*j).client.serveTime = time;
          VIPUserQueue.pop();
      } else if(!NormalUserQueue.empty()){
          (*j).handleUser(NormalUserQueue.front());
          (*j).client.serveTime = time;
          NormalUserQueue.pop();
      } else if (!OfficialUserQueue.empty()){
          (*j).handleUser(OfficialUserQueue.front());
          (*j).client.serveTime = time;
          OfficialUserQueue.pop();
      }
  }

  k = obw.begin();
  if(!((*k).isBusy)){
    if (!OfficialUserQueue.empty()){
        (*k).handleUser(OfficialUserQueue.front());
        (*k).client.serveTime = time;
	OfficialUserQueue.pop();
      } else if(!VIPUserQueue.empty()){
        (*k).handleUser(VIPUserQueue.front());
        (*k).client.serveTime = time;
	VIPUserQueue.pop();
      } else if(!NormalUserQueue.empty()){
        (*k).handleUser(NormalUserQueue.front());
        (*k).client.serveTime = time;
	NormalUserQueue.pop();
      }
  } else if(time - (*k).client.serveTime == sTime){
      (*k).handleUser();
      if (!OfficialUserQueue.empty()){
          (*k).handleUser(OfficialUserQueue.front());
          (*k).client.serveTime = time;
          OfficialUserQueue.pop();
      } else if(!VIPUserQueue.empty()){
          (*k).handleUser(VIPUserQueue.front());
          (*k).client.serveTime = time;
          VIPUserQueue.pop();
      } else if(!NormalUserQueue.empty()){
          (*k).handleUser(NormalUserQueue.front());
          (*k).client.serveTime = time;
          NormalUserQueue.pop();
      }
  }
}

void Simulater::showAll(int now) {
    int times = 1;
    cout<<"第"<<now<<"秒"<<endl<<endl;
    for(list<NormalBankWindow>::iterator i = nbw.begin();
        i != nbw.end(); ++i){
        cout<<"--------------------------"<<endl;
        cout<<"第"<<times<<"个普通用户窗口："<<endl;
        cout<<"当前状态：";
        if((*i).isBusy) {
	  cout << "正忙"<<endl;
            cout<<"当前服务客户:"<<(*i).client.id;
        }
        else
            cout<<"空闲";
        cout<<endl;
        ++times;
    }
    cout<<"--------------------------"<<endl;
    
    list<VIPBankWindow>::iterator j = vbw.begin();
    cout<<"VIP用户窗口:"<<endl;
    cout<<"当前状态：";
    if((*j).isBusy){
      cout<<"正忙"<<endl;
      cout<<"当前服务客户"<<(*j).client.id<<endl;
    } else
	cout<<"空闲"<<endl;

    cout<<"--------------------------"<<endl;
      list<OfficialBankWindow>::iterator k = obw.begin();
      cout<<"对公用户窗口："<<endl;
      cout<<"当前状态:"<<endl;
      if((*k).isBusy){
      cout<<"正忙"<<endl;
      cout<<"当前服务客户"<<(*k).client.id<<endl;
    } else
	cout<<"空闲"<<endl;
    cout<<"--------------------------"<<endl;
}
