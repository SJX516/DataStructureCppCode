
#ifndef _CALCULATE_H
#define _CALCULATE_H
#include <string>
#include <iostream>
#include "ListStack.h"
using namespace std;
class Calculate
{
private:
    int ser;
    string infix;
    int ser_num[20];
    ListStack<char> symbol_stack;
    ListStack<char> suffix_stack;
public:
    Calculate(string temp);
    ~Calculate();
    bool Check();
    int Get_ser_num();
    int Get_suffix();
    int Count();
    int Get_priority(char temp,bool out_stack);
    void Print();

};
#endif
