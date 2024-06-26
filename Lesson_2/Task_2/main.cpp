#include <iostream>

using namespace std;

#define MAX_NUMBERS_COUNT 20

int main()
{
    int numbers[MAX_NUMBERS_COUNT];
    for (int index = 0; index < MAX_NUMBERS_COUNT; index++) {
        numbers[index] = 0;
    }

    int maxRowLength;
    for (int numberIndex = 0; numberIndex < MAX_NUMBERS_COUNT; numberIndex++) {
        cout << "Please, enter value: ";
        cin >> numbers[numberIndex];

        if (!numbers[numberIndex])
            break;

        if (numbers[numberIndex] > maxRowLength)
            maxRowLength = numbers[numberIndex];
    }

    cout << endl;
    for (int row = 0; row < MAX_NUMBERS_COUNT; row++) {
        if (numbers[row] == 0)
            break;

        int gapSize = (maxRowLength - numbers[row]) / 2;
        for (int symbol = 1; symbol <= maxRowLength; symbol++) {
            if (symbol > gapSize && symbol <= (maxRowLength - gapSize)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
