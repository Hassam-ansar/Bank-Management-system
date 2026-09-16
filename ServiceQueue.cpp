#include "ServiceQueue.h"

void ServiceQueue::addService(int accNo, string type)
{
    Service s;
    s.accountNumber = accNo;
    s.requestType = type;
    q.push(s);
}

void ServiceQueue::processService()
{
    if (!q.empty())
    {
        Service s = q.front();
        cout << "Processing account " << s.accountNumber << " request: " << s.requestType << endl;
        q.pop();
    }
    else
    {
        cout << "No pending services." << endl;
    }
}

