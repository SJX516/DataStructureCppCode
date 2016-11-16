#include<iostream>
using namespace std;

class Node
{
public:
    int iNum[5];
    Node * pNext;
    Node()
    {
        for(int i = 0; i < 5 ; i++)
            iNum[i] = 0;
        pNext = NULL;
    }
    void Nodeprint()
    {
        for(int i = 0; i < 5; i++)
            cout<<iNum[i]<<"  ";
    }
};

class List
{
private:
    Node * pBegin;
public:
    List()
    {
        pBegin = new Node;
    }
    void in( int * data ,int len )
    {
        for(int i = 0; i < 5; i++)
        {
            pBegin->iNum[i] = data[i];
        }
        Node * temp = pBegin;
        for( int i = 5; len - i >= 0 ; i = i+5 )
        {
            temp->pNext = new Node;
            temp = temp->pNext;
            if( len - i >= 5 )
                for(int j = 0; j < 5; j++)
                    temp->iNum[j] = data[i+j];
            else
            {
                for(int j = 0; j < len-i; j++)
                    temp->iNum[j] = data[i+j];
            }
        }
    }

    void print()
    {
        Node * temp = pBegin;
        while( temp != NULL )
        {
            temp->Nodeprint();
            cout<<endl;
            temp = temp->pNext;
        }

    }

    Node * search( int num, int & position )
    {
        position = 0;
        Node * temp = pBegin;
        while( temp != NULL )
        {
            for( position = 0; position < 5; position++)
            {
                if( temp->iNum[position] == num )
                    return temp;
            }
            temp = temp->pNext;
        }
        return temp;
    }

};


int main()
{
    List li;
    int data[13] = {10,12,13,23,45,34,24,17,18,19,36,78,91};
    li.in(data,13);
    li.print();
    int pos = 0;
    Node * temp = li.search(19,pos);
    cout<<endl;
    if( temp!= NULL )
    {
        cout<<"19是   ";
        for(int i = 0; i < 5; i++ )
            cout<<temp->iNum[i]<<"   ";
        cout<<"中的第"<<pos+1<<"个"<<endl;
    }
    else
        cout<<"没有找到"<<endl;

}










