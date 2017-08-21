#include "bank_Account.h"
using namespace std;
//creates the user information for newly created accounts
void bank_Account::account_creation()
{
	cout<<"Enter in your account number"<<endl;
	cin>>account_number;
	cout<<"Enter in your first and last name : "<<endl;
	cin.ignore();
	gets(customer_name);
	cout<<"Enter in the account type C(current) or S(savers) : "<<endl;
	cin>>account_type;
	cout<<"How much would you like to deposit : "<<endl;
	cin>>balance;
	cout<<"Account information saved";
}
//shows account information
void bank_Account::show_account()
{
	cout<<"Account No. : "<<account_number<<endl;
	cout<<"Account Holder Name : ";
	cout<<customer_name<<endl;
	cout<<"Type of Account : "<<account_type<<endl;
	cout<<"Balance amount : "<<balance<<endl;
}




//handles deposits takes an int(money) and adds it to balance
void bank_Account::deposit(int money)
{
	balance+=money;
}
//handles withdraw takes and int (money) subtracts it from balance
void bank_Account::withdraw(int money)
{
	balance-=money;
}


//returns account number
int bank_Account::ret_account_number()
{
	return account_number;
}
//returns balance
int bank_Account::ret_balance()
{
	return balance;
}
//returns account type
char bank_Account::ret_account_type()
{
	return account_type;
}








