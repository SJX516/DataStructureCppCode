#ifndef _LINKNODE_H
#define _LINKNODE_H

template<class T>
{
public:
    T data;                        //数据域
    LinkNode<T> * link;            //指向后继指针的节点
};

#endif
