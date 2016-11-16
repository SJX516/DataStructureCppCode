#ifndef _USER_H
#define _USER_H

class User
{
public:
    int id;
    void getServed();
};

class NormalUser:public User
{
public:
    void getServed();
};

class VIPUser:public User
{
public:
    void getServed();
};

class OfficialUser:public User
{
public:
    void getServed();
};

#endif
