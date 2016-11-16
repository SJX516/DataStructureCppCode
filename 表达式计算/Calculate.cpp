#include "Calculate.h"
#include <string.h>
using namespace std;

Calculate::Calculate(string temp)
{
    infix = temp;
    for(int i = 0 ; i < 20; i++)
    {
        ser_num[i]  = 0;
    }
    ser = -1;
}

Calculate::~Calculate()
{
    symbol_stack.Clear();
    suffix_stack.Clear();
}

int Calculate::Get_ser_num()            //把中缀表达式中的数字整合成单个数字，放在ser_num[]中，生成新的中缀表达式
{
    string temp = infix;
    infix = "";
    bool whole_num = false;
    for(int i = 0 ; temp[i] !='\0' ; i++)
    {
        switch( temp[i] )
        {
        case '+': case '-': case '*': case '/': case '(': case ')':
            infix = infix + temp[i];
            whole_num = false;
            break;
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            if( whole_num )
            {
                ser_num[ser] = 10*ser_num[ser]+temp[i]-'0';
            }
            else
            {
                ser++;
                char m = '0'+ser;
                infix = infix + m;
                ser_num[ser] = 10*ser_num[ser]+temp[i]-'0';
                whole_num = true;
            }
            break;
        default:
            infix = "";
            cout<<"表达式中含有不规范的字符，不能识别。"<<endl;
            return 0;
            break;
        }
    }
    if( !Check() )
    {
        cout<<"表达式不符合中缀表达式的格式。"<<endl;
        infix = "";
    }
    return 0;

}
                                      //栈外>栈内时，进栈，不输出
int Calculate::Get_suffix()         //栈外<栈内时，栈顶输出，继续比较，相同时消去
{
    if( infix == "" )
        return 0;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        if( infix[i] >='0' && infix[i] <='C' )
        {
            suffix_stack.Push( infix[i] );
        }
        else
        {
            if( symbol_stack.IsEmpty() )
            {
                symbol_stack.Push( infix[i] );
            }
            else
            {
                char temp = '\0';
                symbol_stack.Top(temp);
                if( Get_priority(infix[i],true) > Get_priority(temp,false) )
                {
                    symbol_stack.Push(infix[i]);
                }
                else if( Get_priority(infix[i],true) < Get_priority(temp,false) )
                {
                    symbol_stack.Pop(temp);
                    suffix_stack.Push(temp);
                    i--;
                }
                else if( Get_priority(infix[i],true) == Get_priority(temp,false) )
                {
                    symbol_stack.Pop(temp);
                }
            }
        }
    }
    char m='\0';
    while( !symbol_stack.IsEmpty() )
    {
        symbol_stack.Pop(m);
        suffix_stack.Push(m);
    }
    return 0;
}

int Calculate::Count()
{
    ListStack<float> result;
    string suffix = "";
    if( infix == "" )
        return 0;
    char m='\0';
    while( !suffix_stack.IsEmpty() )
    {
        suffix_stack.Pop(m);
        suffix = suffix + m;
    }
    int len = suffix.size();
 //   cout<<len<<endl;
    for(int i = len-1; i >= 0; i-- )
    {
        if( suffix[i] >= '0' && suffix[i] <= 'C' )
        {
            result.Push(ser_num[ suffix[i]-'0' ] );
        }
        else
        {
            float s2 ,s1;
            result.Pop(s2);
            result.Pop(s1);
            switch(suffix[i])
            {
            case '+':
                result.Push(s1+s2);
                break;
            case '-':
                result.Push(s1-s2);
                break;
            case '*':
                result.Push(s1*s2);
                break;
            case '/':
                if( s2 == 0 )
                {
                    cout<<"除数不能为0。"<<endl;
                    return 0;
                }
                result.Push(s1/s2);
                break;

            }
        }
    }
    float k = 0;
    result.Top(k);
    cout<<"结果为"<<k<<endl;
    return 0;

}

int Calculate::Get_priority(char temp,bool out_stack)
{
    if( out_stack )
    {
        switch(temp)
        {
        case '(': return 8;
        case ')': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        }
    }
    else
    {
        switch(temp)
        {
        case '(': return 1;
        case ')': return 8;
        case '+': case '-': return 3;
        case '*': case '/': return 5;
        }
    }
    return 0;

}

bool Calculate::Check()
{
    bool judge = true;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        if( !( infix[i] >= '0' && infix[i] <= 'C') && infix[i]!='(' && infix[i]!=')' )
        {
            if( !judge )
            {
                return false;
            }
            judge = false;
        }
        else
        {
            judge = true;
        }
    }
    return true;
}

void Calculate::Print()
{
    for(int i=0 ; infix[i] != '\0' ;i++)
    {
        cout<<infix[i]<<"  ";
    }
    cout<<endl;
    for(int i=0 ; i<=ser; i++)
    {
        cout<<ser_num[i]<<"  ";
    }
    cout<<endl;
}
