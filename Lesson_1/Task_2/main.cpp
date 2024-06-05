#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, I am a calculator!" << endl;
    cout << "Please, write two numbers to get their sum." << endl;

    int firstNumber, secondNumber;
    cout << "Enter first number: ";
    cin >> firstNumber;
    cout << "Enter second number: ";
    cin >> secondNumber;

    cout << "Result: " <<  firstNumber << " + " << secondNumber << " = " << firstNumber + secondNumber << endl;

    return 0;
}
