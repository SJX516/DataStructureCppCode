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
    int line;      //�����������
    int offset;    //����ƫ����
    int total;      //���ַ���
    string name;    //�ĵ�������
public:
    const string & GetName() const;
    void SetName(const string & name);

    int GetCursor( int * pLine = NULL, int * pOffset = NULL )const;   //����ָ�������Ϊ���޸����������
    int MoveCursor( int origin,int offset );  //originΪ1����ʼλ��
    int SetCursor( int line, int offset );    //Ϊ0Ϊ��ǰλ�ã�-1Ϊ�ļ�ĩβ

    string ReadText(int i);
    int AddText ( const string & text);
    int InsertText (string text);

    int FindText(string  text ) ;

    int DeleteText(int line,int offset,int length);

    void WordStat();   //ͳ���ַ���

    int NativeStrMatching( string  T,  string  P);

    TextEditor();
    ~TextEditor();

    friend istream & operator>>(istream & in , TextEditor & editor);
    friend ostream & operator<<(ostream & out, TextEditor & editor);

};


#endif









