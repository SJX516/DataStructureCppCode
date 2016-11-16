
#ifndef  _STACK_H
#define  _STACK_H

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
	bool IsEmpty(T & item);    //判断栈是否为空
	bool IsFUll();             //判断栈是否已满
	/* data */
};

#endif

