#include <iostream>
#include "TextEditor.h"
using namespace std;

int main()
{
    TextEditor art;
    cin>>art;
    cout<<art;


    string text = "";  string m = "#";  string temp = "";
    m += '\n';
    char a;
    for(int k = 0; k<5; )
    {
        bool judge = false;
        cin.get(a);
        if( a == '\n' )
        {
            int len = text.size()-1;
            if( len > 0  && text[len] == '#')
            {
                text += '\n';
                art.InsertText(text);
                cout<<endl;
                cout<<art;
                int zzz,xxx;
                art.GetCursor( &zzz , &xxx );
                cout<<endl;
                cout<<"line"<<zzz<<"   offset"<<xxx<<endl;
                k++;
                judge = true;
            }
        }
        if( judge )
        {
            text = "";
            if( k == 1)
            {
                int line,offset;
                cout<<endl<<"������ϣ��������ڵ��к�ƫ����:"<<endl;
                cin>>line;  cin>>offset; cin.get();
                art.SetCursor(line,offset);
            }
            else if( k == 2 || k == 3 || k == 4)
            {
                int origin,offset;
                cout<<endl<<"������ϣ�����Ĳο�λ�ú�ƫ������"<<endl;
                cin>>origin; cin>>offset; cin.get();
                art.MoveCursor(origin,offset);
            }

        }
        else
        {
            text += a;
        }
    }

    string text2;
    cout<<endl<<"������Ҫ�ҵ�string��"<<endl;
    cin>>text2;
    art.FindText(text2);
    cout<<endl<<"����������Ҫɾ����������ƫ�����ͳ���"<<endl;
    int a1,b,c;
    cin>>a1;
    cin>>b;
    cin>>c;
    art.DeleteText(a1,b,c);
    cout<<endl;
    cout<<art;

    art.WordStat();
    return 0;
}
