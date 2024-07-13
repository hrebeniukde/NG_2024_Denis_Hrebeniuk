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
    for (int row = 1; row <= size; row++) {
        int amountToSkip = size - row;
        for (int symbol = 1; symbol <= rowLength; symbol++) {
            if (symbol > amountToSkip && symbol <= rowLength - amountToSkip)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    // print last row with one * in the center of tree
    for (int symbol = 1; symbol <= size; symbol++) {
        if (symbol != size)
            cout << " ";
        else
            cout << "*";
    }

    cout << endl;

    return 0;
}
