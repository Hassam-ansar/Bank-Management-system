#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include<string>
#include<cstddef>
#include<Stack>

using namespace std;

struct TransactionRecord
{
    int accountNumber;
    string type;
    double amount;
};

class Transaction
{
private:
    stack<TransactionRecord> transactions;

public:
    void pushTransaction(int accNo, string type, double amount);
    void showLastTransaction();
};

#endif

