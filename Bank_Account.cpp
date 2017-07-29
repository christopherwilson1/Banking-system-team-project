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
    std::cout<<"enter in the account type current or savings"<<std::endl;
    std::cin>>account_type;
    std::cout<<"enter in the amount you would like to put in your account"<<std::endl;
    std::cin>>deposit;
    std::cout<<"congratulations your account has been created saving information"<<std::endl;
   /* std::ofstream accountFile;
    accountFile.open("customer_account.txt");
    if(accountFile.is_open())
            {
                std::cout<<"account saved"<<std::endl;
                accountFile<<customer_name<<std::endl;
                accountFile<<account_num<<std::endl;
                accountFile<<account_type<<std::endl;
                accountFile<<deposit<<std::endl;

            }
            else
            {
                std::cout<<"information failed to save please seek out a member of staff"<<std::endl;
            }
accountFile.close();*/
}

void Bank_Account::withdraw_money(double money)
{
    string answer;
    std::cout<<"would you like a receipt y/n"<<std::endl;

    std::cin>>answer;
    std::ofstream receiptFile;
    receiptFile.open("customer_receipt.txt");
    //std::ofstream accountFile;
    //accountFile.open("customer_account.txt");
    if(answer=="y")
    {

        if(money<=deposit && money >=0 )
        {
            deposit-=money;
            if(receiptFile.is_open())
            {
                std::cout<<"receipt printed"<<std::endl;
                receiptFile<<deposit<<std::endl;
                //accountFile<<deposit<<std::endl;
            }
            else
            {
                std::cout<<"receipt failed to print please seek out a member of staff"<<std::endl;
            }
        }
        else if (money<0)
        {
            std::cout<<"That is not a figure than can be withdraw please use whole positive numbers"<<std::endl;
            std::cout<<"The withdrawal has been aborted"<<std::endl;
        }
        else if(money>deposit)
        {
            std::cout<<"You don't have that much money"<<std::endl;
            std::cout<<"The withdrawal has been aborted"<<std::endl;
        }
    }
    else
    {
        if(money<=deposit && money >=0 )
        {
            deposit-=money;
           // accountFile<<deposit;
        }
        else if (money<0)
        {
            std::cout<<"That is not a figure than can be withdraw please use whole positive numbers"<<std::endl;
            std::cout<<"The withdrawal has been aborted"<<std::endl;
        }
        else if(money>deposit)
        {
            std::cout<<"You don't have that much money"<<std::endl;
            std::cout<<"The withdrawal has been aborted"<<std::endl;
        }
    }

receiptFile.close();
//accountFile.close();

}
