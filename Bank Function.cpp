#include "Bank_Account.h"
using namespace std;
Bank_Account::Bank_Account()
{
 //account_creation();
}

Bank_Account::~Bank_Account()
{
 //dtor
}
void Bank_Account::account_creation()
{

     std::cout << "Enter in your first and last names" << std::endl;
     gets(customer_name);
     std::cout << "Enter in the account number" << std::endl;
     std::cin >> account_num;
     std::cout << "enter in the account type current or savings" << std::endl;
     std::cin >> account_type;
     std::cout << "enter in the amount you would like to put in your account" << std::endl;
     std::cin >> balance;
     std::cout << "congratulations your account has been created saving information" << std::endl;
}
void Bank_Account::show_account()
{
    cout<<"Customer Name"<<customer_name<<endl;
    cout<<"Acount number"<<account_num<<endl;
    cout<<"Account Type"<<account_type<<endl;
    cout<<"Balance"<<balance<<endl;

}
void Bank_Account::withdraw_money(int money)
{
    balance-=money;

}
void Bank_Account::deposit_money(int money)
{
  balance+=money;

}

int Bank_Account::give_accountnum()
{
    return account_num;
}
char Bank_Account::give_accounttype()
{
    return account_type;
}
int Bank_Account::give_accountdep()
{
    return balance;
}
