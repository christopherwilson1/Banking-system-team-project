#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
class Bank_Account
{

    int account_num;
    int balance;
    char account_type;
    char customer_name[70];
    public:

        Bank_Account();
        virtual ~Bank_Account();
        void account_creation();
        void withdraw_money(int money);
        void deposit_money(int money);
        int give_accountnum();
        char give_accounttype();
        int give_accountdep();
        void show_account();


    protected:

    private:

};

#endif // BANK_ACCOUNT_H
