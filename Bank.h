#ifndef BANK_H
#define BANK_H
#include <iostream>
#include"Account.h"
#include"CustomerList.h"
#include"CustomerTree.h"
#include"Transaction.h"
#include"ServiceQueue.h"
#include"Validator.h"
#include "BankGraph.h"

using namespace std;
class CustomerList;
class CustomerTree;
class Bank
{
private:
    CustomerList list;
    CustomerTree tree;
    Transaction transactionStack;
    ServiceQueue queue;
    BankGraph branchGraph;
    int accountCounter;

public:
    Bank();
    void createAccount();
    void performTransaction();
    void displayAllAccounts();
    void showRouting();
    Node* findAccount(int accNo);
};

#endif
