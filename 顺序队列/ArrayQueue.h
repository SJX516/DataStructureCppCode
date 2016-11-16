#ifndef _ARRAYQUEUE_H
#define _ARRAYQUEUE_H
#include "Queue.h"
#include <iostream>
using namespace std;

template<class T>
class ArrayQueue:public Queue<T>
{
private:
    int maxsize;
    int front;
    int rear;
    T * queue;
public:
    ArrayQueue(int size)
    {
        maxsize = size + 1;
        queue = new T[maxsize];
        front = rear = 0;
    }
    ~ArrayQueue()
    {
        delete []queue;
    }
    void Clear()
    {
        front = rear;
    }
    bool EnQueue(const T item)
    {
        if( (rear+1) % maxsize == front )
        {
            cout<<"队列已满，溢出"<<endl;
            return false;
        }
        queue[rear] = item;
        rear = (rear + 1) % maxsize;
        return true;
    }
    bool DeQueue(T & item)
    {
        if(front == rear)
        {
            cout<<"队列为空"<<endl;
            return false;
        }
        item = queue[front];
        front = (front + 1) % maxsize;
        return true;
    }
    bool GetFront(T & item)
    {
        if( front == rear )
        {
            cout<<"队列为空"<<endl;
            return false;
        }
        item = queue[item];
        return true;
    }

};

#endif
