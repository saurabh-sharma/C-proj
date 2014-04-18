#include"account.h"
#include"transaction.h"
#include"customer.h"
int main()
{
    custom* Mary = new custom ("Mary Jones", "235718", "5074");
//cout<<endl<<__LINE__<<endl;
    custom* John = new custom ("John Smith", "375864", "3251");
//cout<<endl<<__LINE__<<endl;
    acnt* MaryAccount = new acnt(*Mary, "06-3121-10212357", "01/03/2014", 100);
//cout<<endl<<__LINE__<<endl;
    acnt* JohnAccount = new acnt(*John, "06-3121-10213758", "10/03/2014");
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recordwithdraw(MaryAccount,new transaction("01/03/2014", "ATM Withdrawal", 50) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recorddeposit(MaryAccount,new transaction("02/03/2014", "Deposit", 90) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recordwithdraw(MaryAccount,new transaction("04/03/2014", "ATM Withdrawal", 150) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recorddeposit(MaryAccount,new transaction("05/03/2014", "Deposit", 20) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recordwithdraw(MaryAccount,new transaction("05/03/2014", "Withdraw", 100) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->recordwithdraw(MaryAccount,new transaction("05/03/2014", "Withdraw", 50) );
//cout<<endl<<__LINE__<<endl;
    JohnAccount->recorddeposit(JohnAccount,new transaction("11/03/2014", "Deposit", 20) );
//cout<<endl<<__LINE__<<endl;
    JohnAccount->recorddeposit(JohnAccount,new transaction("12/03/2014", "Deposit", 80) );
//cout<<endl<<__LINE__<<endl;
    JohnAccount->recordwithdraw(JohnAccount,new transaction("12/03/2014", "Withdraw", 50) );
//cout<<endl<<__LINE__<<endl;
    MaryAccount->printreport(MaryAccount);
//cout<<endl<<__LINE__<<endl;
    JohnAccount->printreport(JohnAccount);
    return 0;
}
