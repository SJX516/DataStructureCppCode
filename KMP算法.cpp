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

int KMPStrMatching(string T,string P,int * N,int startIndex)
{
    int lastIndex = T.size() - P.size();
    if( ( lastIndex - startIndex ) < 0 )    //��startIndex�������޷�ƥ��ɹ�
        return -1;
    int i;  int j = 0;                     //�ֱ�ָ��T��P�ڲ��ַ����α�
    for( i = startIndex ; i < T.size(); i++)
    {
        while( P[j] != T[i] && j > 0 )
            j = N[j-1];
        if( P[j] == T[i] )                //��P�ĵ�jλ��T�ĵ�iλ��ͬʱ�������
            j++;
        if( j == P.size() )
            return ( i-j+1 );             //ƥ��ɹ������ظ�T�Ӵ��Ŀ�ʼλ��
    }
    return -1;
}

int main()
{
    string a;
    string b;
    cout<<"��������Ŀ�괮��ģʽ��"<<endl;
    cin>>a;
    cin>>b;
    int * n = Next(b);
    cout<<a<<"�е�"<<KMPStrMatching(a,b,n,0)+1<<"����ʼƥ�䵽"<<b<<endl;
    return 0;
}







