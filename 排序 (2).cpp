#include <iostream>
#define MAX 32767
using namespace std;
void maopao(int *t, int q){//冒泡排序
	int i, j;
	int temp;
	for (i = 0; i<q-1; i++)//比较q-1次 大数后置
	for (j = 0; j<q - i-1; j++){//每次能确定最后一个最大 所以 每次少比一个
		if (t[j]>t[j + 1]){
			temp = t[j];
			t[j] = t[j + 1];
			t[j + 1] = temp;
		}
	}
	for (i = 0; i<q; i++){
		cout << t[i] << ' ';
	}
	cout << endl;
}
void charu(int *t, int q){//插入排序
	int i, j;
	int temp;
	int now;
	int *p = new int[q];//创建临时数组 最后删除
	for (i = 0; i<6; i++){//数组赋初值无穷大
		p[i] = MAX;
	}
	p[0] = t[0];//放入第一个数据
	for (i = 1; i<6; i++){//每次放入一个并排序找出放入元素的应在位置
		j = i - 1;
		while (j >= 0 && p[j]>t[i]){//比待插入元素大的后移一位
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = t[i];//元素放入
	}
	for (i = 0; i<q; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
	delete p;
}

void xuanzhe(int *t, int n){ //简单选择排序
	int i, j;
	int temp;
	int temp1, temp2;
	for (i = 1; i<n; i++){//设置交换变量 进行一轮筛选比出后边最小元素
		temp = i - 1;
		for (j = i; j<n; j++){
			if (t[j]<t[temp])
				temp = j;
		}
		if (temp != i - 1){//如果后边有比比较位小的 交换
			temp1 = t[i - 1];
			t[i - 1] = t[temp];
			t[temp] = temp1;
		}
	}
	for (i = 0; i<n; i++){
		cout << t[i] << ' ';
	}
	cout << endl;

}
void half(int *t, int n){//折半插入
	int i, j;
	int temp;
	int left, right, mid;
	int *p = new int[n];//申请与删除
	for (i = 0; i<6; i++){//初始化无限大
		p[i] = MAX;
	}
	p[0] = t[0];
	for (i = 1; i<n; i++){//插入算法的插入优化 折半查找
		temp = t[i];
		left = 0;
		right = i - 1;
		while (left <= right){//插入查找 比较中间元素与待插入元素大小 选择下个折半区间
			mid = (left + right) / 2;//出发是忽略小数部分~~~~~~
			if (p[mid]>temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)//在原序列中间插入时后移
			p[j + 1] = p[j];
		p[left] = temp;
	}
	for (i = 0; i<n; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
	delete p;
}
void shell(int *t, int n){//希尔排序
	int d = n / 2;
	int i;
	while (d >= 1){//即n>=2 即最后一次排序
		for (i = 0; i<d; i++){//对于每个增量d 都做一次增量长度d的循环
			for (int j = i + d; j<n; j += d){// 以增量d为间隔冒泡排序
				int temp = t[j];
				int k = j - d;
				while (k >= i && t[k]>temp){
					t[k + d] = t[k];
					k -= d;
				}
				t[k + d] = temp;
			}
		}
		d = d / 2;//增量减半
	}
	for (i = 0; i<n; i++){
		cout << t[i] << ' ';
	}
	cout << endl;
}

int Partition(int *a, int start, int end){
	int left, right;//以第一个元素作为中轴
	left = start + 1; right = end;
	while (left <= right){
		while (left <= right && a[left] <= a[start])left++;//找出左右两段不符合大小与中轴的第一个元素
		while (left <= right && a[right]>a[start])right--;
		if (left<right){//若果此时左还小于右 做交换
			int temp;
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
		else{//跳出有两种情况 要么是left==right 要么是直接比较到right前一位结束
			int temp;
			temp = a[start];
			a[start] = a[right];
			a[right] = temp;
		}
	}
	return right;
}

void QuickSort(int *a, int start, int end){//快速排序
	if (start<end){
		int p = Partition(a, start, end);//调用函数得出中轴，中轴左侧都比它小，右侧都大
		QuickSort(a, start, p - 1);//对左右递归调用快排
		QuickSort(a, p + 1, end);
	}

	
}


int main(){
	int t[6] = { 2, 8, 4, 0, 5, 1 };
	int b[6] = { 4, 6, 1, 9, 4, 6 };
	int n[6] = { 2, 5, 3, 8, 6, 9 };
	int d[6] = { 1, 8, 5, 3, 6, 4 };
	int c[6] = { 4, 2, 7, 5, 9, 8 };
	int a[6] = { 5, 4, 1, 2, 8, 7 };
	cout << "    冒泡排序"; maopao(t, 6);
	cout << "    插入排序"; charu(b, 6);
	cout << "    选择排序"; xuanzhe(n, 6);
	cout << "折半插入排序"; half(d, 6);
	cout << "    希尔排序"; shell(c, 6);

	
	cout << "    快速排序"; QuickSort(a, 0, 5);
	for (int i = 0; i <= 5; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	
	system("pause");
	return 0;
}








