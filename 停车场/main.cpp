#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
#include "Car.h"
int main( )
{
    ifstream fin("data.txt", std::ios::in);
    if( !fin.is_open() )
    {
        cout<<"´ò¿ªÊ§°Ü"<<endl;
    }
    else
    {
    char line[30]={0};
    string name = "";
    string action = "";
    stack<Car *> temp;
    stack<Car *> gallery;
    while( fin.getline( line, sizeof(line) ) )
    {
        Car * temp_car;
        stringstream word(line);
        word >> name;
        word >> action;
        temp_car = new Car(name);
        if( action[0] == 'a' )
        {
            if( gallery.size() == 5 )
            {
                cout<<"Sorry "<< (*temp_car).license_plate<<", the lot is full"<<endl;
            }
            else
                gallery.push( temp_car );
        }
        else if( action[0] == 'd' )
        {
            temp_car = gallery.top();
            while( (*temp_car).license_plate != name && !gallery.empty() )
            {
                (*temp_car).time++;
                temp.push(temp_car);
                gallery.pop();
                if( !gallery.empty() )
                    temp_car = gallery.top();
            }
            if( gallery.empty() )
            {
                cout<<"sorry don't have the car "<<name<<endl;
            }
            else
            {
                cout<<(*temp_car).license_plate<<" was moved "<< (*temp_car).time <<" times while it was here"<<endl;
                delete temp_car;
                gallery.pop();
            }
            while( !temp.empty() )
            {
                temp_car = temp.top();
                temp.pop();
                gallery.push(temp_car);
            }
        }

    }
    while( !gallery.empty() )
    {
        Car * temp_car;
        temp_car = gallery.top();
        cout<<(*temp_car).license_plate<<" was moved "<< (*temp_car).time <<" times while it was here"<<endl;
        delete temp_car;
        gallery.pop();
    }
    }
    fin.clear();
    fin.close();
    return 0;
}







