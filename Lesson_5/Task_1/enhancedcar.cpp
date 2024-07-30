#include "enhancedcar.h"

EnhancedCar::EnhancedCar(string manufacturer, string modelRange, string type,
                         string color, int seatsCount, int price) {
    this->setManufacturer(manufacturer);
    this->setModelRange(modelRange);
    this->setColor(color);
    this->setSeatsCount(seatsCount);
    this->type = type;
    this->price = price;
}

void EnhancedCar::setType(string type) { this->type = type; }

string EnhancedCar::getType() { return this->type; }

void EnhancedCar::setPrice(int price) { this->price = price; }

int EnhancedCar::getPrice() { return this->price; }

void EnhancedCar::setColor(string color) { this->color = color; }

string EnhancedCar::getColor() { return this->color; }

void EnhancedCar::setModelRange(string modelRange) {
    this->modelRange = modelRange;
}

string EnhancedCar::getModelRange() { return this->modelRange; }

void EnhancedCar::setSeatsCount(int seatsCount) {
    this->seatsCount = seatsCount;
}

int EnhancedCar::getSeatsCount() { return this->seatsCount; }
