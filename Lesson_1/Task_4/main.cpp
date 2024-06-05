#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Hello, I am a PRO calculator!" << endl;
    cout << "Please, write two numbers and action to get result." << endl;
    cout << "Available actions: +, -, *, /, r (root), e (exponent)" << endl;
    cout << endl;

    float firstNumber, secondNumber, result = 0.0;
    char action;

    cout << "Enter first number: ";
    cin >> firstNumber;

    cout << "Enter second number (or exponent in actions r/e): ";
    cin >> secondNumber;

    cout << "Enter action: ";
    cin >> action;

    switch (action) {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        result = firstNumber / secondNumber;
        break;
    case 'r':
        result = pow(firstNumber, 1 / secondNumber);
        break;
    case 'e':
        result = pow(firstNumber, secondNumber);
        break;
    default:
        cout << "Error, you have selected an unknown action =(" << endl;
        exit(0);
    }

    cout << endl;
    cout << "Result: " << result << endl;
    return 0;
}
