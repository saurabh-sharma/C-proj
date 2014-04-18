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
 //   custom* createcustomer(string& uname,tring& uid,string& upin)
    {
        custom* obj=new custom;
        obj->custname=uname;
        obj->id=uid;
        obj->pin=upin;
        //return obj;
    }
};
custom c[2];

#endif
