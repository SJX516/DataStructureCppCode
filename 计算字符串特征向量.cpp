
#include <iostream>
#include <string>
using namespace std;

int * Next(string p)
{
    int m = p.size();          //ģʽp�ĳ���
    int * N = new int [m];
    N[0] = 0;
    for(int i = 1; i < m; i++ )     //��p��ÿһ��λ�ý��з���
    {
        int k = N[i-1];             //��i-1λ�õ��ǰ׺������
        while( k > 0 && p[i] != p[k] )
            k = N[k-1];
        if( p[i] == p[k] )
            N[i] = k+1;
        else
            N[i] = 0;
    }
    return N;
}

int main()
{
    string a;
    cin>>a;
    int * p = Next(a);
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    for(int i = 0; i < a.size(); i++)
    {
        cout<<p[i]<<"   ";
    }
    return 0;
}




