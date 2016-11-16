#include<iostream>
#include<string>
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
	bool IsEmpty();
	~ArrayStack();
	/* data */
};
template <class T>
bool ArrayStack<T>::IsEmpty()
{
    if( top == -1 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
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
int main()
{
    ArrayStack<char> bracket(20);
    string expression;
    cout<<"输入一个表达式："<<endl;
    cin>>expression;
    for(int i = 0 ; expression[i] != '\0'; i++)
    {
        switch(expression[i])
        {
        case '(':
            bracket.Push(')');
            break;
        case '[':
            bracket.Push(']');
            break;
        case '{':
            bracket.Push('}');
            break;
        case ')': case ']': case '}':
            char temp;
            if( bracket.IsEmpty() )
            {
                cout<<"配对失败！！！"<<endl;
                return 0;
            }
            else
            {
                bracket.Pop(temp);
                if( temp != expression[i] )
                {
                    cout<<"配对失败！！！"<<endl;
                    return 0;
                }
            }
            break;
        default:
            break;
        }
    }
    if( bracket.IsEmpty() )
    {
        cout<<"配对成功！！！"<<endl;
    }
    else
    {
        cout<<"配对失败！！！"<<endl;
    }
    return 0;


}
