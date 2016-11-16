#include "Simulater.h"
#include <windows.h>
#include <iostream>
using namespace std;
Simulater::Simulater()
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            customerEnterMatrix[i][j] = 0;
        }
    }
    customerEnterMatrix[0][0] = 3;
    customerEnterMatrix[0][1] = 1;
    customerEnterMatrix[0][2] = 1;
    customerEnterMatrix[1][0] = 5;
    customerEnterMatrix[3][0] = 5;
    customerEnterMatrix[3][1] = 1;
    nbw[0].id = 1;
    nbw[1].id = 2;
    nbw[2].id = 3;
    current_len = 0;
}

void Simulater::simulate()
{
    while( 1 )
    {
        simulateCustomerEnter();
        simulateCallCustomer();
        if( ! ( UserWait() || ( current_len < 7 ) ) )
            break;
        Sleep(2000);
        simulateCustomerEnter();
        Sleep(2000);

    }
}

bool Simulater::simulateCustomerEnter()
{
    static int j = 0;
        NormalUser nu[ customerEnterMatrix[current_len][0] ];
        for(int k = 0; k < customerEnterMatrix[current_len][0] ; k++)
        {
            ++j;  nu[k].id = j;
            NormalUserQueue.push( nu[k] );
        }

        VIPUser vu[ customerEnterMatrix[current_len][1] ];
        for(int k = 0; k < customerEnterMatrix[current_len][1] ; k++)
        {
            ++j;  vu[k].id = j;
            VIPUserQueue.push( vu[k] );
        }

        OfficialUser ou[ customerEnterMatrix[current_len][2] ];
        for(int k = 0; k < customerEnterMatrix[current_len][2] ; k++)
        {
            ++j;  ou[k].id = j;
            OfficialUserQueue.push( ou[k] );
        }
        current_len++;
    return true;

}

bool Simulater::UserWait()
{
    if( !OfficialUserQueue.empty() )
    {
        return true;
    }
    if( !VIPUserQueue.empty() )
    {
        return true;
    }
    if( !NormalUserQueue.empty() )
    {
        return true;
    }
    return false;

}

void Simulater::simulateCallCustomer()
{
    for(int i = 0; !NormalUserQueue.empty() && i < 3; i++)
    {
        nbw[i].HandleUser();
        ( NormalUserQueue.front() ).getServed();
        NormalUserQueue.pop();
    }
    if( !VIPUserQueue.empty() )
    {
        vbw.HandleUser();
        (VIPUserQueue.front() ).getServed();
        VIPUserQueue.pop();
    }
    else if( !NormalUserQueue.empty() )
    {
        vbw.HandleUser();
        (NormalUserQueue.front() ).getServed();
        NormalUserQueue.pop();
    }

    if( !OfficialUserQueue.empty() )
    {
        obw.HandleUser();
        (OfficialUserQueue.front() ).getServed();
        OfficialUserQueue.pop();
    }
    else if( !NormalUserQueue.empty() )
    {
        obw.HandleUser();
        (NormalUserQueue.front() ).getServed();
        NormalUserQueue.pop();
    }
    cout<<endl<<endl;


}

void NormalBankWindow::HandleUser()
{
    cout<<"普通窗口"<<this->id<<"正在招待";
}

void VIPBankWindow::HandleUser()
{
    cout<<"VIP窗口正在招待";
}

void OfficalBankWindow::HandleUser()
{
    cout<<"对公窗口正在招待";
}

void NormalUser::getServed()
{
    cout<<"第"<<this->id<<"号普通客户。"<<endl<<endl;
}

void VIPUser::getServed()
{
    cout<<"第"<<this->id<<"号VIP客户。"<<endl<<endl;
}

void OfficialUser::getServed()
{
    cout<<"第"<<this->id<<"号对公客户。"<<endl<<endl;
}
