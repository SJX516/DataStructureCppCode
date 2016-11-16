#ifndef _CAR_H
#define _CAR_H
#include <string>
using namespace std;

class Car
{
public:
    string license_plate;
    int time;

    Car( string temp ,int num = 0)
    {
        license_plate = temp;
        time = num;
    }
    ~Car()
    {

    }

};
#endif
