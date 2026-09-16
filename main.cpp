
#include <iostream>
#include "Bank.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Banking System\n";
    Bank myBank;
    int choice;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n2. Perform Transaction\n3. Display All Accounts\n4. Branch Network (Shortest Path)\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: myBank.createAccount(); break;
            case 2: myBank.performTransaction(); break;
            case 3: myBank.displayAllAccounts(); break;
            case 4: myBank.showRouting(); break; // New Graph Feature
            case 5: cout << "Exiting...Thanks for using our serices :" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
