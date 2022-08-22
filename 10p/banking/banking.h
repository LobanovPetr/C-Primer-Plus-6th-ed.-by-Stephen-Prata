#ifndef BANKING_
#define BANKING_

#include <cstring>

class Account
{
    char * name;
    char * account;
    double balance;
public:
    Account(const char * tname = nullptr,const char * taccount = nullptr, double tbalance = 0);
    void deposit(double tmoney = 0);
    void withdraw(double tmoney = 0);
    void show() const;
    ~Account(){delete[] name; delete[] account;}
};

#endif
