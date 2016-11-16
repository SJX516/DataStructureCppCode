#ifndef _LISTSTACK_H
#define _LISTSTACK_H
#include "Stack.h"
#include<iostream>
using namespace std;

template <class T>
class LinkNode
{
public:
    T data;
    LinkNode<T> * link;
    LinkNode(const T & el, LinkNode<T> * ptr = 0)
    {
        data = el;
        link = ptr;
    }
};

template <class T>
class LinkStack:public Stack<T>
{
private:
    LinkNode <T> * top;
    int size;
public:
    LinkStack(int s = 0)
    {
        top = NULL;
        size = 0;
    }
    ~LinkStack()
    {
        Clear();
    }

    void Clear()
    {
        while ( top != NULL )
        {
            LinkNode<T> *tmp = top;
            top = top->link;
            delete tmp;
        }
        size = 0;
    }

    bool Push(const T item)
    {
        LinkNode<T> * tmp = new LinkNode<T>(item,top);
        top = tmp;
        size++;
        return true;
    }

    bool Pop(T & item)
    {
        LinkNode<T> *tmp;
        if(size == 0)
        {
            cout<<"栈为空，不能执行出栈操作"<<endl;
            return false;
        }
        item = top->data;
        tmp = top->link;
        delete top;
        top = tmp;
        size--;
        return true;
    }

    bool Top(T & item)
    {
        if(size == 0 )
        {
            cout<<"栈为空，不能读取栈顶元素" <<endl;
            return false;
        }
        item = top->data;
        return true;
    }

};

#endif
