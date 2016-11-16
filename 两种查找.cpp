//Ë³Ğò²éÕÒ ÕÛ°ë²éÕÒ
#include<iostream>
using namespace std;

template<class T>
int Search(T array[], T key, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == key)
			return i;
	}
	return -1;
}

template<class T>
int BiSearch(T array[], T key, int n)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		//cout <<left<<" "<<right<<"  "<< mid<<endl;
		if (key < array[mid])
		{
			right = mid - 1;
		}
		else if (key>array[mid])
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = { 1,2,3,4,5,6,7 };
	cout << a[Search(a, 3, 7)] << endl;
	cout << a[BiSearch(a, 1, 7)] << endl;
	return 0;
}
