#include<iostream>
using namespace std;
//ֱ�Ӳ���
//template <class Record>
void InsertSort (int Array[], int n)  {
    //Array[]Ϊ���������飬nΪ���鳤��
	int TempRecord;	// ��ʱ����
	for (int i=1; i<n; i++)  {	// ���β����i����¼
		TempRecord = Array[i];
		//��i��ʼ��ǰѰ�Ҽ�¼i����ȷλ��
		int j = i-1;
          //����Щ���ڵ��ڼ�¼i�ļ�¼����
	      while ((j>=0) &&   (TempRecord < Array[j])) {
		   Array[j+1] = Array[j];	 j = j - 1;
		}
		//��ʱj������Ǽ�¼i����ȷλ�ã�����
	       Array[j+1] = TempRecord;
	}
	for(int tt=0;tt<n;tt++)
        cout<<Array[tt]<<'\t';
    cout<<endl;
}
//�۰����
void BinaryInsertSort(int R[],int n)
{  for(int i=1; i<n; i++)  //������n-1�β���
  {	  int left=0,right=i-1;int temp=R[i];
    while(left<=right)
	{       int middle=(left+right)/2;      //ȡ�е�
                    if(temp<R[middle]) right=middle-1;
                                       //ȡ������
                   else
                      left=middle+1;
               }           //ȡ������
	     for(int j=i-1;j>=left;j--)
	            R[j+1]=R[j];    //Ԫ�غ��ƿճ�����λ
	  R[left]=temp;
             }
             for(int tt=0;tt<n;tt++)
        cout<<R[tt]<<'\t';
    cout<<endl;
}
//ϣ������
//template <class T >
void ShellSort (int Vector[], int arrSize  ) {
    int temp,j;
    int gap = arrSize / 2;  //gap�������м��
    while ( gap != 0 ) {	          //ѭ��,ֱ��gapΪ��
        for ( int i = gap; i < arrSize; i++) {
            temp = Vector[i];	//ֱ�Ӳ�������
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
//ð��
//template <class Record>
void BubbleSort(int Array[], int n)  {
	bool NoSwap;			// �Ƿ����˽����ı�־
	int i, j,temp;
	for (i = 0; i < n-1; i++)  {
		NoSwap = true;		// ��־��ʼΪ��
		for (j = n-1; j>0; j--)
		       if (Array[j] < Array[j-1])  {// �ж��Ƿ�����
			//swap(Array, j, j-1);	// �������ö�
			temp=Array[j];
			Array[j]=Array[j-1];
			Array[j-1]=temp;
			NoSwap = false;	// �����˽�������־��Ϊ��
		        }
    		if (NoSwap) 		// û�������������ź���
		       return;
	}
	for(i=0;i<n;i++)
        cout<<Array[i]<<'\t';
    cout<<endl;
}
//����
int Partition(int Array[], int first, int last){
   int low = first+1,high=last;
   int pivot = Array[first];
	  while(low <= high){  //����Ϊ��������ӳ���ʱ����
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
    InsertSort(Array1,10);//ֱ�Ӳ���
    BinaryInsertSort(Array2,10);//�۰����
    ShellSort (Array3,10);//ϣ������
    BubbleSort(Array4,10);//ð������
    QuickSort(Array5,0,9);//����
    for(int i=0;i<10;i++)
        cout<<Array5[i]<<'\t';
    cout<<endl;
    return 0;
}

