#include <iostream>
#include <cmath>

using namespace std;

#define FIELD_CENTER_X 0
#define FIELD_CENTER_Y 0

int main()
{
    cout << "========== Detector \"Otklik\" ==========" << endl;

    double radius, posX, posY;

    cout << "Please, enter N: ";
    cin >> radius;

    cout << "Please, enter X: ";
    cin >> posX;

    cout << "Please, enter Y: ";
    cin >> posY;

    cout << endl;

    bool isPosInField = pow(posX, 2) + pow(posY, 2) <= pow(radius, 2);
    if (isPosInField) {
        double distance = sqrt(pow(posX - FIELD_CENTER_X, 2) + pow(posY - FIELD_CENTER_Y, 2));
        cout << "Detector flashing frequency: " << distance << endl;
    } else {
        cout << "You are not within the radius of the field!" << endl;
    }

    cout << endl;
    cout << "Good bye!" << endl;
    cout << "=======================================" << endl;

    return 0;
}
