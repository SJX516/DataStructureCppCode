#include<iostream>
using namespace std;

template <class T>
class Stack
{
public:
	Stack(){}
	~Stack(){}
	void Clear();              //���ջ
	bool Push( const T item);  //ջ��ѹ�����
	bool Pop(T & item);        //��ȡջ��Ԫ��
	bool Top(T & item);        //��ȡջ��Ԫ�ص�ֵ����ɾ��
	bool IsEmpty();    //�ж�ջ�Ƿ�Ϊ��
	bool IsFUll();             //�ж�ջ�Ƿ�����
	/* data */
};


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
            cout<<"ջΪ�գ�����ִ�г�ջ����"<<endl;
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
            cout<<"ջΪ�գ����ܶ�ȡջ��Ԫ��" <<endl;
            return false;
        }
        item = top->data;
        return true;
    }
    bool IsEmpty()
    {
        if( size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

};


void Change(int num,int x)
{
    LinkStack<int> p;
    int temp;
    while( num >= x )
    {
        temp = num % x;
        num = num / x;
        p.Push(temp);
    }
    cout<<num;
    while(!p.IsEmpty())
    {
        p.Pop(temp);
        cout<<temp;
    }

}

int main()
{
    int a,b;
    cout<<"����һ��ʮ��������"<<endl;
    cin>>a;
    cout<<"������ϣ��ת���ɵĽ��ƣ�"<<endl;
    cin>>b;
    Change(a,b);
    return 0;
}

