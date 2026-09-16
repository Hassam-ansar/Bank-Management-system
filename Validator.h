#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include<string>
#include<cstddef>

using namespace std;

class Validator
{
public:
    static bool checkPassword(string input, string actual);
};

#endif
