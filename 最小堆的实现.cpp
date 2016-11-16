
class MinHeap
{ 		            // 最小堆类定义
private:
	int *heapArray;			// 存放堆数据的数组
	int CurrentSize;			// 当前堆中元素数目
	int MaxSize;			// 堆所能容纳的最大元素数目
	void swap(int pos_x, int pos_y);	// 交换位置x和y的元素
	void BuildHeap();			// 建堆
public:
    MinHeap(const int n);			// 构造函数，n表示 堆的最大元素数目
	virtual ~MinHeap(){delete []heapArray;}; 	// 析构函数
	bool isEmpty( );				// 如果堆空，则返回真
    bool isLeaf(int pos) const;	    		// 如果是叶结点，返回TRUE
  	int leftchild(int pos) const;	   		// 返回左孩子位置
  	int rightchild(int pos) const;		// 返回右孩子位置
  	int parent(int pos) const;			// 返回父结点位置
	bool Insert(const int& newNode);		// 向堆中插入新元素newNode
	int& RemoveMin();			// 从堆顶删除最小值
    bool Remove(int pos, int& node); 		// 删除给定下标的元素
	void SiftUp(int position);		 // 从position向上开始调整，使序列成为堆
	void SiftDown(int left);         	// 向下筛选，参数left表示开始处理的数组下标
};

MinHeap::MinHeap(const int n)  {
	if (n <= 0)     return;
	CurrentSize = 0;
	MaxSize = n;				// 初始化堆容量为n
	heapArray = new int[MaxSize];		// 创建堆空间
	BuildHeap();                                                    // 此处进行堆元素的赋值工作
}

bool MinHeap::isLeaf(int pos) const  {
	return ( pos >= CurrentSize/2) && (pos < CurrentSize);
}


int MinHeap::leftchild(int pos) const  {
	return 2*pos + 1;					 	// 返回左孩子位置
}

int MinHeap::rightchild(int pos) const  {
	return 2*pos + 2;					   	// 返回右孩子位置
}

int MinHeap::parent(int pos) const  {
	return (pos-1)/2;				   		// 返回父结点位置
}


void MinHeap::SiftUp(int position)  {
     // 从position向上开始调整
	int temppos = position;
	int temp = heapArray[temppos];
	while ( (temppos>0) && ( heapArray[parent(temppos)] > temp ) )
	{
		heapArray[temppos] = heapArray[parent(temppos)];
		temppos = parent(temppos);
	}
	heapArray[temppos] = temp;
}

void MinHeap::SiftDown(int left)
{
    int i = left;			// 标识父结点
    int j = leftchild(i); 			// 标识关键值较小的子结点
    int temp = heapArray[i];		// 保存父结点
    while (j < CurrentSize)
    {       		// 过筛
        if ( (j < CurrentSize-1) && (heapArray[j]>heapArray[j + 1]))
                                   //若有右子结点，且小于左子结点
            j++;							// j指向右子结点
        if (temp>heapArray[j])
        {  //若父结点大于子节点的值则交换位置
            heapArray[i] = heapArray[j];
            i = j;
            j = leftchild(j);
        }
        else break;  //堆序满足，跳出
    }
    heapArray[i] = temp;
}

                                                         // 建堆
void MinHeap::BuildHeap()  {
	for (int i = CurrentSize/2-1; i >= 0; i--)               // 反复调用筛选函数
		SiftDown(i);
}

bool MinHeap::Insert(const int& newNode)  {  	                      // 向堆中插入新元素newNode
	if (CurrentSize == MaxSize)	return FALSE;                        // 堆空间已经满
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);					// 向上调整
	CurrentSize++;
	return TRUE;
}



int& MinHeap::RemoveMin()
{	// 从堆顶删除最小值
	if (CurrentSize == 0)
	{
		cout<< "Can't Delete";		// 调用RemoveMin之前，需要判断堆非空
		exit(1) ;
	}
	else
	{
		swap(0,--CurrentSize);	                 // 交换堆顶和最后一个元素
		if (CurrentSize>1)      SiftDown(0);          // 从堆顶开始筛选
		return heapArray[CurrentSize];
	}
}

bool MinHeap::Remove(int pos, int& node)
{   	// 删除给定下标的元素
	if ( (pos < 0) || (pos >= CurrentSize))     return false;
	node = heapArray[pos];
	heapArray[pos] = heapArray[--CurrentSize];	// 用最后的元素值替代删除位置的元素
    if (heapArray[parent(pos)] > heapArray[pos])
		SiftUp(pos);			// 当前元素小于父结点，需要上升调整
	else SiftDown(pos);			// 当前元素大于父结点，向下筛
	return true;
}

