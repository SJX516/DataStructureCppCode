#include<iostream>
using namespace std;
//直接插入
//template <class Record>
void InsertSort (int Array[], int n)  {
    //Array[]为待排序数组，n为数组长度
	int TempRecord;	// 临时变量
	for (int i=1; i<n; i++)  {	// 依次插入第i个记录
		TempRecord = Array[i];
		//从i开始往前寻找记录i的正确位置
		int j = i-1;
          //将那些大于等于记录i的记录后移
	      while ((j>=0) &&   (TempRecord < Array[j])) {
		   Array[j+1] = Array[j];	 j = j - 1;
		}
		//此时j后面就是记录i的正确位置，回填
	       Array[j+1] = TempRecord;
	}
	for(int tt=0;tt<n;tt++)
        cout<<Array[tt]<<'\t';
    cout<<endl;
}
//折半插入
void BinaryInsertSort(int R[],int n)
{  for(int i=1; i<n; i++)  //共进行n-1次插入
  {	  int left=0,right=i-1;int temp=R[i];
    while(left<=right)
	{       int middle=(left+right)/2;      //取中点
                    if(temp<R[middle]) right=middle-1;
                                       //取左区间
                   else
                      left=middle+1;
               }           //取右区间
	     for(int j=i-1;j>=left;j--)
	            R[j+1]=R[j];    //元素后移空出插入位
	  R[left]=temp;
             }
             for(int tt=0;tt<n;tt++)
        cout<<R[tt]<<'\t';
    cout<<endl;
}
//希尔插入
//template <class T >
void ShellSort (int Vector[], int arrSize  ) {
    int temp,j;
    int gap = arrSize / 2;  //gap是子序列间隔
    while ( gap != 0 ) {	          //循环,直到gap为零
        for ( int i = gap; i < arrSize; i++) {
            temp = Vector[i];	//直接插入排序
            for (j = i; j >= gap; j -= gap )
                if ( temp < Vector[j-gap] )
                    Vector[j] = Vector[j-gap];
                else break;
              Vector[j] = temp;
        }
        gap = ( int ) ( gap / 2 );
    }
    for(int tt=0;tt<arrSize;tt++)
        cout<<Vector[tt]<<'\t';
    cout<<endl;
}
//冒泡
//template <class Record>
void BubbleSort(int Array[], int n)  {
	bool NoSwap;			// 是否发生了交换的标志
	int i, j,temp;
	for (i = 0; i < n-1; i++)  {
		NoSwap = true;		// 标志初始为真
		for (j = n-1; j>0; j--)
		       if (Array[j] < Array[j-1])  {// 判断是否逆置
			//swap(Array, j, j-1);	// 交换逆置对
			temp=Array[j];
			Array[j]=Array[j-1];
			Array[j-1]=temp;
			NoSwap = false;	// 发生了交换，标志变为假
		        }
    		if (NoSwap) 		// 没发生交换，则排好序
		       return;
	}
	for(i=0;i<n;i++)
        cout<<Array[i]<<'\t';
    cout<<endl;
}
//快排
int Partition(int Array[], int first, int last){
   int low = first+1,high=last;
   int pivot = Array[first];
	  while(low <= high){  //在作为快排序的子程序时不用
		while(low <= high && Array[low] <pivot)
			low++;
		while(low <= high && Array[high] > pivot)
			high --;
		 if(low<high) swap(Array[high--] , Array[low++]);
              else low++;}
    swap(Array[first],Array[high]);
    return high; }
void QuickSort(int Array[], int low, int high){
	int PivotLocation;
  	if(low < high){
	     PivotLocation=Partition(Array, low, high);
      QuickSort(Array, low, PivotLocation-1);
      QuickSort(Array, PivotLocation+1, high);
  	}
}

int main()
{
    int Array1[10]={4,5,3,2,7,9,0,8,1,6};
    int Array2[10]={4,5,3,2,7,9,0,8,1,6};
    int Array3[10]={4,5,3,2,7,9,0,8,1,6};
    int Array4[10]={4,5,3,2,7,9,0,8,1,6};
    int Array5[10]={4,5,3,2,7,9,0,8,1,6};
    InsertSort(Array1,10);//直接插入
    BinaryInsertSort(Array2,10);//折半插入
    ShellSort (Array3,10);//希尔排序
    BubbleSort(Array4,10);//冒泡排序
    QuickSort(Array5,0,9);//快排
    for(int i=0;i<10;i++)
        cout<<Array5[i]<<'\t';
    cout<<endl;
    return 0;
}

