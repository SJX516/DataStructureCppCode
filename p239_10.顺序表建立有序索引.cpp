#include<iostream>
using namespace std;

class Sort
{
public:
    int data;
    int num;
    Sort()
    {
        data = 0;
        num = 0;
    }
};

void swap(Sort * s1,Sort * s2)
{
    Sort temp;
    temp.data = s2->data;
    temp.num = s2->num;
    s2->data = s1->data;
    s2->num = s1->num;
    s1->data = temp.data;
    s1->num = temp.num;

}

void BubbleSort( Sort * s,int len)
{
    int flag = 0;
    for( int i = 0; i < len; i++)
    {
        flag = 0;
        for(int j = 1; j < len-1;j++ )
        {
            if( s[j].data < s[j-1].data)
            {
                flag = -1;
                swap( &s[j] , &s[j-1] );
            }
        }
        if( flag == 0 )
            return;
    }
}

int main()
{
    int c[6] = {9,6,8,7,5,10};
    Sort s[6];
    for(int i = 0; i < 6; i++)
    {
        s[i].data = c[i];
        s[i].num = i;
    }
    BubbleSort(s,6);
    for(int i = 0; i < 6; i++)
    {
        cout<<s[i].data<<"    "<<s[i].num<<endl;
    }


}
