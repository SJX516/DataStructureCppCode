#ifndef _TEXTEDITOR_H
#define _TEXTEDITOR_H
#include <iostream>
#include <string>
#include "Linklist.h"
using namespace std;



class TextEditor
{
private:
    LinkList<string> article;
    int line;      //光标所在行数
    int offset;    //行内偏移量
    int total;      //总字符数
    string name;    //文档的名字
public:
    const string & GetName() const;
    void SetName(const string & name);

    int GetCursor( int * pLine = NULL, int * pOffset = NULL )const;   //两个指针变量是为了修改外面的数字
    int MoveCursor( int origin,int offset );  //origin为1代表开始位置
    int SetCursor( int line, int offset );    //为0为当前位置，-1为文件末尾

    string ReadText(int i);
    int AddText ( const string & text);
    int InsertText (string text);

    int FindText(string  text ) ;

    int DeleteText(int line,int offset,int length);

    void WordStat();   //统计字符数

    int NativeStrMatching( string  T,  string  P);

    TextEditor();
    ~TextEditor();

    friend istream & operator>>(istream & in , TextEditor & editor);
    friend ostream & operator<<(ostream & out, TextEditor & editor);

};


#endif









