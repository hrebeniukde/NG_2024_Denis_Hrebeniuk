#include <conio.h>
#include <iostream>

using namespace std;

#define MAX_ACCOUNTS_COUNT 10

int main()
{
    int bankData[MAX_ACCOUNTS_COUNT] = {0}; // init with zeros values
    int accountNumber = 0;

    char restart = '\0';
    do {
        system("cls");
        cout << "Please, enter account number: ";
        cin >> accountNumber;
        accountNumber -= 1; // index of bankData array

        if (accountNumber < 0 || accountNumber > 10) {
            cout << "You have entered an incorrect account number, please try again." << endl;
            exit(0);
        }

        system("cls");
        cout << "========== NG Bank ==========" << endl;
        cout << "Menu:" << endl;
        cout << "1. Show amount of money in the account" << endl;
        cout << "2. Put money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Show amount of money in all accounts" << endl;
        cout << "5. Show account with maximum amount of money" << endl;
        cout << "6. Show account with minimum amount of money" << endl;
        cout << "7. Exit" << endl;

        int action;
        cout << "Enter desired action: ";
        cin >> action;

        system("cls");
        switch (action) {
        case 1: // amount of money
            cout << "The amount of money in the account: " << bankData[accountNumber] << endl;
            break;
        case 2: // fall into case 3
        case 3: // put/withdraw money
            int amount;
            cout << "Enter amount of money: ";
            cin >> amount;
            cout << endl;

            if (action == 2) {
                if (amount <= 0) {
                    cout << "Deposit amount must be greater than 0!" << endl;
                    break;
                }

                bankData[accountNumber] += amount; // put money
            } else {
                if (amount <= 0) {
                    cout << "Withdraw amount must be greater than 0!" << endl;
                    break;
                }

                if (bankData[accountNumber] < amount) {
                    cout << "Not enough money in the account." << endl;
                    break;
                }

                bankData[accountNumber] -= amount; // withdraw money
            }

            break;
        case 4: { // amount of money in all accounts
            int sum = 0;
            for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++)
                sum += bankData[account];

            cout << "Total amount in all accounts: " << sum << endl;
            break;
        }
        case 5: { // max amount among all acounts
            int maxAmountAccount = 0;
            for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++) {
                if (bankData[account] > bankData[maxAmountAccount])
                    maxAmountAccount = account;
            }

            cout << "Account with maximum amount of money (" << bankData[maxAmountAccount]
                 << ") is No" << maxAmountAccount + 1 << endl;
            break;
        }
        case 6: { // min amount among all acounts
            int minAmountAccount = 0;
            for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++) {
                if (bankData[account] < bankData[minAmountAccount])
                    minAmountAccount = account;
            }

            cout << "Account with minimum amount of money (" << bankData[minAmountAccount]
                 << ") is No" << minAmountAccount + 1 << endl;
            break;
        }
        case 7: // exit from application
            exit(0);
        default:
            cout << "You chose the wrong action." << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        restart = getch();
    } while (restart == 'Y' || restart == 'y');

    return 0;
}
