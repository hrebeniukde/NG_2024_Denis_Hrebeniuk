#include <iostream>

using namespace std;

int main()
{
    cout << "Let's draw a Christmas tree, shall we?" << endl;

    int size;
    cout << "Please, enter a size: ";
    cin >> size;

    int rowLength = (size * 2) - 1;

    cout << endl;
    for (int row = 1; row <= size + 1; row++) {
        bool breakLoop;
        if (row == size + 1) {
            row = 1;
            breakLoop = true; // last row, so just exit from loop
        }

        int amountToSkip = size - row;
        for (int symbol = 1; symbol <= rowLength; symbol++) {
            if (symbol > amountToSkip && symbol <= rowLength - amountToSkip) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;

        if (breakLoop)
            break;
    }

    return 0;
}
