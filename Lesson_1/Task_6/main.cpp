#include <iostream>

using namespace std;

int main()
{
    cout << "Let's draw a Christmas tree, shall we?" << endl;

    int size;
    cout << "Please, enter a size: ";
    cin >> size;
    cout << endl;

    int rowLength = (size * 2) - 1;

    for (int row = 1; row <= size; row++) {
        int amountToSkip = size - row;
        for (int symbol = 0; symbol < amountToSkip; symbol++)
            cout << " ";

        int amountToPrint = rowLength - amountToSkip;
        for (int symbol = amountToSkip; symbol < amountToPrint; symbol++)
            cout << "*";

        cout << endl;
    }

    // print last row with one * in the center of tree
    for (int symbol = 1; symbol < size; symbol++)
        cout << " ";
    cout << "*" << endl;

    return 0;
}
