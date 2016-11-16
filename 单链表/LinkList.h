#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>
#include <string>
using namespace std;
template<class T>
class LinkNode
{
public:
    T data;                        //数据域
    LinkNode<T> * link;            //指向后继指针的节点
};

template<class T>
class LinkList
{
private:
    LinkNode<T> *head;
    LinkNode<T> *current;
    int size;
public:
    LinkList()
    {
        head = current = NULL;
        size = 0;
    }
    ~LinkList()
    {
        LinkNode<T> * temp = head;
        while(head != NULL)
        {
            head = head->link;
            delete temp;
            temp = head;
        }
    }
    void add(T a)
    {
        LinkNode<T> * temp = new LinkNode<T>;
        temp->data = a;
        temp->link = NULL;
        if( size == 0 )
        {
            head = current = temp;
            size++;
        }
        else
        {
            current->link = temp;
            current = temp;
            size++;
        }
    }

    T read(int i)
    {
        string m = "#";
        m += '\n';
        LinkNode<T> * temp = head;
        if( i > size )
            return m;
        for(int k = 1; k < i; k++)
            temp = temp->link;
        return temp->data;

    }

    void ChangeLineData(int line, string temp)
    {
        LinkNode<T> * ptemp = head;
        for(int k = 1; k < line; k++)
            ptemp = ptemp->link;
        ptemp->data = temp;

    }

    void AddInLine(int line,string temp)
    {
        LinkNode<T> * ptemp = head;
        LinkNode<T> * ptemp1 = new LinkNode<T>;
        ptemp1->data = temp;
        LinkNode<T> * ptemp2 = head;
        for(int k = 1; k < line-1; k++)
            ptemp = ptemp->link;
        ptemp2 = ptemp->link;
        ptemp->link = ptemp1;
        ptemp1->link = ptemp2;
        size++;
    }

    void Insert(int * pline,int * poffset, string temp)
    {
        string  str_line = read(*pline);
        int len = str_line.size();
        string a = "";
        string b = "";
        for(int i = 0; i < len; i++)
        {
            if( i < *poffset )
                a += str_line[i];
            else
                b += str_line[i];
        }
        int t_len = temp.size();
        if( temp[t_len-1] != '\n' )
        {
            a += temp;
            a += b;
            ChangeLineData(*pline,a);
            *poffset = a.size() - b.size();
        }
        else
        {
            a += temp;
            ChangeLineData(*pline,a);
            AddInLine( (*pline)+1 , b );
            (*pline) ++;
            *poffset = 0;
        }
    }

};

#endif
