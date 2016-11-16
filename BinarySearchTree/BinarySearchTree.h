#ifndef _B_S_T_H
#define _B_S_T_H
#include "BinarySearchTreeNode.h"
#include<iostream>
using namespace std;

template <class T>
class BinarySearchTree
{
private:
    BinarySearchTreeNode<T> * pRoot;
public:
	BinarySearchTree()
	{
	    pRoot = NULL;
	}
	~BinarySearchTree(){}

    BinarySearchTreeNode<T> * getRoot()
    {
        return pRoot;
    }

    void preOrder(BinarySearchTreeNode<T> * root)
    {
        if( root )
        {
            cout<<root->data<<"  ";
            preOrder( root->pLeftChild );
            preOrder( root->pRightChild );
        }
    }
    void inOrder(BinarySearchTreeNode<T> * root)
    {
        if( root )
        {
            inOrder( root->pLeftChild );
            cout<<root->data<<"  ";
            inOrder( root->pRightChild );
        }
    }
    void postOrder(BinarySearchTreeNode<T> * root)
    {
        if( root )
        {
            postOrder( root->pLeftChild );
            postOrder( root->pRightChild );
            cout<<root->data<<"  ";
        }
    }

	void insertNode( const T& value)
	{
	    BinarySearchTreeNode<T> * p = pRoot, * prev = NULL;
	    while( p != NULL )
	    {
	        prev = p;
	        if( p->data < value )
                p = p->pRightChild;
            else
                p = p->pLeftChild;
	    }
	    if( pRoot == NULL )
            pRoot = new BinarySearchTreeNode<T> (value);
        else if( prev->data < value )
            prev->pRightChild = new BinarySearchTreeNode<T> (value);
        else
            prev->pLeftChild = new BinarySearchTreeNode<T> (value);
	}

	BinarySearchTreeNode<T> **  search(BinarySearchTreeNode<T> * &root, T key)
	{
	    BinarySearchTreeNode<T> **  current = &root;
	    while( ( (*current) != NULL) && (key != (*current)->data) )
	    {
	        current = (key < (*current)->data ) ?search((*current)->pLeftChild,key):search((*current)->pRightChild,key);
	    }
	    return current;
	}

	void deleteByMerging( BinarySearchTreeNode<T> ** node)
	{
	    BinarySearchTreeNode<T> * temp = *node;
	    if( ( *node ) == pRoot )
	    {
                node = &pRoot;
	    }
	    if( (*node) != NULL)
	    {
	        if( !(*node)->pRightChild )
                (*node) = (*node)->pLeftChild;
            else if(  (*node)->pLeftChild == NULL )
                (*node) = (*node)->pRightChild;
            else
            {
                temp = (*node)->pLeftChild;
                while(temp->pRightChild != NULL)
                    temp = temp->pRightChild;
                temp->pRightChild = (*node)->pRightChild;
                temp = (*node);
                (*node) = (*node)->pLeftChild;
            }
            delete temp;
	    }
	}

	void deleteByCopying( BinarySearchTreeNode<T> ** node)
	{
	    BinarySearchTreeNode<T> * previous, *temp = *node;
	    if( (*node)->pRightChild == NULL )
            (*node) = (*node)->pLeftChild;
        else if((*node)->pLeftChild == NULL )
            (*node) = (*node)->pRightChild;
        else
        {
            temp = (*node)->pLeftChild;
            previous = (*node);
            while( temp->pRightChild != NULL)
            {
                previous = temp;
                temp = temp->pRightChild;
            }
            (*node)->data = temp->data;
            if( previous == (*node) )
                previous->pLeftChild = temp->pLeftChild;
            else
                previous->pRightChild = temp->pLeftChild;
        }
        delete temp;
	}

};


#endif // _B_S_T_H

