#include <iostream>
#include <string>
#include "Calculate.h"
using namespace std;

int main()
{
    string infix;
    cout<<"输入中缀表达式: "<<endl;
    cin>>infix;
    Calculate calculate(infix);
    calculate.Get_ser_num();
    calculate.Get_suffix();
//    calculate.Print();
    calculate.Count();
    return 0;
}
