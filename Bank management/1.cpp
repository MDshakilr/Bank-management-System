//Bank Management System
#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    string accountNumber;
    string accountHolderName;
    double balance;

public:

    Account(string naccountNumber, string naccountHolderName, double nbalance)
    {
        accountNumber=naccountNumber;
        accountHolderName=naccountHolderName;
        balance=nbalance;

    }

    virtual ~Account()
    {
    }

    string getAccountNumber()
    {
        return accountNumber;
    }

    string getAccountHolderName()
    {
        return accountHolderName;
    }

    double getBalance()
    {
        return balance;
    }

    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccountType() = 0;


    virtual void displayAccountInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance:" << balance << endl;
    }



};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:

    SavingsAccount(string naccountNumber, string naccountHolderName, double nbalance, double ninterestRate):Account(naccountNumber,naccountHolderName,nbalance)
    {
        accountNumber=naccountNumber;
        accountHolderName=naccountHolderName;
        balance=nbalance;
        interestRate=ninterestRate;
    }

    void deposit(double amount) override
    {
        balance = balance+amount;
        cout << "Deposited:" << amount << "  New balance:" << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance =  balance- amount;
            cout << "Withdrew :" << amount << " New balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayAccountType()  override
    {
        cout << "Account Type: Savings Account" << endl;
    }

    void displayAccountInfo()override
    {
        Account::displayAccountInfo();
        cout<<"interest Rate:"<<interestRate<<endl;
    }


};


class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:

    CurrentAccount(string naccountNumber, string naccountHolderName, double nbalance, double noverdraftLimit) : Account(naccountNumber, naccountHolderName, nbalance)
    {
        accountNumber=naccountNumber;
        accountHolderName=naccountHolderName;
        balance=nbalance;
        overdraftLimit= noverdraftLimit;
    }


    void deposit(double amount) override
    {
        balance =  balance+amount;
        cout << "Deposited :" << amount << "  New balance: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance =  balance-amount;
            cout << "Withdrew:" << amount << " New balance: " << balance << endl;
        }
        else
        {
            cout << "<< Insufficient balance!" << endl;

        }
    }

    void displayAccountType()  override
    {
        cout << "Account Type: Current Account" << endl;
    }
    void displayAccountInfo()override
    {
        Account::displayAccountInfo();
        cout<<"Overdraft Limit:"<<overdraftLimit<<endl;
    }
};



class SalaryAccount  : public Account
{
public:

    SalaryAccount(string naccountNumber, string naccountHolderName, double nbalance) : Account(naccountNumber, naccountHolderName, nbalance)
    {
        accountNumber=naccountNumber;
        accountHolderName=naccountHolderName;
        balance=nbalance;

    }
    void deposit(double amount) override
    {
        balance =  balance+amount;
        cout << "Deposited :" << amount << "  New balance: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance =  balance-amount;
            cout << "Withdrew :" << amount << " New balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }




    void displayAccountType()  override
    {
        cout << "Account Type: SalaryAccount" << endl;
    }

    void displayAccountInfo()override
    {
        Account::displayAccountInfo();

    }
};



int main()
{



    Account* savings1 ;
    SavingsAccount s1("41230201235", "Md.Shakil Rana", 1000.0, 3.5);
    savings1=&s1;
    savings1-> displayAccountInfo();
    savings1->deposit(500);
    savings1->withdraw(200);
    savings1->displayAccountType();






    Account* current1 ;
    CurrentAccount c1("41230201236", "Md.Rafi", 500.0, 1000.0);
    current1=& c1;
    current1->displayAccountInfo();
    current1->deposit(1500);
    current1->withdraw(300);
    current1->displayAccountType();



    Account *salary1 ;
    SalaryAccount s2("112337777", "Md.Hasan", 5000.0);
    salary1=&s2;
    salary1-> displayAccountInfo();
    salary1->withdraw(1000);
    salary1->displayAccountType();


    return 0;
}
/*Account Number: 41230201235
Account Holder: Md.Shakil Rana
Balance:1000
interest Rate:3.5
Deposited:500  New balance:1500
Withdrew :200 New balance: 1300
Account Type: Savings Account
Account Number: 41230201236
Account Holder: Md.Rafi
Balance:500
Overdraft Limit:1000
Deposited :1500  New balance: 2000
Withdrew:300 New balance: 1700
Account Type: Current Account
Account Number: 112337777
Account Holder: Md.Hasan
Balance:5000
Withdrew :1000 New balance: 4000
Account Type: SalaryAccount
*/
