#include <iostream>
#include "Stack.h"
#include "arraystack.h"
using namespace std;
int main()
{
	int temp;
    ArrayStack<int> a(4);
    a.Push(0);
    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Top(temp);
    cout<<"��ǰջ��Ԫ��Ϊ"<<temp<<endl;
    a.Pop(temp);
    a.Top(temp);
    cout<<"��ǰջ��Ԫ��Ϊ"<<temp;
    a.Clear();
    return 0;
}
