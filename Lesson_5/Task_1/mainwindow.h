#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define MAX_CARS_COUNT 10

using namespace std;

class Car {
private:
    string manufacturer;

protected:
    int price;
    string type;

public:
    Car() {
        price = 0;
        type.clear();
        manufacturer.clear();
    }

    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    string getManufacturer() {
        return this->manufacturer;
    }
};

class EnhancedCar: public Car {
private:
    string color;
    string modelRange;
    int seatsCount;

public:
    EnhancedCar(string manufacturer, string modelRange, string type, string color, int seatsCount, int price) {
        this->setManufacturer(manufacturer);
        this->setModelRange(modelRange);
        this->type = type;
        this->setColor(color);
        this->setSeatsCount(seatsCount);
        this->price = price;
    }

    void setType(string type) {
        this->type = type;
    }

    string getType() {
        return this->type;
    }

    void setPrice(int price) {
        this->price = price;
    }

    int getPrice() {
        return this->price;
    }

    void setColor(string color) {
        this->color = color;
    }

    string getColor() {
        return this->color;
    }

    void setModelRange(string modelRange) {
        this->modelRange = modelRange;
    }

    string getModelRange() {
        return this->modelRange;
    }

    void setSeatsCount(int seatsCount) {
        this->seatsCount = seatsCount;
    }

    int getSeatsCount() {
        return this->seatsCount;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateMaxPriceFilter(const QString &);
    void updateCarTypeFilter(const QString &);
    void updateCarManufacturerFilter(const QString &);

private:
    Ui::MainWindow *ui;

    EnhancedCar carList[MAX_CARS_COUNT] = {
        EnhancedCar("Toyota", "Camry", "Sedan", "White", 5, 25000),
        EnhancedCar("Ford", "Mustang", "Coupe", "Red", 4, 35000),
        EnhancedCar("Chevrolet", "Tahoe", "SUV", "Black", 7, 50000),
        EnhancedCar("Honda", "Civic", "Sedan", "Blue", 5, 20000),
        EnhancedCar("Tesla", "Model S", "Sedan", "Silver", 5, 75000),
        EnhancedCar("BMW", "X5", "SUV", "Gray", 5, 60000),
        EnhancedCar("Mercedes-Benz", "C-Class", "Sedan", "Black", 5, 40000),
        EnhancedCar("Audi", "A4", "Sedan", "White", 5, 37000),
        EnhancedCar("Jeep", "Wrangler", "SUV", "Green", 4, 45000),
        EnhancedCar("Porsche", "911", "Coupe", "Yellow", 4, 100000)
    };

    int maxPriceFilter;
    string carTypeFilter;
    string carManufacturerFilter;

    void setUpFilters();
    void updateCarList();
};
#endif // MAINWINDOW_H
