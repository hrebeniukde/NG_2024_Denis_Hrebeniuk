#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void printComplexDoubleNumber(complex<double> number)
{
    cout << number.real();

    if (number.imag() > 0) {
        cout << " + " << number.imag() << "i";
    } else if (number.imag() < 0) {
        cout << " - " << -number.imag() << "i";
    }

    cout << endl;
}

int main()
{
    cout << "Hi, I can help you solve any quadratic equation!" << endl;
    cout << "Note: if your quadratic equation is incomplete, simply specify 0 in the missing values" << endl;
    cout << endl;

    double numberA, numberB, numberC;
    complex<double> discriminant, firstRoot, secondRoot;

    cout << "Please, enter a: ";
    cin >> numberA;

    cout << "Please, enter b: ";
    cin >> numberB;

    cout << "Please, enter c: ";
    cin >> numberC;

    cout << endl;
    if (numberA && numberB && numberC) {
        discriminant = pow(numberB, 2) - 4 * numberA * numberC;
        firstRoot = (-numberB + sqrt(discriminant)) / (2.0 * numberA);
        secondRoot = (-numberB - sqrt(discriminant)) / (2.0 * numberA);

        cout << "Discriminant = ";
        printComplexDoubleNumber(discriminant);
    } else if (numberA && numberB && !numberC) {
        secondRoot = -(numberB / numberA);
    } else if (numberA && !numberB && numberC) {
        double root = -(numberC / numberA);

        if (root > 0) {
            firstRoot = sqrt(root);
            secondRoot = -sqrt(root);
        } else {
            cout << "No further solution to the quadratic equation is possible, the root cannot be negative";
            return 0;
        }
    } else {
        cout << "Error, you have specified incorrect input data";
        return 0;
    }

    cout << "First root = ";
    printComplexDoubleNumber(firstRoot);
    cout << "Second root = ";
    printComplexDoubleNumber(secondRoot);

    return 0;
}
