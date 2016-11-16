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
    bool simulateCustomerEnter();   //当没有了用户进入的时候，即到了12s的时候，返回false
    bool UserWait();                //有用户在等待返回true
    void simulateCallCustomer();

};

#endif
