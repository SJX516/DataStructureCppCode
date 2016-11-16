
#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H
#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
class ArrayStack:public Stack<T>
{
private:
	int maxsize;
	int top;
	T * st;
public:
	ArrayStack(int size);
	ArrayStack();
	void Clear();
	bool Push(const T item);
	bool Pop(T & item);
	bool Top(T & item);
	~ArrayStack();
	/* data */
};

template <class T>
ArrayStack<T>::ArrayStack(int size)
{
    maxsize = size;
    top = -1;
    st = new T[maxsize];
}

template <class T>
ArrayStack<T>::ArrayStack()
{
    top = -1;
}

template <class T>
void ArrayStack<T>::Clear()
{
    top = -1;
}

template <class T>
bool ArrayStack<T>::Push(const T item)
{
    if( top == maxsize-1 )
    {
        cout<<"栈满溢出"<<endl;
        return false;
    }
    else
    {
        st[++top] = item;
        return true;
    }
}

template <class T>
bool ArrayStack<T>::Pop(T & item)
{
    if( top == -1 )
    {
        cout<<"栈为空，不能进行删除操作"<<endl;
        return false;
    }
    else
    {
        item = st[top--];
        return false;
    }
}

template <class T>
bool ArrayStack<T>::Top(T & item)
{
    if(top == -1)
    {
        cout<<"栈为空，不能读取栈顶元素"<<endl;
        return false;
    }
    else
    {
        item = st[top];
        return true;
    }
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
    delete []st;
}

#endif

