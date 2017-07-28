#include <iostream>
#include <string>
using namespace std;

 //test account details
 string firstAccount = "Hamzah"; // Name used in place of entering card.
 int firstAccountPin = 1234;
 int firstAccountBalance = 3000;


string verifyAccount(string AccountName,int AccountPin)
{
 if (AccountName == firstAccount) {
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

int menu(int input){
cout << "      Menu   " << endl;
cout << "1. Display Balance";
cout << "2. Deposit Cash ";
cout << "3. Withdraw Cash";
cout << "4. Print Balance";

cin >> input;

if(input == 1){
        cout << "Here is your balance:£"<< firstAccountBalance << endl;
}
 else if(input == 2){
        cout << "Please enter amount you wish to deposit";
        int deposit;
        cin >> deposit;
        cout << "Amount deposited";
        //int firstAccountBalance + deposit = firstAccountBalance;
    }

 else if(input == 3){
        cout << "Please enter amount you wish to Withdraw";
    }
 else if(input == 4){
        cout << "Balance has been printed on slip";
    }
 else {
     cout << "Invalid input";
 }
}


int main()
{
 string AccountName;
 int AccountPin;
 cout << "Enter your name for your account";
 cin >> AccountName;
 cout << "Enter your pin";
 cin >> AccountPin;
 cout<< verifyAccount(AccountName,AccountPin)<<"\n";
 return 0;
}
