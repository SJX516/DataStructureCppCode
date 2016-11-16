#ifndef _SIMULATER_H
#define _SIMULATER_H
#include "Bankwindow.h"
#include "User.h"
#include<queue>
using namespace std;

class Simulater
{
private:
    queue<NormalUser>  NormalUserQueue;
    queue<VIPUser>  VIPUserQueue;
    queue<OfficialUser> OfficialUserQueue;
    NormalBankWindow nbw[3];
    VIPBankWindow vbw;
    OfficalBankWindow obw;
    int customerEnterMatrix[7][3];
    int current_len ;
public:
    Simulater();
    void simulate();
    bool simulateCustomerEnter();   //��û�����û������ʱ�򣬼�����12s��ʱ�򣬷���false
    bool UserWait();                //���û��ڵȴ�����true
    void simulateCallCustomer();

};

#endif
