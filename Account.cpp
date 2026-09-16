#include "Account.h"
Account::Account() {}

Account::Account(int accNo, string n, double b, string a, int ag, string p,string br)
{
    accountNumber = accNo;
    name = n;
    balance = b;
    address = a;
    age = ag;
    password = p;
    branch = br;
}

int Account::getAccountNumber()
 { return accountNumber; }
string Account::getName() { return name; }
double Account::getBalance() { return balance; }
string Account::getAddress() { return address; }
int Account::getAge() { return age; }
string Account::getpass(){
	return password;
}
string Account::getBranch() { return branch; }

bool Account::verifyPassword(string pass) { return password == pass; }

void Account::deposit(double amount) { balance += amount; }

bool Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        return true;
    }
    return false;
}
