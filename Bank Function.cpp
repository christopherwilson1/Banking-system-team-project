#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
//test account details
string firstAccount = "Hamzah"; // Name used in place of entering card.
int firstAccountPin = 1234;
int firstAccountBalance = 3000;


string verifyAccount(string AccountName, int AccountPin)
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

string menu() {
 cout << "      Menu (Select option or enter 5 to quit)" << endl;
 cout << "1. Display Balance"<< endl;
 cout << "2. Deposit Cash "<< endl;
 cout << "3. Withdraw Cash"<< endl;
 cout << "4. Print Balance"<< endl;
 cout << "Enter option:";

 int input;
 cin >> input;

 if (input == 1) {
  stringstream sstm;
  sstm << "Here is your balance(pounds):" << firstAccountBalance<<"\n";
  return sstm.str();
 }
 else if (input == 2) {
  cout<< "Please enter amount you wish to deposit \n";
  int deposit;
  cin >> deposit;
 firstAccountBalance += deposit;
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


int main()
{
 string AccountName;
 int AccountPin;
 cout << "Enter your name for your account";
 cin >> AccountName;
 cout << "Enter your pin";
 cin >> AccountPin;
 cout << verifyAccount(AccountName, AccountPin) << "\n";
 while (true){
 cout<<menu();
 }
 return 0;
}
