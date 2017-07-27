#include <iostream>
#include <string>
using namespace std;

void verifyAccount(){
//test account details
string firstAccount = "Hamzah"; // Name used in place of entering card.
int firstAccountPin = 1234;

int accountPin;
string accountName;

cout<<"Enter your name for your account";
cin>> accountName;

if (accountName ==firstAccount){
        cout<<"Card details processed."<<endl;
        cout<<"Enter your pin";
        cin>>accountPin;
    }

if (accountPin == firstAccountPin){
        cout <<"Pin accepted";
    }

else {
        cout << "Invalid Pin";
    }

}



int main()
{
   verifyAccount();
    return 0;
}
