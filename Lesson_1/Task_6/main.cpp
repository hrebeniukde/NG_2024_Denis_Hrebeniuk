#include <iostream>

using namespace std;

void fillLine(int amountToSkip, int rowLength) {
    for (int symbol = 1; symbol <= rowLength; symbol++) {
        if (symbol > amountToSkip && symbol <= rowLength - amountToSkip) {
            cout << "*";
        } else {
            cout << " ";
        }
    }
}

int main()
{
    cout << "Let's draw a Christmas tree, shall we?" << endl;

    int size;
    cout << "Please, enter a size: ";
    cin >> size;

    int rowLength = (size * 2) - 1;

    cout << endl;
    for (int row = 1; row <= size; row++) {
        fillLine(size - row, rowLength);
        cout << endl;
    }

    fillLine(size - 1, rowLength);

    return 0;
}
