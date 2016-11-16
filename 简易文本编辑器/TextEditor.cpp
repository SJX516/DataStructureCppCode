#include "TextEditor.h"

TextEditor::TextEditor()
{
    line = offset = total = 0;
    name = "text1";
}

TextEditor::~TextEditor()
{}

int TextEditor::AddText( const string & text)
{
    int m = text.size()-1;
    offset = m;
    line++;
    total += m;
    article.add( text );
    return 0;
}

string TextEditor::ReadText(int i)
{
    return article.read(i);
}

istream & operator>>(istream & in , TextEditor & editor )
{
    string m = "#";
    m += '\n';
    string temp = "";
    char a;
    in.get(a);
    while(  a != '\n')
    {
        temp += a;
        in.get(a);
    }
    temp += '\n';
    while(temp != m)
    {
        editor.AddText(temp);
        temp = "";
        in.get(a);
        while(  a != '\n')
        {
            temp += a;
            in.get(a);
        }
        temp += '\n';
    }
    return in;
}

ostream & operator<<(ostream & out, TextEditor & editor)
{
    string m = "#";
    m += '\n';
    int i = 1;
    string temp = editor.ReadText(i);
    i++;
    while( temp != m )
    {
        out<<temp;
        temp = editor.ReadText(i);
        i++;
    }
    return out;
}

const string & TextEditor::GetName() const
{
    return name;
}

void TextEditor::SetName(const string & name)
{
    this->name = name;
}

int TextEditor::GetCursor(int * pLine , int * pOffset)const
{
    *pLine  = line;
    *pOffset = offset;
    return 0;
}

int TextEditor::SetCursor(int line, int offset)
{
    this->line = line;
    this->offset = offset;
    return 0;
}

int TextEditor::MoveCursor(int origin,int offset1)
{
    switch( origin )
    {
    case 1:
    case -1:
        while( offset1 < 0 )
            offset1 += total;
        while( offset1 > total )
            offset1 -= total;
        break;
    case 0:
    {
        int cursor = 0;
        int i = 1;
        string temp = this->ReadText(i);
        while( i < line )
        {
            cursor += ( temp.size()-1 );
            temp = this->ReadText(i);
            i++;
        }
        cursor += this->offset;
        offset1  = cursor + offset1;
        while( offset1 < 0 )
            offset1 += total;
        while(offset1 > total)
            offset1 -= total;
        break;
    }
    default:
        break;
    }
    int mLine = 1;
    int len  = ReadText(mLine).size()-1;
    while( offset1 > len )
    {
        offset1 -= len;
        mLine++;
        len = ReadText(mLine).size()-1;

    }
    this->offset = offset1;
    this->line = mLine;
    return 0;
}

int TextEditor::InsertText(string text)
{
    int len = text.size() - 2;
    string temp = "" ;
    for(int i = 0; i < len; i++ )
    {
        if( text[i] != '\n' && i != len-1 )
            temp += text[i];
        if(i == len-1 )
        {
            temp += text[i];
            article.Insert(&line,&offset,temp);
            if( text[i] == '\n' )
                total += temp.size()-1;
            else
                total += temp.size();
            temp = "";
        }
        else if ( text[i] == '\n' )
        {
            temp += text[i];
            article.Insert(&line,&offset,temp);
            total += temp.size()-1;
            temp = "";
        }
    }
    return 0;
}


int TextEditor::FindText( string  text)
{
    string m = "#"; m += '\n';
    for(int i = 1; ; i++)
    {
        string temp = ReadText(i);
        if( temp == m )
            break;
        if( NativeStrMatching(temp,text) != -1)
            cout<<endl<<"在"<<i<<"行的第"<<NativeStrMatching(temp,text)<<"个位置匹配到"<<text<<endl;
    }
    return 0;
}

int TextEditor::NativeStrMatching( string  T, string  P)
{
    int p = 0;
    int t = 0;
    int plen = P.length();
    int tlen = T.length();
    if( tlen < plen )
    {
        return -1;
    }
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
        return (t-plen+1);
    }
    else
    return -1;
}

int TextEditor::DeleteText(int line,int offset,int length)
{
    string temp;
    string a = "";
    temp = ReadText(line);
    int len = temp.size()-1;
    if( (offset+length) < len)
    {
        for(int i = 0; i < offset; i++ )
            a += temp[i];
        for(int i = offset+length; i < len; i++)
            a += temp[i];
        a += '\n';
    }
    else
    {
        for(int i = 0; i < offset; i++)
            a += temp[i];
        a += '\n';
    }
    article.ChangeLineData(line,a);
    return 0;
}

void TextEditor::WordStat()
{
    string m = "#";
    m += "\n";
    int word = 0, num = 0,symbol = 0,space = 0;
    for( int i = 1; ;i++ )
    {
        string temp = ReadText(i);
        if( temp == m )
        {
            cout<<endl;
            cout<<"共有"<<total<<"个字符"<<endl;
            cout<<"共有"<<word<<"个字母"<<endl;
            cout<<"共有"<<num<<"个数字"<<endl;
            cout<<"共有"<<symbol<<"个标点"<<endl;
            cout<<"共有"<<space<<"个空格"<<endl;
            break;
        }
        else
        {
            for(int k = 0; k < temp.size()-1; k++)
            {
                if( temp[k] == ' ' )
                    space++;
                else if(  temp[k] >= '0' && temp[k] <= '9' )
                    num++;
                    else if( temp[k] >= 'A' && temp[k] <= 'Z')
                        word++;
                        else if( temp[k] >= 'a' && temp[k] <= 'z' )
                            word++;
                            else
                                symbol++;
            }

        }

    }
}




