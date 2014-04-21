#include<iostream>
using namespace std;

#ifndef trans_H
#define trans_H
#include<string>

class transaction
{
    public:
        string transdate;
        string transdesc;
        double transamt;
        double withdraw;
        double trbalance;
        double deposit;
        transaction()
        {

        }
        transaction(const string& date, const string& description, const double& amount)
        {
            transdate=date;
            transdesc=description;
            transamt=amount;
            if(description=="Deposit" || description=="OPENING BALANCE")
            {
                deposit=amount;
            }
            else
            {
                withdraw=amount;
            }
        }
};



#endif
