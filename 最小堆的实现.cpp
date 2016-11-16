
class MinHeap
{ 		            // ��С���ඨ��
private:
	int *heapArray;			// ��Ŷ����ݵ�����
	int CurrentSize;			// ��ǰ����Ԫ����Ŀ
	int MaxSize;			// ���������ɵ����Ԫ����Ŀ
	void swap(int pos_x, int pos_y);	// ����λ��x��y��Ԫ��
	void BuildHeap();			// ����
public:
    MinHeap(const int n);			// ���캯����n��ʾ �ѵ����Ԫ����Ŀ
	virtual ~MinHeap(){delete []heapArray;}; 	// ��������
	bool isEmpty( );				// ����ѿգ��򷵻���
    bool isLeaf(int pos) const;	    		// �����Ҷ��㣬����TRUE
  	int leftchild(int pos) const;	   		// ��������λ��
  	int rightchild(int pos) const;		// �����Һ���λ��
  	int parent(int pos) const;			// ���ظ����λ��
	bool Insert(const int& newNode);		// ����в�����Ԫ��newNode
	int& RemoveMin();			// �ӶѶ�ɾ����Сֵ
    bool Remove(int pos, int& node); 		// ɾ�������±��Ԫ��
	void SiftUp(int position);		 // ��position���Ͽ�ʼ������ʹ���г�Ϊ��
	void SiftDown(int left);         	// ����ɸѡ������left��ʾ��ʼ����������±�
};

MinHeap::MinHeap(const int n)  {
	if (n <= 0)     return;
	CurrentSize = 0;
	MaxSize = n;				// ��ʼ��������Ϊn
	heapArray = new int[MaxSize];		// �����ѿռ�
	BuildHeap();                                                    // �˴����ж�Ԫ�صĸ�ֵ����
}

bool MinHeap::isLeaf(int pos) const  {
	return ( pos >= CurrentSize/2) && (pos < CurrentSize);
}


int MinHeap::leftchild(int pos) const  {
	return 2*pos + 1;					 	// ��������λ��
}

int MinHeap::rightchild(int pos) const  {
	return 2*pos + 2;					   	// �����Һ���λ��
}

int MinHeap::parent(int pos) const  {
	return (pos-1)/2;				   		// ���ظ����λ��
}


void MinHeap::SiftUp(int position)  {
     // ��position���Ͽ�ʼ����
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
    int i = left;			// ��ʶ�����
    int j = leftchild(i); 			// ��ʶ�ؼ�ֵ��С���ӽ��
    int temp = heapArray[i];		// ���游���
    while (j < CurrentSize)
    {       		// ��ɸ
        if ( (j < CurrentSize-1) && (heapArray[j]>heapArray[j + 1]))
                                   //�������ӽ�㣬��С�����ӽ��
            j++;							// jָ�����ӽ��
        if (temp>heapArray[j])
        {  //�����������ӽڵ��ֵ�򽻻�λ��
            heapArray[i] = heapArray[j];
            i = j;
            j = leftchild(j);
        }
        else break;  //�������㣬����
    }
    heapArray[i] = temp;
}

                                                         // ����
void MinHeap::BuildHeap()  {
	for (int i = CurrentSize/2-1; i >= 0; i--)               // ��������ɸѡ����
		SiftDown(i);
}

bool MinHeap::Insert(const int& newNode)  {  	                      // ����в�����Ԫ��newNode
	if (CurrentSize == MaxSize)	return FALSE;                        // �ѿռ��Ѿ���
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);					// ���ϵ���
	CurrentSize++;
	return TRUE;
}



int& MinHeap::RemoveMin()
{	// �ӶѶ�ɾ����Сֵ
	if (CurrentSize == 0)
	{
		cout<< "Can't Delete";		// ����RemoveMin֮ǰ����Ҫ�ж϶ѷǿ�
		exit(1) ;
	}
	else
	{
		swap(0,--CurrentSize);	                 // �����Ѷ������һ��Ԫ��
		if (CurrentSize>1)      SiftDown(0);          // �ӶѶ���ʼɸѡ
		return heapArray[CurrentSize];
	}
}

bool MinHeap::Remove(int pos, int& node)
{   	// ɾ�������±��Ԫ��
	if ( (pos < 0) || (pos >= CurrentSize))     return false;
	node = heapArray[pos];
	heapArray[pos] = heapArray[--CurrentSize];	// ������Ԫ��ֵ���ɾ��λ�õ�Ԫ��
    if (heapArray[parent(pos)] > heapArray[pos])
		SiftUp(pos);			// ��ǰԪ��С�ڸ���㣬��Ҫ��������
	else SiftDown(pos);			// ��ǰԪ�ش��ڸ���㣬����ɸ
	return true;
}

