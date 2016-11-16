#include "MaxHeap.h"
#include <iostream>
#include <math.h>
using namespace std;

MaxHeap::MaxHeap(int n)
{
	if (n <= 0)     return;
	iCurrentSize = 10;
	iMaxSize = n;				        // 初始化堆容量为n
	pHeapArray = new int[iMaxSize];	    // 创建堆空间
	int a[10] = {20,14,35,15,10,80,30,17,12,11};
	for(int i = 0; i < 10; i++)
        pHeapArray[i] = a[i];
	printTree();
	buildHeap();                        // 此处进行堆元素的赋值工作

}

bool MaxHeap::isLeaf(int pos) const
{
	return ( pos >= iCurrentSize/2) && (pos < iCurrentSize);
}
int MaxHeap::getLeftChildPos(int pos) const
{
	return 2*pos + 1;					 	// 返回左孩子位置
}
int MaxHeap::getRightChildPos(int pos) const
{
	return 2*pos + 2;					   	// 返回右孩子位置
}
int MaxHeap::getParentChildPos(int pos) const
{
	return (pos-1)/2;				   		// 返回父结点位置
}
void MaxHeap::swap(int x,int y)
{
    int temp = pHeapArray[x];
    pHeapArray[x] = pHeapArray[y];
    pHeapArray[y] = temp;
}

void MaxHeap::buildHeap()
{
    for(int i = iCurrentSize/2-1; i >= 0 ; i--)
        siftDown( i );
}

void MaxHeap::print()
{
    for(int i = 0; i<iCurrentSize; i++)
        cout<<pHeapArray[i]<<"  ";
    cout<<endl;
}

void MaxHeap::printTree()
{
    int hight = 1;
    int i = 0;
    while( getLeftChildPos(i) < iCurrentSize )
    {
        hight++;
        i = getLeftChildPos(i);
    }
    for( i = 0; i < hight; i++)
    {
        int begin = 0; int next = 1;
        for(int k = hight-i-1; k > 0; k--)
        {
            begin = next;
            next = 2*next+1;
        }
        for(int m = pow(2,i)-1; m < pow(2,i+1)-1 && m < iCurrentSize; m++ )
        {
            if( m == pow(2,i)-1 )
            {
                for(int x = 0; x < begin; x++)
                    cout<<"  ";
                cout<<pHeapArray[m];
            }
            else
            {
                for(int x = 0; x < next; x++)
                    cout<<"  ";
                cout<<pHeapArray[m];
            }
        }
        cout<<endl;

    }
    cout<<endl;

}
void MaxHeap::siftDown(int left)
{
    while( getLeftChildPos(left) < iCurrentSize )
    {
        int leftChildPos = getLeftChildPos(left);
        if( leftChildPos+1 < iCurrentSize && pHeapArray[leftChildPos+1] > pHeapArray[leftChildPos] )
            leftChildPos++;
        if( pHeapArray[left] < pHeapArray[leftChildPos] )
         {
             swap(left,leftChildPos);
             left = leftChildPos;
         }
         else break;
    }
}

void MaxHeap::siftUp(int pos)
{
    while( getParentChildPos( pos ) >= 0)
    {
        int parentPos = getParentChildPos(pos);
        if( pHeapArray[pos] > pHeapArray[parentPos] )
        {
            swap(pos,parentPos);
            pos = parentPos;
        }
        else break;
    }

}

bool MaxHeap::insertNum(const int & newNode)
{
    if (iCurrentSize == iMaxSize)	return false;
    pHeapArray[iCurrentSize] = newNode;
    siftUp(iCurrentSize);
    iCurrentSize++;
    return true;
}

int  MaxHeap::removeMax()
{
    if (iCurrentSize == 0)
	{
		cout<< "Can't Delete";
		return 0;
	}
    else
    {
        swap(0,--iCurrentSize);
        if (iCurrentSize > 1) siftDown(0);
        return pHeapArray[iCurrentSize];
    }

}

bool MaxHeap::remove(int pos,int & node)
{
    if( (pos < 0) || (pos >= iCurrentSize) ) return false;
    node = pHeapArray[pos];
    swap(pos,--iCurrentSize);
    if( pHeapArray[pos] > pHeapArray[getParentChildPos(pos)] )
        siftUp(pos);
    else
        siftDown(pos);
    return true;

}



