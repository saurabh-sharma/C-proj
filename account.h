#include<iostream>
#include<iomanip>

using namespace std;

#ifndef account_H
#define account_H


#include "customer.h"
#include "transaction.h"

#include<string.h>

class acnt
{
public:
    string acntno;
    double balance;
    double tdeposit;
    double twithdrawal;
    int tcount;
    custom holder;
    transaction tlist[100];
    void printreport(acnt* acntobj);
    void recorddeposit(acnt* acntobj,transaction *transc);
    void recordwithdraw(acnt* acntobj,transaction *transc);

    acnt()
    {
        acntno="06-3121-1021-0001";
        balance=0;
        tdeposit=0;
        twithdrawal=0;
    }
    acnt (const custom &aholder, const string &aacntno, const string &transdate, const double &abalance=0)
    {
        holder=aholder;
        acntno=aacntno;
        balance=abalance;
        tdeposit=abalance;
        twithdrawal=0;
        tlist[0].transdate = transdate;
        tlist[0].transdesc = "opening balance";
        tlist[0].deposit=abalance;
        tlist[0].trbalance=abalance;
        tlist[0].withdraw=0;
        tlist[0]=transaction(transdate,"OPENING BALANCE",abalance);
        tcount=1;
    }
};
acnt acc;
acnt account[2];
void acnt :: printreport(acnt* acntobj)
{
    cout<<"ACCOUNT SUMMARY  "<<acntobj->acntno<<"-"<<acntobj->holder.custname<<endl<<endl;;
    cout<<right<<setw(20)<<"Total Deposits:"<<right<<setw(9)<<"       $"<<acntobj->tdeposit<<"  DR"<<endl;
    cout<<right<<setw(23)<<"Total Withdrawals:"<<right<<setw(5)<<"     $"<<acntobj->twithdrawal<<"  CR"<<endl;
    cout<<right<<setw(19)<<"Final Deposit:"<<right<<setw(10)<<"        $"<<acntobj->balance<<"  DR"<<endl;
    cout<<endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << left << setw(15) <<"Date"<< setw(20) << "Description"<< setw(15) <<"Deposit"<< setw(15) <<"Withdrawal"<<" Balance\n";
    for(int i = 0; i < 80; i++)
        cout << "=";
    cout << "\n";
    for(int i=0;i<acntobj->tcount; i++)
    {
        cout  <<left<<setw(15)<<acntobj->tlist[i].transdate;
        cout << left << setw(20) <<acntobj->tlist[i].transdesc;
        if(acntobj->tlist[i].deposit!=0)
            cout << left << setw(15) <<acntobj->tlist[i].deposit;
        else
          cout << left << setw(15) <<" ";
        if((acntobj->tlist[i].withdraw)!=0)
            cout << left<< setw(15) <<(acntobj->tlist[i].withdraw);
        else
            cout << left << setw(15) <<" ";
        /*if(i==0)
        {
            cout << left << setw(15) <<acntobj->tlist[i].trbalance<<endl;
        }
        else
        {*/
            acntobj->tlist[i].trbalance=(acntobj->tlist[i-1].trbalance)-(acntobj->tlist[i].withdraw)+(acntobj->tlist[i].deposit);

            //BUG CAUSING -VE 0.00 Below line
            cout << left <<setw(15) <<acntobj->tlist[i].trbalance<<endl;
    }
}

void acnt :: recorddeposit(acnt *acntobj,transaction *transc)
{
    if((transc->transamt) >0)
    {
        acntobj->balance=acntobj->balance+transc->transamt;
        acntobj->tdeposit=acntobj->tdeposit+transc->transamt;
        transc->trbalance=transc->trbalance+transc->transamt;
        acntobj->tlist[acntobj->tcount]=*transc;
        acntobj->tcount+=1;
    }
    else
        cout<<"Amount entered should be greater than zero\n";
}


void acnt :: recordwithdraw(acnt * acntobj,transaction * transc)
{

    if(acntobj->balance>=transc->transamt)
    {
        acntobj->balance=acntobj->balance-transc->transamt;
        acntobj->twithdrawal=acntobj->twithdrawal+transc->transamt;
        transc->trbalance=transc->trbalance-transc->transamt;
        acntobj->tlist[acntobj->tcount]=*transc;
        acntobj->tcount+=1;
    }
    else
    {
        cout<<"Sorry! There is no money in your account."<<endl;
    }
    acntobj->tcount++;
}

#endif
