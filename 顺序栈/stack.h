
#ifndef  _STACK_H
#define  _STACK_H

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
	bool IsEmpty(T & item);    //�ж�ջ�Ƿ�Ϊ��
	bool IsFUll();             //�ж�ջ�Ƿ�����
	/* data */
};

#endif

