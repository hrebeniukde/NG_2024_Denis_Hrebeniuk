#include <iostream>

using namespace std;

#define MAX_TEXT_SIZE 512

int main()
{
    char text[MAX_TEXT_SIZE];

    cout << "Please, enter your text: ";
    cin.getline(text, MAX_TEXT_SIZE);

    int wordsCount = 0;
    bool isAnyLetterFound = false;
    for (int index = 0; text[index] != '\0'; index++) {
        char symbol = text[index];

        if (symbol == ' ' || text[index + 1] == '\0') {
            if (isAnyLetterFound)
                wordsCount += 1;

            isAnyLetterFound = false;

            continue;
        }

        if (isalpha(symbol))
            isAnyLetterFound = true;
    }

    cout << "Found " << wordsCount << " words in text!" << endl;

    return 0;
}
