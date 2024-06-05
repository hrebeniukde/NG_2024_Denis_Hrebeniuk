#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, I am a calculator!" << endl;
    cout << "Please, write two numbers to get their sum." << endl;

    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Result: " <<  a << " + " << b << " = " << a + b << endl;

    return 0;
}
