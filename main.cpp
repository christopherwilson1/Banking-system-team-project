#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include "Bank_Account.h"
using namespace std;
int account_creation_func();
int main()
{
account_creation_func();
}


int account_creation_func()
{
    Bank_Account customer_account;
    std::ofstream accountFile;
    accountFile.open("customer_account.txt",ios::binary|ios::app);
    customer_account.account_creation();
    accountFile.write(reinterpret_cast<char *>(& customer_account),sizeof(Bank_Account));
    accountFile.close();

}
