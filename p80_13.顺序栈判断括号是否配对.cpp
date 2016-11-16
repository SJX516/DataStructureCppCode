#include<iostream>
#include<string>
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
        cout<<"ջ�����"<<endl;
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
        cout<<"ջΪ�գ����ܽ���ɾ������"<<endl;
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
        cout<<"ջΪ�գ����ܶ�ȡջ��Ԫ��"<<endl;
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
    cout<<"����һ�����ʽ��"<<endl;
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
                cout<<"���ʧ�ܣ�����"<<endl;
                return 0;
            }
            else
            {
                bracket.Pop(temp);
                if( temp != expression[i] )
                {
                    cout<<"���ʧ�ܣ�����"<<endl;
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
        cout<<"��Գɹ�������"<<endl;
    }
    else
    {
        cout<<"���ʧ�ܣ�����"<<endl;
    }
    return 0;


}
