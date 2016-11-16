#ifndef _BANKWINDOW_H
#define _BANKWINDOW_H

class BankWindow
{
public:
    int id;
    void HandleUser();
};

class NormalBankWindow:public BankWindow
{
public:
    void HandleUser();
};

class VIPBankWindow:public BankWindow
{
public:
    void HandleUser();
};

class OfficalBankWindow:public BankWindow
{
public:
    void HandleUser();
};

#endif
