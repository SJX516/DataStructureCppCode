#ifndef _MAXHEAP_H
#define _MAXHEAP_H


class MaxHeap
{
private:
	int * pHeapArray;			// ��Ŷ����ݵ�����
	int iCurrentSize;			// ��ǰ����Ԫ����Ŀ
	int iMaxSize;			    //���������ɵ����Ԫ����Ŀ
	void swap(int pos_x, int pos_y);	// ����λ��x��y��Ԫ��
	void buildHeap();			        // ����
public:
    MaxHeap(int n = 10);			    // ���캯����n��ʾ �ѵ����Ԫ����Ŀ
	virtual ~MaxHeap(){ delete []pHeapArray; }  	// ��������
	bool isEmpty( );				        // ����ѿգ��򷵻���
    bool isLeaf(int pos) const;	    		// �����Ҷ��㣬����TRUE
  	int getLeftChildPos(int pos) const;	   		// ��������λ��
  	int getRightChildPos(int pos) const;		    // �����Һ���λ��
  	int getParentChildPos(int pos) const;			    // ���ظ����λ��
  	void print();
  	void printTree();
	bool insertNum(const int& newNode);		// ����в�����Ԫ��newNode
	int  removeMax();			            // �ӶѶ�ɾ����Сֵ
    bool remove(int pos, int& node); 		// ɾ�������±��Ԫ��
	void siftUp(int position);		        // ��position���Ͽ�ʼ������ʹ���г�Ϊ��
	void siftDown(int left);         	    // ����ɸѡ������left��ʾ��ʼ����������±�
};


#endif // _MAXHEAP_H

