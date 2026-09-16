#include "CustomerList.h"
#include<cstddef>


CustomerList::CustomerList() { head =NULL; }

void CustomerList::addCustomer(Account acc)
{
    Node* newNode = new Node(acc);
    if (!head)
        head = newNode;
    else
    {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void CustomerList::displayAll()
{
    Node* temp = head;
    while (temp)
    {
        cout << "Account No: " << temp->data.getAccountNumber()
             << ", Name: " << temp->data.getName()
             << ", Balance: " << temp->data.getBalance() << endl;
        temp = temp->next;
    }
}

Node* CustomerList::searchCustomer(int accountNumber)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data.getAccountNumber() == accountNumber)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

