#include <iostream>
#include "banking.h"

Account::Account(const char * tname,const char * taccount, double tbalance)
{
    name = new char[strlen(tname) + 1];
    account = new char[strlen(taccount) + 1];
    strcpy(name, tname);
    strcpy(account, taccount);
    name[strlen(tname)] = '\0';
    account[strlen(taccount)] = '\0';
    balance = tbalance;
}

void Account::deposit(double tmoney)
{
    if (tmoney < 0)
        return;
    balance+= tmoney;
}

void Account::withdraw(double tmoney)
{
    if (tmoney < 0 || tmoney > balance)
        return;
    balance-= tmoney;
}

void Account::show() const
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Name: " << name <<
    " Account: " << account << '\n';
    cout << "Balance: " << balance << '\n';
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
