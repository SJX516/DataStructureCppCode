#include<iostream>
using namespace std;

template <class T>
class Stack
{
public:
	Stack(){}
	~Stack(){}
	void Clear();              //清空栈
	bool Push( const T item);  //栈的压入操作
	bool Pop(T & item);        //读取栈顶元素
	bool Top(T & item);        //读取栈顶元素的值但不删除
	bool IsEmpty();    //判断栈是否为空
	bool IsFUll();             //判断栈是否已满
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
    cout<<"输入一个十进制数："<<endl;
    cin>>a;
    cout<<"输入你希望转换成的进制："<<endl;
    cin>>b;
    Change(a,b);
    return 0;
}

