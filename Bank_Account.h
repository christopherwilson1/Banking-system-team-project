#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include<string>
class Bank_Account
{
    int account_num;
    double deposit;
    std::string account_type;
    std::string customer_name;
    public:
        Bank_Account();
        virtual ~Bank_Account();
        void account_creation();
        void display_account();
        void receipt();
        void edit_account();
    protected:

    private:
        void deposit_money();
        void withdraw_money();

};

#endif // BANK_ACCOUNT_H
