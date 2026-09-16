#ifndef SERVICEQUEUE_H
#define SERVICEQUEUE_H
#include <iostream>
#include<string>
#include<cstddef>

#include <queue>

using namespace std;

struct Service
{
    int accountNumber;
    string requestType;
};

class ServiceQueue
{
private:
    queue<Service> q;

public:
    void addService(int accNo, string type);
    void processService();
};

#endif
