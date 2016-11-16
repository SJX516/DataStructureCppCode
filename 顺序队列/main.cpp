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
    cout<<"当前顶端元素为："<<temp<<endl;
    m.EnQueue(4);
    m.GetFront(temp);
    cout<<"当前顶端元素为："<<temp<<endl;
    return 0;
}
