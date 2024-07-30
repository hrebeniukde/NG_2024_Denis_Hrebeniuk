#ifndef ENHANCEDCAR_H
#define ENHANCEDCAR_H

#include "car.h"


class EnhancedCar : public Car
{
private:
    string color;
    string modelRange;
    int seatsCount;

public:
    EnhancedCar(
        string manufacturer, string modelRange, string type, string color, int seatsCount, int price);

    void setType(string type);
    string getType();

    void setPrice(int price);
    int getPrice();

    void setColor(string color);
    string getColor();

    void setModelRange(string modelRange);
    string getModelRange();

    void setSeatsCount(int seatsCount);
    int getSeatsCount();
};

#endif // ENHANCEDCAR_H
