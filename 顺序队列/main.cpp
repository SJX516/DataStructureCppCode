#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main()
{
    int temp;
    ArrayQueue<int> m(3);
    m.EnQueue(1);
    m.EnQueue(2);
    m.EnQueue(3);
    m.EnQueue(4);
    m.DeQueue(temp);
    cout<<"��ǰ����Ԫ��Ϊ��"<<temp<<endl;
    m.EnQueue(4);
    m.GetFront(temp);
    cout<<"��ǰ����Ԫ��Ϊ��"<<temp<<endl;
    return 0;
}
