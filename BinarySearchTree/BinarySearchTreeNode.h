#ifndef _B_S_T_N_H
#define _B_S_T_N_H
#include "BinarySearchTree.h"

template <class T>
class BinarySearchTreeNode
{
private:

public:
    T data;
    BinarySearchTreeNode<T> * pLeftChild;
    BinarySearchTreeNode<T> * pRightChild;
	BinarySearchTreeNode()
	{
	    pLeftChild = NULL;
	    pRightChild = NULL;
	}
	BinarySearchTreeNode(const T& value)
	{
	    data = value;
        pLeftChild = NULL;
	    pRightChild = NULL;
	}
	~BinarySearchTreeNode(){}
};


#endif // _B_S_T_N_H

