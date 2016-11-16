#include<iostream>
#include<string>
using namespace std;
#define null NULL;
class passenger_node
{
public:
    string passenger_name;
    int position;
    passenger_node * panext;
    passenger_node()
    {
        position = 0;
        passenger_name = "";
        panext = null;
    }
};

class passenger
{
public:
    bool seat[5];
    passenger_node * passenger_head;
    passenger();
    int add(string );
    string search(int );
    int del(string );
    void print();
};

void passenger::print()
{
    passenger_node * patemp = passenger_head;
    while( patemp )
    {
        cout<<patemp->passenger_name<<","<<patemp->position<<"   ";
        patemp = patemp->panext;
    }
    cout<<endl;

}

int passenger::add(string name)
{
    passenger_node ** patemp = &passenger_head;
    bool have_seat = false;
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        if( seat[i] )
        {
            have_seat = true;
            break;
        }
    }
    if( !have_seat )
    {
        cout<<"�ú����Ѿ�û����λ��"<<endl;
        return 0;
    }
    if( *patemp )
    {
        while( *patemp )
        {
            if( name < (*patemp)->passenger_name )
            {
                break;
            }
            patemp = &(*patemp)->panext;
        }
        passenger_node * temp2 = *patemp;
        *patemp = new passenger_node;
        (*patemp)->passenger_name = name;
        (*patemp)->panext = temp2;
        (*patemp)->position = i+1;
        seat[i] = false;
    }
    else
    {
        *patemp = new passenger_node;
        (*patemp)->panext = null;
        (*patemp)->passenger_name = name;
        (*patemp)->position = 1;
        seat[0] = false;
    }
    cout<<"Ԥ���ɹ�"<<endl;
}

string passenger::search(int position)
{
    passenger_node * patemp = passenger_head;
    while( patemp )
    {
        if( patemp->position == position )
        {
           return patemp->passenger_name;
        }
        patemp = patemp->panext;
    }
    return "";

}

int passenger::del(string name)
{
    passenger_node ** patemp = &passenger_head;
    while( *patemp )
    {
        if( (*patemp)->passenger_name == name )
        {
             break;
        }
        patemp = &( (*patemp)->panext ) ;
    }
    if(!*patemp)
    {
        cout<<"û�иó˿�"<<endl;
        return 0;
    }
    else
    {
        passenger_node * temp2 = *patemp;
        seat[temp2->position-1] = true;
        *patemp = (*patemp)->panext;
        delete temp2;
        cout<<"ȡ������ɹ�"<<endl;
        return 1;
    }

}

passenger::passenger()
{
    passenger_head = null;
    for(int i = 0 ; i < 5; i++)
    {
        seat[i] = true;
    }
}

class flight_node
{
public:
    passenger peoples;
    flight_node * flnext;
    int flight_num;
    flight_node()
    {
        flight_num = 0;
        flnext = null;
    }
};

class flight
{
private:
    flight_node * flight_head;
public:
    flight();
    void get_the_position(int flight_num,int position);
    void get_the_flight(int flight_num); //��û�У��½�һ��
    void del(int flight_num,string name); //û�иú��࣬û�иó˿Ͷ�Ҫ�ж�
    void add_passenger(int flight_num,string name);
    void print();
};

flight::flight()
{
    flight_head = null;
}

void flight::get_the_position(int flight_num,int position) //����λ���Ƿ�ռ��
{
    flight_node * temp = flight_head;
    while( temp )
    {
        if( temp->flight_num == flight_num )
        {
            break;
        }
        temp = temp->flnext;
    }
    if( temp->peoples.search(position) != "" )
    {
        cout<<"����λ�����ˣ�Ϊ"<<temp->peoples.search(position)<<endl;
    }
    else if(position > 5)
    {
        cout<<"û�и���λ"<<endl;
    }
    else
    {
        cout<<"����λ��û��"<<endl;
    }
}

void flight::get_the_flight(int flight_num) //��û�У��½�һ��
{
    flight_node ** temp = &flight_head;
    if( !*temp )
    {
        flight_head = new flight_node;
        flight_head->flight_num = flight_num;
        flight_head->flnext = null;
    }
    else
    {
        while( *temp )
        {
            if( (*temp)->flight_num == flight_num )
            {
                return ;
            }
            temp = &( (*temp)->flnext );
        }
        *temp = new flight_node;
        (*temp)->flight_num = flight_num;
        (*temp)->flnext = null;
    }


}

void flight::del(int flight_num,string name) //û�иú��࣬û�иó˿Ͷ�Ҫ�ж�
{
    flight_node * fltemp = flight_head;
    while( fltemp )
    {
        if( fltemp->flight_num == flight_num )
        {
            break;
        }
        fltemp = fltemp->flnext;
    }
    if( !fltemp )
    {
        cout<<"û�иú���"<<endl;
    }
    else
    {
        fltemp->peoples.del(name);
    }

}

void flight::add_passenger(int flight_num,string name)
{
    flight_node * fltemp = flight_head;
    while( fltemp )
    {
        if( fltemp->flight_num == flight_num )
        {
            break;
        }
        fltemp = fltemp->flnext;
    }
    fltemp->peoples.add(name);
}

void flight::print()
{
    flight_node * fltemp = flight_head;
    while( fltemp )
    {
        cout<<"����"<<fltemp->flight_num<<"   ";
        fltemp->peoples.print();
        fltemp = fltemp->flnext;
    }

}
int main()
{
    bool over = false;
    int choose;
    string name;
    int position;
    int flight_num;
    flight fl;
    while( !over )
    {
    cout<<endl;
    int judge = 1;
    cout<<endl<<endl<<endl<<"      "
        <<"1.Ԥ��һ��Ʊ"<<endl;

    cout<<endl<<endl<<endl<<"      "
        <<"2.ȡ��Ԥ��"<<endl;

    cout<<endl<<endl<<endl<<"      "
        <<"3.���ĳ��λ�Ƿ�ռ"<<endl;
    cout<<endl<<endl<<endl<<"      "
        <<"4.��ʾ��ǰ���к���ͳ˿�"<<endl;
    cout<<endl<<endl<<endl<<"      "
        <<"5.�˳�"<<endl;
    cin>>choose;
    switch(choose)
    {
    case 1:
        cout<<endl<<endl<<endl;
        cout<<"������ҪԤ���ĺ��ࣺ"<<endl;
        cin>>flight_num;
        cout<<"�������������"<<endl;
        cin>>name;
        fl.get_the_flight(flight_num); //��û�У��½�һ��
        fl.add_passenger(flight_num,name);
        while(judge != 0)
        {
            cout<<"����0�������˵�"<<endl;
            cin>>judge;
        }
        break;
    case 2:
        cout<<endl<<endl<<endl;
        cout<<"�������������"<<endl;
        cin>>name;
        cout<<"������Ԥ���˵ĺ��ࣺ"<<endl;
        cin>>flight_num;
        fl.del(flight_num,name); //û�иú��࣬û�иó˿Ͷ�Ҫ�ж�
        while(judge != 0)
        {
            cout<<"����0�������˵�"<<endl;
            cin>>judge;
        }
        break;
    case 3:
        cout<<endl<<endl<<endl;
        cout<<"������ҪԤ���ĺ��ࣺ"<<endl;
        cin>>flight_num;
        cout<<"��������Ҫ����λ��"<<endl;
        cin>>position;
        fl.get_the_flight(flight_num); //��û�У��½�һ��
        fl.get_the_position(flight_num,position);
        while(judge != 0)
        {
            cout<<"����0�������˵�"<<endl;
            cin>>judge;
        }
        break;
    case 4:
        fl.print();
        while(judge != 0)
        {
            cout<<"����0�������˵�"<<endl;
            cin>>judge;
        }
        break;
    case 5:
        over = true;
        break;
    }
    }
    return 0;
}
