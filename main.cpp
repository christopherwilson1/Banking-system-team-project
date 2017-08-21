
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include"bank_Account.h"
using namespace std;





void write_account();//writes the account to a txt doc
void display_info(int);//take the info from txt doc and displays it (just 1 user)
void deposit_withdraw(int, int);//handles with draw and deposit



int main()
{
	char button;
	int console_input;

	do
	{
    cout << "      Menu (Select option or enter 5 to quit)" << endl;
    cout << "1. New Account "<< endl;
    cout << "2. Deposit Cash "<< endl;
    cout << "3. Withdraw Cash"<< endl;
    cout << "4. Balance Enquiry"<< endl;
    cout << "5. To exit "<< endl;
    cout << "Enter option:";

		cin>>button;
		switch(button)
		{
		 case '1':
            write_account();
            break;
        case '2':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            deposit_withdraw(console_input,1);
            break;
        case '3':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            deposit_withdraw(console_input,2);
            break;
        case '4':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            display_info(console_input);
            break;
        case '5':
        cout<<"Thank you for using the system, we hope you enjoyed it"<<endl;
     default :cout<<"\a";
		}
		getch();
	}while(button!='5');
	return 0;
}



void write_account()
{
	bank_Account customer;
	ofstream customerFile;
	customerFile.open("customer_account.txt",ios::app);
	customer.account_creation();
	customerFile.write((char *) &customer, sizeof(bank_Account));
	customerFile.close();
}


void display_info(int num)
{
	bank_Account customer;
	int flag=0;
	ifstream customerFile;
	customerFile.open("customer_account.txt");
	if(!customerFile)
	{
		cout<<"File did not open please seek assistance from staff ";
		return;
	}
	cout<<"Balance Information"<<endl;
	while(customerFile.read((char *) &customer, sizeof(bank_Account)))
	{
		if(customer.ret_account_number()==num)
		{
			customer.show_account();
			flag=1;
		}
	}
	customerFile.close();
	if(flag==0)
		cout<<"Could not find account number please talk to staff";
}


void deposit_withdraw(int n, int option)
{
	int amount;
	int found=0;
	bank_Account customer;
	fstream customerFile;
	customerFile.open("customer_account.txt",ios::in|ios::out);
	if(!customerFile)
	{
		cout<<"File did not open please seek assistance from staff";
		return;
	}
	while(customerFile.read((char *) &customer, sizeof(bank_Account)) && found==0)
	{
	    int receipt_opt;
		if(customer.ret_account_number()==n)
		{
			customer.show_account();
			if(option==1)
			{
				cout<<"    Deposit money    "<<endl;
				cout<<"Enter the amount you would like to deposit: "<<endl;
				cin>>amount;
				customer.deposit(amount);

			}
			if(option==2)
			{
				cout<<"   Withdraw Screen  "<<endl;
				cout<<"Enter The amount to be withdraw: "<<endl;
				cin>>amount;
				int bal=customer.ret_balance();
				if(bal<amount)
					cout<<"Not enough money";
				else
					customer.withdraw(amount);

			}
			int pos=(-1)* sizeof(customer);
			customerFile.seekp(pos,ios::cur);
			customerFile.write((char *) &customer, sizeof(bank_Account));
			//cout<<"Information saved";
			found=1;
	       }
	}
	customerFile.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}









