#include "Transaction.h"
#include <iostream>
using namespace std;

void Transaction::pushTransaction(int accNo, string type, double amount)
{
    TransactionRecord tr;
    tr.accountNumber = accNo;
    tr.type = type;
    tr.amount = amount;
    transactions.push(tr);
}

void Transaction::showLastTransaction()
{
    if (!transactions.empty())
    {
        TransactionRecord tr = transactions.top();
        cout << "Last Transaction - Account: " << tr.accountNumber
             << ", Type: " << tr.type
             << ", Amount: " << tr.amount << endl;
    }
    else
    {
        cout << "No transactions yet." << endl;
    }
}
