#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
private:
    string manufacturer;

protected:
    int price;
    string type;

public:
    Car();

    void setManufacturer(string manufacturer);
    string getManufacturer();
};

#endif // CAR_H
