#include "car.h"

Car::Car() {
    price = 0;
    type.clear();
    manufacturer.clear();
}

void Car::setManufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

string Car::getManufacturer() { return this->manufacturer; }
