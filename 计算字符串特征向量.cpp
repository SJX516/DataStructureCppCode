
#include <iostream>
#include <string>
using namespace std;

int * Next(string p)
{
    int m = p.size();          //模式p的长度
    int * N = new int [m];
    N[0] = 0;
    for(int i = 1; i < m; i++ )     //对p的每一个位置进行分析
    {
        int k = N[i-1];             //第i-1位置的最长前缀串长度
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




