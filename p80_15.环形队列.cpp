
#include <iostream>
using namespace std;

class ArrayQueue
{
private:
    int maxsize;
    int front;
    int rear;
    int tag;
    int * queue;
public:
    ArrayQueue(int size)
    {
        maxsize = size + 1;
        queue = new int[maxsize];
        front = rear = 0;
        tag = 0;
    }

    ~ArrayQueue()
    {
        delete []queue;
    }
    void Clear()
    {
        front = rear;
        tag = 0;
    }
    bool EnQueue(const int item)
    {
        if( (rear+1) % maxsize == front )
        {
            cout<<"队列已满，溢出"<<endl;
            return false;
        }
        queue[rear] = item;
        rear = (rear + 1) % maxsize;
        if( (rear+1) % maxsize == front ) tag = 2;
        else tag = 1;
        return true;
    }
    bool DeQueue(int & item)
    {
        if(front == rear)
        {
            cout<<"队列为空"<<endl;
            return false;
        }
        item = queue[front];
        front = (front + 1) % maxsize;
        if(front == rear)
        {
            tag = 0;
        }
        return true;
    }

    bool GetFront(int & item)
    {
        if( front == rear )
        {
            cout<<"队列为空"<<endl;
            return false;
        }
        item = queue[item];
        return true;
    }
    bool IsEmpty()
    {
        if( tag == 0 )
        {
            return  true;
        }
        return false;
    }
    bool IsFull()
    {
        if( tag == 2)
        {
            return true;
        }
        return false;
    }

};

int main()
{
    int temp;
    ArrayQueue m(3);
    m.EnQueue(1);
    m.EnQueue(2);
    m.EnQueue(3);
    if( !m.IsFull() )
        m.EnQueue(4);
    else m.DeQueue(temp);
    cout<<"当前顶端元素为："<<temp<<endl;
    while( !m.IsEmpty() )
    {
        m.DeQueue(temp);
    }
    m.DeQueue(temp);
    return 0;
}

