#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, hello! How much money do you make?" << endl;

    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    if (amount < 1000) {
        cout << "You should work harder!";
    }

    if (amount > 1000) {
        if (amount > 1000000) {
            cout << "You are a millionaire!";
        }

        if (amount < 1000000) {
            cout << "Good work!";
        }
    }

    cout << " But you are good! :)" << endl;

    return 0;
}
