#include <iostream>
#include "ListStack.h"
using namespace std;

int main()
{
	int temp;
    LinkStack<int> a(4);
    a.Push(0);
    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Top(temp);
    cout<<"当前栈顶元素为"<<temp<<endl;
    a.Pop(temp);
    a.Top(temp);
    cout<<"当前栈顶元素为"<<temp<<endl;
    a.Clear();
    return 0;
}
