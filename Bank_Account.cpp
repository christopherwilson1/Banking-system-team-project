#include "Bank_Account.h"
using namespace std;
Bank_Account::Bank_Account()
{
 account_creation();
}

Bank_Account::~Bank_Account()
{
 //dtor
}
void Bank_Account::account_creation()
{
     std::cout << "Enter in your first and last names" << std::endl;
     std::getline(std::cin, customer_name);
     std::cout << "Enter in the account number" << std::endl;
     std::cin >> account_num;
     std::cout << "enter in the account type current or savings" << std::endl;
     std::cin >> account_type;
     std::cout << "enter in the amount you would like to put in your account" << std::endl;
     std::cin >> deposit;
     std::cout << "congratulations your account has been created saving information" << std::endl;
     std::cout<<"enter in a pin"<<endl;
     std::cin>>pin;
     std::ofstream accountFile;
     accountFile.open("customer_account.txt",std::fstream::app);
         if(accountFile.is_open())
             {
                 std::cout<<"account saved"<<std::endl;
                 accountFile<<customer_name<<std::endl;
                 accountFile<<account_num<<std::endl;
                 accountFile<<account_type<<std::endl;
                 accountFile<<deposit<<std::endl;
                 accountFile<<pin<<std::endl;
                 accountFile<<"" << endl;

             }
         else
             {
                std::cout<<"information failed to save please seek out a member of staff"<<std::endl;
             }
 accountFile.close();
}

void Bank_Account::withdraw_money(double money)
{
     string answer;
     std::cout << "would you like a receipt y/n" << std::endl;

     std::cin >> answer;
     std::ofstream receiptFile;
     receiptFile.open("customer_receipt.txt");
     std::ofstream accountFile;
     accountFile.open("customer_account.txt",std::fstream::app);
     if (answer == "y")
     {

          if (money <= deposit && money >= 0)
              {
               deposit -= money;
               if (receiptFile.is_open())
                   {
                        std::cout << "receipt printed" << std::endl;
                        receiptFile << deposit << std::endl;
                        accountFile<<deposit<<std::endl;
                   }
               else
                   {
                        std::cout << "receipt failed to print please seek out a member of staff" << std::endl;
                   }
               }
          else if (money<0)
              {
                   std::cout << "That is not a figure than can be withdraw please use whole positive numbers" << std::endl;
                   std::cout << "The withdrawal has been aborted" << std::endl;
              }
          else if (money>deposit)
              {
                   std::cout << "You don't have that much money" << std::endl;
                   std::cout << "The withdrawal has been aborted" << std::endl;
              }
    }
     else
         {
          if (money <= deposit && money >= 0)
              {
                deposit -= money;
               accountFile<<deposit;
              }
          else if (money<0)
          {
               std::cout << "That is not a figure than can be withdraw please use whole positive numbers" << std::endl;
               std::cout << "The withdrawal has been aborted" << std::endl;
          }
          else if (money>deposit)
          {
               std::cout << "You don't have that much money" << std::endl;
               std::cout << "The withdrawal has been aborted" << std::endl;
          }
     }

 receiptFile.close();
 accountFile.close();

}

string Bank_Account::menu() {
 cout << "      Menu (Select option or enter 5 to quit)" << endl;
 cout << "1. Display Balance"<< endl;
 cout << "2. Deposit Cash "<< endl;
 cout << "3. Withdraw Cash"<< endl;
 cout << "4. Print Balance"<< endl;
 cout << "Enter option:";

 int input;
 cin >> input;

 if (input == 1) {
 // stringstream sstm;
  //sstm << "Here is your balance(pounds):" << firstAccountBalance<<"\n";
  //return sstm.str();
 }
 else if (input == 2) {
  cout<< "Please enter amount you wish to deposit \n";
  int deposit;
  cin >> deposit;

  return "Amount deposited \n";
 }

 else if (input == 3) {
  return "Please enter amount you wish to Withdraw";
 }
 else if (input == 4) {
  return "Balance has been printed on slip";
 }
 else if (input== 5){
    exit(0);
 }
 else {
    return "invalid input";
 }
}
string verifyAccount(string customer_name, int pin)
{
 if (customer_name == firstAccount) {
  cout << "Card details processed." << endl;
  if (AccountPin == firstAccountPin) {
   return "Pin accepted";
  }
  else
  {
   return "Pin is incorrect";
  }

 }
 else
 {
  return "Account does not exist";
 }

}
