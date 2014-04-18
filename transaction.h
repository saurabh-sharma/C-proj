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
        transaction(const string& date, const string& description, const double& amount)//, const double& withdraw,const double& deposit)
        {
            transaction* transc=new transaction;
            transc->transdate=date;
            transc->transdesc=description;
            transc->transamt=amount;
        //scout<<transc->transamt;
            //transc->trbalance=amount;

            (description=="Deposit")?transc->deposit=amount:transc->withdraw=-amount;

            //transc->deposit=amount;
            //transc->withdraw=-amount;
            //return transc;
        }
};



#endif
