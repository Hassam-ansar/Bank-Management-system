#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string name;
    double balance;
    string address;
    int age;
    string password;
    int accountNumber;
    string branch; // <--- Make sure this is here

public:
    Account();
    // Add 'string br' at the end here to match your .cpp
    Account(int accNo, string n, double b, string a, int ag, string p, string br);

    int getAccountNumber();
    string getName();
    double getBalance();
    void deposit(double amount);
    bool withdraw(double amount);
    string getAddress();
    int getAge();
    string getpass();
    string getBranch(); // <--- This declaration must exist here
    bool verifyPassword(string pass);
};

#endif


