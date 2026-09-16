#ifndef CUSTOMERTREE_H
#define CUSTOMERTREE_H

#include "Node.h"

class CustomerTree {
private:
    Node* root;
    Node* insert(Node* node, Node* newNode);
    Node* search(Node* node, int accountNumber);

public:
    CustomerTree();
    void addCustomer(Node* newNode);
    Node* searchCustomer(int accountNumber);
};

#endif
