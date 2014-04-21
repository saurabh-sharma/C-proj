#include"account.h"
#include"transaction.h"
#include"customer.h"
int main()
{
    custom* Mary = new custom ("Mary Jones", "235718", "5074");
    custom* John = new custom ("John Smith", "375864", "3251");
    acnt* MaryAccount = new acnt(*Mary, "06-3121-10212357", "01/03/2014", 100);
    acnt* JohnAccount = new acnt(*John, "06-3121-10213758", "10/03/2014");
    MaryAccount->recordwithdraw(MaryAccount,new transaction("01/03/2014", "ATM Withdrawal", 50) );
    MaryAccount->recorddeposit(MaryAccount,new transaction("02/03/2014", "Deposit", 90) );
    //MaryAccount->recordwithdraw(MaryAccount,new transaction("04/03/2014", "ATM Withdrawal", 150) );
    MaryAccount->recorddeposit(MaryAccount,new transaction("05/03/2014", "Deposit", 20) );
    MaryAccount->recordwithdraw(MaryAccount,new transaction("05/03/2014", "Withdraw", 100) );
    MaryAccount->recordwithdraw(MaryAccount,new transaction("05/03/2014", "Withdraw", 50) );
    JohnAccount->recorddeposit(JohnAccount,new transaction("11/03/2014", "Deposit", 20) );
    JohnAccount->recorddeposit(JohnAccount,new transaction("12/03/2014", "Deposit", 80) );
    JohnAccount->recordwithdraw(JohnAccount,new transaction("12/03/2014", "Withdraw", 50) );
    MaryAccount->printreport(MaryAccount);
    JohnAccount->printreport(JohnAccount);
    return 0;
}
