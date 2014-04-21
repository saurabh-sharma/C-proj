#include<iostream>
#include<iomanip>
using namespace std;

#ifndef custom_H
#define custom_H
#include<string.h>

class custom
{
public:
    string id;
    string custname;
    string pin;
    custom()
    {

    }
    custom(const string& uname,const string& uid,const string& upin)
    {
        custname=uname;
        id=uid;
        pin=upin;
    }
};
custom c[2];

#endif
