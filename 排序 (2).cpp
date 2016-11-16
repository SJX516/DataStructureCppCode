#include <iostream>
#define MAX 32767
using namespace std;
void maopao(int *t, int q){//ð������
	int i, j;
	int temp;
	for (i = 0; i<q-1; i++)//�Ƚ�q-1�� ��������
	for (j = 0; j<q - i-1; j++){//ÿ����ȷ�����һ����� ���� ÿ���ٱ�һ��
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
void charu(int *t, int q){//��������
	int i, j;
	int temp;
	int now;
	int *p = new int[q];//������ʱ���� ���ɾ��
	for (i = 0; i<6; i++){//���鸳��ֵ�����
		p[i] = MAX;
	}
	p[0] = t[0];//�����һ������
	for (i = 1; i<6; i++){//ÿ�η���һ���������ҳ�����Ԫ�ص�Ӧ��λ��
		j = i - 1;
		while (j >= 0 && p[j]>t[i]){//�ȴ�����Ԫ�ش�ĺ���һλ
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = t[i];//Ԫ�ط���
	}
	for (i = 0; i<q; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
	delete p;
}

void xuanzhe(int *t, int n){ //��ѡ������
	int i, j;
	int temp;
	int temp1, temp2;
	for (i = 1; i<n; i++){//���ý������� ����һ��ɸѡ�ȳ������СԪ��
		temp = i - 1;
		for (j = i; j<n; j++){
			if (t[j]<t[temp])
				temp = j;
		}
		if (temp != i - 1){//�������бȱȽ�λС�� ����
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
void half(int *t, int n){//�۰����
	int i, j;
	int temp;
	int left, right, mid;
	int *p = new int[n];//������ɾ��
	for (i = 0; i<6; i++){//��ʼ�����޴�
		p[i] = MAX;
	}
	p[0] = t[0];
	for (i = 1; i<n; i++){//�����㷨�Ĳ����Ż� �۰����
		temp = t[i];
		left = 0;
		right = i - 1;
		while (left <= right){//������� �Ƚ��м�Ԫ���������Ԫ�ش�С ѡ���¸��۰�����
			mid = (left + right) / 2;//�����Ǻ���С������~~~~~~
			if (p[mid]>temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)//��ԭ�����м����ʱ����
			p[j + 1] = p[j];
		p[left] = temp;
	}
	for (i = 0; i<n; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
	delete p;
}
void shell(int *t, int n){//ϣ������
	int d = n / 2;
	int i;
	while (d >= 1){//��n>=2 �����һ������
		for (i = 0; i<d; i++){//����ÿ������d ����һ����������d��ѭ��
			for (int j = i + d; j<n; j += d){// ������dΪ���ð������
				int temp = t[j];
				int k = j - d;
				while (k >= i && t[k]>temp){
					t[k + d] = t[k];
					k -= d;
				}
				t[k + d] = temp;
			}
		}
		d = d / 2;//��������
	}
	for (i = 0; i<n; i++){
		cout << t[i] << ' ';
	}
	cout << endl;
}

int Partition(int *a, int start, int end){
	int left, right;//�Ե�һ��Ԫ����Ϊ����
	left = start + 1; right = end;
	while (left <= right){
		while (left <= right && a[left] <= a[start])left++;//�ҳ��������β����ϴ�С������ĵ�һ��Ԫ��
		while (left <= right && a[right]>a[start])right--;
		if (left<right){//������ʱ��С���� ������
			int temp;
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
		else{//������������� Ҫô��left==right Ҫô��ֱ�ӱȽϵ�rightǰһλ����
			int temp;
			temp = a[start];
			a[start] = a[right];
			a[right] = temp;
		}
	}
	return right;
}

void QuickSort(int *a, int start, int end){//��������
	if (start<end){
		int p = Partition(a, start, end);//���ú����ó����ᣬ������඼����С���Ҳ඼��
		QuickSort(a, start, p - 1);//�����ҵݹ���ÿ���
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
	cout << "    ð������"; maopao(t, 6);
	cout << "    ��������"; charu(b, 6);
	cout << "    ѡ������"; xuanzhe(n, 6);
	cout << "�۰��������"; half(d, 6);
	cout << "    ϣ������"; shell(c, 6);

	
	cout << "    ��������"; QuickSort(a, 0, 5);
	for (int i = 0; i <= 5; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	
	system("pause");
	return 0;
}








