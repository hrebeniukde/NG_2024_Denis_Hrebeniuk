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
    for (int i = 1; i <= size + 1; i++) {
        for (int j = 1; j <= rowLength; j++) {
            // just calculate how many "cells" we should skip at start and at the end
            int amountToSkip = (i == size + 1) ? size - 1 : size - i; // if row == 5, just repeat first row iteration behaviour

            if (j > amountToSkip && j <= rowLength - amountToSkip) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
