#include <iostream>
#include <string.h>
using namespace std;

int NativeStrMatching(const string & T, const string & P)
{
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
           // return (t-plen+1);
           cout<<T<<"中第"<<t - plen + 1<<"个开始匹配到"<<P<<endl;
        }
        else
            return 0;
        if( t < tlen)
        {
            t = t-p+1; p = 0;
        }
        else
            break;
    }
    return 0;

}

int main()
{
    string a,b;
    cout<<"依次输入目标串和模式串"<<endl;
    cin>>a;
    cin>>b;
    NativeStrMatching(a,b);
    return 0;
}
