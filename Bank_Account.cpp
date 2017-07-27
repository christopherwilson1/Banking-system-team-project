#include "Bank_Account.h"

Bank_Account::Bank_Account()
{
    //ctor
}

Bank_Account::~Bank_Account()
{
    //dtor
}
void Bank_Account::account_creation()
{
    std::cout<<"Enter in your first and last names"<<std::endl;
    std::getline(std::cin,customer_name);
    std::cout<<"Enter in the account number"<<std::endl;
    std::cin>>account_num;
    std::cout<<"enter in the account type"<<std::endl;
    std::cin>>account_type;
    std::cout<<"enter in the amount you would like to put in your account"<<std::endl;
    std::cin>>deposit;
    std::cout<<"congratulations your account has been created"<<std::endl;

}
