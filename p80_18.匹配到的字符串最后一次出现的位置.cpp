#include <iostream>
#include <string.h>
using namespace std;

int NativeStrMatching(const string & T, const string & P)
{
    int temp = 0;
    int p = 0;
    int t = 0;
    int plen = P.length();
    int tlen = T.length();
    if( tlen < plen )
    {
        return 0;
    }
    while (1)
    {
        while( p < plen && t < tlen )
        {
            if( T[t] == P[p] )
            {
                p++; t++;                                          
            }
            else
            {
                t = t - p + 1;
                p = 0;
            }
        }
        if( p >= plen )
        {
           //return (t-plen+1);
           //cout<<T<<"中第"<<t - plen + 1<<"个开始匹配到"<<P<<endl;
           temp = t - plen + 1;
        }
        if( t < tlen)
        {
            t = t-p+1; p = 0;
        }
        else
            break;
    }
    return temp;

}

int main()
{
    string a,b;
    cout<<"依次输入目标串和模式串"<<endl;
    cin>>a;
    cin>>b;
    if( NativeStrMatching(a,b) != 0 )
        cout<<a<<"中最后一次出现"<<b<<"是在第"<<NativeStrMatching(a,b)<<"个位子上";
    else
        cout<<"没有找到"<<endl;
    return 0;
}
