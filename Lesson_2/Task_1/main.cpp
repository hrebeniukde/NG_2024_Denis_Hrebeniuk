#include <iostream>
#include <conio.h>

using namespace std;

#define MAX_ACCOUNTS_COUNT 10

void askAction(); // prototype to find this function in askContinue()

int bankData[MAX_ACCOUNTS_COUNT], accountNumber;

void printHeader() {
    cout << "========== NG Bank ==========" << endl;
}

void askContinue() {
    cout << "Do you want to continue? (y/n): ";

    char answer = getch();
    if (answer == 'y' || answer == 'Y') {
        askAction();
    }
}

void askAccountNumber() {
    cout << "Please, enter your account number: ";
    cin >> accountNumber;
    cout << endl;
    accountNumber -= 1; // index of bankData array

    if (accountNumber < 0 || accountNumber > 10) {
        cout << "You have entered an incorrect account number, please try again." << endl;
        exit(0);
    }
}

void askAction() {
    system("cls");

    printHeader();
    cout << "1. Show amount of money in the account" << endl;
    cout << "2. Put money" << endl;
    cout << "3. Withdraw money" << endl;
    cout << "4. Show amount of money in all accounts" << endl;
    cout << "5. Show account with maximum amount of money" << endl;
    cout << "6. Show account with minimum amount of money" << endl;
    cout << "7. Change to another account number" << endl;
    cout << "8. Exit" << endl;

    int action;
    cout << "Enter desired action: ";
    cin >> action;
    system("cls");

    switch (action) {
    case 1:
        cout << "The amount of money in the account: " << bankData[accountNumber] << endl;
        break;
    case 2:
    case 3:
        int amount;
        cout << "Enter amount of money: ";
        cin >> amount;
        cout << endl;

        if (action == 2)
            bankData[accountNumber] += amount; // put money
        else {
            if (bankData[accountNumber] < amount) {
                cout << "Not enough money in the account." << endl;
                askContinue();
                break;
            }

            bankData[accountNumber] -= amount; // withdraw money
        }

        break;
    case 4: {
        int sum = 0;
        for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++)
            sum += bankData[account];

        cout << "Total amount in all accounts: " << sum << endl;
        break;
    }
    case 5: {
        int maxAmountAccount = 0;
        for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++) {
            if (bankData[account] > bankData[maxAmountAccount])
                maxAmountAccount = account;
        }

        cout << "Account with maximum amount of money (" << bankData[maxAmountAccount] << ") is No" << maxAmountAccount + 1 << endl;
        break;
    }
    case 6: {
        int minAmountAccount = 0;
        for (int account = 0; account < MAX_ACCOUNTS_COUNT; account++) {
            if (bankData[account] < bankData[minAmountAccount])
                minAmountAccount = account;
        }

        cout << "Account with minimum amount of money (" << bankData[minAmountAccount] << ") is No" << minAmountAccount + 1 << endl;
        break;
    }
    case 7:
        askAccountNumber();
        break;
    case 8:
        exit(0);
    default:
        cout << "You chose the wrong action." << endl;
    }

    askContinue();
}

int main()
{
    printHeader();
    askAccountNumber();
    askAction();

    return 0;
}
