#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <iostream>
#include"Node.h"
#include<string>
#include<cstddef>

class CustomerList
{
private:
    Node* head;

public:
    CustomerList();
    void addCustomer(Account acc);
    void displayAll();
    Node* searchCustomer(int accountNumber);
};

#endif
