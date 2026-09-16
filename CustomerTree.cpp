#include "CustomerTree.h"
#include<cstddef>

CustomerTree::CustomerTree() { root = NULL; }

Node* CustomerTree::insert(Node* node, Node* newNode)
{
    if (node==NULL)
        return newNode; 
    if (newNode->data.getAccountNumber() < node->data.getAccountNumber())
        node->left = insert(node->left, newNode);
    else
        node->right = insert(node->right, newNode);
    return node;
}

void CustomerTree::addCustomer(Node* newNode)
{
    root = insert(root, newNode);
}

Node* CustomerTree::search(Node* node, int accountNumber)
{
    if (!node || node->data.getAccountNumber() == accountNumber)
        return node;
    if (accountNumber < node->data.getAccountNumber())
        return search(node->left, accountNumber);
    else
        return search(node->right, accountNumber);
}

Node* CustomerTree::searchCustomer(int accountNumber)
{
    return search(root, accountNumber);
}

