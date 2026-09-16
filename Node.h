#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Account.h"
#include <cstddef>

class Node {
public:
    Account data;
    Node* next;
    Node* left;
    Node* right;

    // The constructor logic must be inside the class to avoid "extra qualification" errors
    Node(Account acc) {
        data = acc;
        next = NULL;
        left = NULL;
        right = NULL;
    }
}; // Don't forget this semicolon!

#endif

