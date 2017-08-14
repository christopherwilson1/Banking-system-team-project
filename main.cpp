#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include "Bank_Account.h"
#include <sstream>
#include <cstdlib>
#include<cctype>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
using namespace std;
void menu();
void build_account();
void read_file(int a);
void deposite_and_withdraw(int a,int choice);
int main()
{
 int console_input;
 char button;

 do{

    cout << "      Menu (Select option or enter 5 to quit)" << endl;
    cout << "1. New Account "<< endl;
    cout << "2. Deposit Cash "<< endl;
    cout << "3. Withdraw Cash"<< endl;
    cout << "4. Balance Enquiry"<< endl;
    cout << "Enter option:";
    cin>>button;

    switch(button)
    {
     case '1':
            build_account();
            break;
     case '2':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            deposite_and_withdraw(console_input,1);
            break;
     case '3':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            deposite_and_withdraw(console_input,2);
            break;
     case '4':
            cout<<"enter in your account number"<<endl;
            cin>>console_input;
            read_file(console_input);
            break;
     case '5':
        cout<<"Thank you for using the system, we hope you enjoyed it"<<endl;
     default :cout<<"\a";
    }
    getch();
}while(button!='5');
return 0;

}









/*void menu() {
 cout << "      Menu (Select option or enter 5 to quit)" << endl;
 cout << "1. New Account "<< endl;
 cout << "2. Deposit Cash "<< endl;
 cout << "3. Withdraw Cash"<< endl;
 cout << "4. Balance Enquiry"<< endl;
 cout << "Enter option:";

 int input;
 cin >> input;

 if (input == 1) {
 build_account();
 }
 else if (input == 2) {
  money_in_out(input,1);
 }

 else if (input == 3)
 {
money_in_out(input,1);
}
 else if (input == 4) {
  read_file(input);
 }
 else if (input== 5){
    exit(0);
 }
 else {
    cout<<  "invalid input";
 }
}*/
//this function writes the account details into a file
void build_account()
{
    Bank_Account customer;
    ofstream enteraccountFile;
    enteraccountFile.open("customer_account.dat",ios::binary|ios::app);
    customer.account_creation();
    enteraccountFile.write((char *)&customer, sizeof(Bank_Account));
    enteraccountFile.close();
}



//this function reads the file
void read_file(int a)
{
    Bank_Account customer;
    ifstream readaccountFile;
    readaccountFile.open("customer_account.dat",ios::binary);
    bool flag=false;
    if(!readaccountFile)
    {
        cout<<"File could not be found or opened please contact a member of staff"<<endl;
        return;
    }
    cout<<"    Balance Information    "<<endl;
    while(readaccountFile.read((char *) &customer,sizeof(Bank_Account)))
    {
        if(customer.give_accountnum()==a)
        {
            customer.show_account();
            flag=true;
        }
    }
    readaccountFile.close();
    if(flag==false)
        cout<<"This account does not exist"<<endl;

}



void deposite_and_withdraw(int a,int choice)
{
    int amount;
    int found=0;
    Bank_Account customer;
    fstream accountFile;
    accountFile.open("customer_account.dat",ios::binary|ios::in|ios::out);
    if(!accountFile)
    {
        cout<<"ERROR! File could not be opened"<<endl;
        return;
    }
    while(accountFile.read((char*)&customer,sizeof(Bank_Account))&&found==0)
    {
        if(customer.give_accountnum()==a)
        {
            customer.show_account();
            if(choice==1)//handles deposits
            {
                cout<<"enter in the amount you would like to deposit"<<endl;
                cin>>amount;
                customer.deposit_money(amount);
            }
            if(choice==2)//handles withdraws
            {
                cout<<"enter in the amount you would like to withdraw"<<endl;
                cin>>amount;
                int balance=customer.give_accountdep()-amount;
                if((balance<500&&customer.give_accounttype()=='s')||(balance<1000&&customer.give_accounttype()=='c'))
                    cout<<"not enough money"<<endl;
                else
                    customer.withdraw_money(amount);
            }
            int position=(-1)*sizeof(customer);
            accountFile.seekp(position,ios::cur);
            accountFile.write((char*)&customer,sizeof(Bank_Account));
            cout<<"Information has been saved"<<endl;
            found=1;

        }
    }
    accountFile.close();
    if(found==0)
        cout<<"account could not be found please make one"<<endl;


}







