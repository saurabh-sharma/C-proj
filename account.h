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
        acnt* acntobj=new acnt;
        acntobj->holder=aholder;
        acntobj->acntno=aacntno;
        acntobj->balance=abalance;
        acntobj->tdeposit=abalance;
        acntobj->twithdrawal=0;


        //cout<<acntobj->tdeposit;
       acntobj->tlist[0].transdate = transdate;
        acntobj->tlist[0].transdesc = "opening balance";
        acntobj->tlist[0].deposit=abalance;
        acntobj->tlist[0].trbalance=abalance;
        acntobj->tlist[0].withdraw=0;
        acntobj->tlist[0]=transaction(transdate,"OPENING BALANCE",abalance);
        acntobj->tcount=1;
        //return acntobj;//return pointer
    }
};
acnt acc;
acnt account[2];
void acnt :: printreport(acnt* acntobj)
{
    cout<<"ACCOUNT SUMMARY  "<<acntobj->acntno<<"-"<<acntobj->holder.custname<<endl;
    cout<<right<<setw(30)<<"Total Deposits:"<<right<<setw(10)<<"       $"<<acntobj->tdeposit<<endl;
    cout<<right<<setw(33)<<"Total Withdrawals:"<<right<<setw(7)<<"    $"<<acntobj->twithdrawal<<endl;
    cout<<right<<setw(29)<<"Final Deposit:"<<right<<setw(10)<<"        $"<<acntobj->balance<<endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << left << setw(20) <<"Date"<< setw(26) << "Description"<< setw(16) <<"Deposit"<< setw(16) <<"Withdrawal"<<" Balance\n";
    for(int i = 0; i < 81; i++)
        cout << "=";
    cout << "\n";
    for(int i=0;i<acntobj->tcount; i++)
    {
        cout  <<left<<setw(20)<<acntobj->tlist[i].transdate;
        cout << left << setw(26) <<acntobj->tlist[i].transdesc;
        if(acntobj->tlist[i].deposit!=0)
            cout << left << setw(16) <<acntobj->tlist[i].deposit;
        else
          cout << left << setw(16) <<" ";
        if(acntobj->tlist[i].withdraw!=0)
            cout << left<< setw(16) <<acntobj->tlist[i].withdraw;
        else
            cout << left << setw(16) <<" ";
        if(i==0)
        {
            cout << left << setw(16) <<acntobj->tlist[i].trbalance<<endl;
        }
        else
        {
            acntobj->tlist[i].trbalance=acntobj->tlist[i-1].trbalance-acntobj->tlist[i].withdraw+acntobj->tlist[i].deposit;
            cout << left << setw(16) <<acntobj->tlist[i].trbalance<<endl;
        }
    }
}

//function recorddeposit
void acnt :: recorddeposit(acnt *acntobj,transaction *transc)
{
    //transc->transamt=10;
    cout<<transc->transamt;
    if((transc->transamt) >0)
    {
        acntobj->balance=acntobj->balance+transc->transamt;//add the deposit amount to the balance
        acntobj->tdeposit=acntobj->tdeposit+transc->transamt;//add the transaction amount to balance
        transc->trbalance=transc->trbalance+transc->transamt;//
        acntobj->tlist[acntobj->tcount]=*transc;
        acntobj->tcount+=1;//increment tcount
    }
    else
        cout<<"Amount entered should be greater than zero\n";
}

//function withdraw
void acnt :: recordwithdraw(acnt * acntobj,transaction * transc)
{
    cout<<transc->transamt<<"*************"<<endl<<acntobj->balance<<endl;
    if(acntobj->balance>=transc->transamt)//to check whether withdrawal amount is greater than balance
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

// Print report

#endif //end the header file
