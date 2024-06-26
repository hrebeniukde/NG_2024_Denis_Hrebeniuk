#include <iostream>

using namespace std;

#define MAX_NUMBERS_COUNT 5

int main()
{
    int numbers[MAX_NUMBERS_COUNT];
    for (int index = 0; index < MAX_NUMBERS_COUNT; index++) {
        numbers[index] = 0;
    }

    int maxColumnLength;
    for (int index = 0; index < MAX_NUMBERS_COUNT; index++) {
        cout << "Please, enter value: ";
        cin >> numbers[index];

        if (numbers[index] > maxColumnLength)
            maxColumnLength = numbers[index];
    }

    cout << endl;
    for (int row = 1; row <= maxColumnLength; row++) {
        for (int symbol = 0; symbol < MAX_NUMBERS_COUNT; symbol++) {
            if (row <= numbers[symbol]) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
