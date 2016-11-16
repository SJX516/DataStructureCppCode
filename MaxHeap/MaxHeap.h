#ifndef _MAXHEAP_H
#define _MAXHEAP_H


class MaxHeap
{
private:
	int * pHeapArray;			// 存放堆数据的数组
	int iCurrentSize;			// 当前堆中元素数目
	int iMaxSize;			    //堆所能容纳的最大元素数目
	void swap(int pos_x, int pos_y);	// 交换位置x和y的元素
	void buildHeap();			        // 建堆
public:
    MaxHeap(int n = 10);			    // 构造函数，n表示 堆的最大元素数目
	virtual ~MaxHeap(){ delete []pHeapArray; }  	// 析构函数
	bool isEmpty( );				        // 如果堆空，则返回真
    bool isLeaf(int pos) const;	    		// 如果是叶结点，返回TRUE
  	int getLeftChildPos(int pos) const;	   		// 返回左孩子位置
  	int getRightChildPos(int pos) const;		    // 返回右孩子位置
  	int getParentChildPos(int pos) const;			    // 返回父结点位置
  	void print();
  	void printTree();
	bool insertNum(const int& newNode);		// 向堆中插入新元素newNode
	int  removeMax();			            // 从堆顶删除最小值
    bool remove(int pos, int& node); 		// 删除给定下标的元素
	void siftUp(int position);		        // 从position向上开始调整，使序列成为堆
	void siftDown(int left);         	    // 向下筛选，参数left表示开始处理的数组下标
};


#endif // _MAXHEAP_H

