#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<conio.h>
#include<stdio.h>

class bank_Account
{
    int account_number;//customer account number
	char customer_name[50];//customer username
	int balance;// customer balance
	char account_type;// account type
public:
	void account_creation();//cretae account
	void show_account();//displays account

	void deposit(int);//deposits money
	void withdraw(int);//withdraws money
	int ret_account_number();//returns account number
	int ret_balance();//returns balance
	char ret_account_type();//returns account type

};

#endif // BANK_ACCOUNT_H
