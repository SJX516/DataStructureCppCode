#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q[10];
    int temp;
    cout<<"����10���ڵ����������븺��ֹͣ���롣"<<endl;
    cin>>temp;
    for( ;temp >= 0 ;)
    {
        q[temp].push(temp);
        cin>>temp;
    }
    for(int i = 1; i<10; i++)
    {
        while( !q[i].empty() )
        {
            q[0].push( q[i].front() );
            q[i].pop();
        }
    }
    while( !q[0].empty() )
    {
        cout<<q[0].front()<<"  ";
        q[0].pop();
    }
    cout<<endl;
    return 0;
}
