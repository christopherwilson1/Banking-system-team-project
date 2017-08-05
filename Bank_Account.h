#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
#include <cstdlib>
using namespace std;
class Bank_Account
{
    int pin;
    int account_num;
    double deposit;
    std::string account_type;
    std::string customer_name;
    public:
        Bank_Account();
        virtual ~Bank_Account();
        void account_creation();
        std::string menu();
        void receipt(int n);
        void edit_account();
        void report() const;
        void withdraw_money(double money);
        string verifyAccount(string customer_name,int pin);

    protected:

    private:
        void deposit_money();

};

#endif // BANK_ACCOUNT_H


