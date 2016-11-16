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

int KMPStrMatching(string T,string P,int * N,int startIndex)
{
    int lastIndex = T.size() - P.size();
    if( ( lastIndex - startIndex ) < 0 )    //若startIndex过大；则无法匹配成功
        return -1;
    int i;  int j = 0;                     //分别指向T，P内部字符的游标
    for( i = startIndex ; i < T.size(); i++)
    {
        while( P[j] != T[i] && j > 0 )
            j = N[j-1];
        if( P[j] == T[i] )                //当P的第j位和T的第i位相同时，则继续
            j++;
        if( j == P.size() )
            return ( i-j+1 );             //匹配成功，返回该T子串的开始位置
    }
    return -1;
}

int main()
{
    string a;
    string b;
    cout<<"依次输入目标串和模式串"<<endl;
    cin>>a;
    cin>>b;
    int * n = Next(b);
    cout<<a<<"中第"<<KMPStrMatching(a,b,n,0)+1<<"个开始匹配到"<<b<<endl;
    return 0;
}







