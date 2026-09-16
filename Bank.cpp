#include "Bank.h"

Bank::Bank() { accountCounter = 0; }

void Bank::createAccount()
{
    string name, address, password, branchCity;
    int age, cityChoice;
    double balance;

    // Added Graph Feature: Choose city before creation
    cout << "--- Choose your Punjab Division Branch ---\n";
    branchGraph.displayDivisions();
    cout << "Enter choice (1-10): ";
    cin >> cityChoice;
    branchCity = branchGraph.getCityName(cityChoice - 1);

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Set Account Password: ";
    cin >> password;

    accountCounter++;
    Account acc(accountCounter, name, balance, address, age, password, branchCity);
    list.addCustomer(acc);
    Node* node = new Node(acc);
    tree.addCustomer(node);

    cout << "Account created successfully in " << branchCity << "! Account Number: " << accountCounter << endl;
}

void Bank::showRouting() {
    string src, dest;
    cout << "Enter Source Branch Name: "; cin.ignore(); getline(cin, src);
    cout << "Enter Destination Branch Name: "; getline(cin, dest);
    branchGraph.findShortestPath(src, dest);
}

// ... performTransaction and displayAllAccounts remain exactly as your original code ...
void Bank::performTransaction()
{
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;
    Node* node = tree.searchCustomer(accNo);
    if (!node)
    {
        cout << "Account not found!" << endl;
        return;
    }

    string pass;
    cout << "Enter Password: ";
    cin >> pass;
    if (!Validator::checkPassword(pass, node->data.getpass()) )
    {
        cout << "Incorrect Password!" << endl;
        return;
    }

    int choice;
    cout << "1. Deposit\n2. Withdraw\n3. Transaction History\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        double amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        node->data.deposit(amt);
        transactionStack.pushTransaction(accNo, "Deposit", amt);
        cout << "Deposit successful!" << endl;
    }
    else if (choice == 2)
    {
        double amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (node->data.withdraw(amt))
        {
            transactionStack.pushTransaction(accNo, "Withdraw", amt);
            cout << "Withdrawal successful!" << endl;
        }
        else
            cout << "Insufficient balance!" << endl;
    }
    else if (choice == 3)
    {
        transactionStack.showLastTransaction();
    }
}

void Bank::displayAllAccounts() { list.displayAll(); }
Node* Bank::findAccount(int accNo) { return tree.searchCustomer(accNo); }

