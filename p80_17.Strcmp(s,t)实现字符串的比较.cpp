#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;
int Strcmp(string s1, string s2)
{
    int count = 0;
    while( s1[count] !='\0' && s2[count] != '\0')
    {
        if( s1[count] > s2[count] )
            return 1;
        else if( s1[count] < s2[count] )
            return -1;
        count++;
    }
    if(s1[count] =='\0' && s2[count] != '\0' )
        return -1;
    else if( s1[count] !='\0' && s2[count] == '\0')
        return 1;
    return 0;
}

int main()
{
    string m;
    string n;
    cout<<"依次输入两个字符串"<<endl;
    cin>>m;
    cin>>n;
    cout<<m;
    switch( Strcmp(m,n) )
    {
    case 1:  cout<<" > "; break;
    case 0:  cout<<" = "; break;
    case -1:  cout<<" < "; break;
    }
    cout<<n<<endl;
    return 0;
}
