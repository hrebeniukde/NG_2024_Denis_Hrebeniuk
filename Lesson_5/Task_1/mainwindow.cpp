#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "enhancedcar.h"

#define MAX_CARS_COUNT 10

EnhancedCar carList[MAX_CARS_COUNT]
    = {EnhancedCar("Toyota", "Camry", "Sedan", "White", 5, 25000),
       EnhancedCar("Ford", "Mustang", "Coupe", "Red", 4, 35000),
       EnhancedCar("Chevrolet", "Tahoe", "SUV", "Black", 7, 50000),
       EnhancedCar("Honda", "Civic", "Sedan", "Blue", 5, 20000),
       EnhancedCar("Tesla", "Model S", "Sedan", "Silver", 5, 75000),
       EnhancedCar("BMW", "X5", "SUV", "Gray", 5, 60000),
       EnhancedCar("Mercedes-Benz", "C-Class", "Sedan", "Black", 5, 40000),
       EnhancedCar("Audi", "A4", "Sedan", "White", 5, 37000),
       EnhancedCar("Jeep", "Wrangler", "SUV", "Green", 4, 45000),
       EnhancedCar("Porsche", "911", "Coupe", "Yellow", 4, 100000)};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    maxPriceFilter = 0;
    carTypeFilter.clear();
    carManufacturerFilter.clear();

    connect(ui->maxPriceInput, &QLineEdit::textChanged, this, &MainWindow::updateMaxPriceFilter);
    connect(ui->carTypeList, &QComboBox::currentTextChanged, this, &MainWindow::updateCarTypeFilter);
    connect(ui->carManufacturerList,
            &QComboBox::currentTextChanged,
            this,
            &MainWindow::updateCarManufacturerFilter);

    setUpFilters();
}

void MainWindow::setUpFilters()
{
    int maxCarPrice = 0;

    ui->carTypeList->addItem("All");
    ui->carManufacturerList->addItem("All");

    for (int index = 0; index < MAX_CARS_COUNT; index++) {
        EnhancedCar currentCar = carList[index];

        int carPrice = currentCar.getPrice();
        if (carPrice > maxCarPrice)
            maxCarPrice = carPrice;

        QString carType = QString::fromStdString(currentCar.getType());
        QString carManufacturer = QString::fromStdString(currentCar.getManufacturer());

        if (ui->carTypeList->findText(carType) == -1)
            ui->carTypeList->addItem(carType);

        if (ui->carManufacturerList->findText(carManufacturer) == -1)
            ui->carManufacturerList->addItem(carManufacturer);
    }

    ui->maxPriceInput->setText(QString::number(maxCarPrice));
}

void MainWindow::updateCarList()
{
    ui->carList->clear();

    for (int index = 0; index < MAX_CARS_COUNT; index++) {
        EnhancedCar currentCar = carList[index];

        string carType = currentCar.getType();
        string carManufacturer = currentCar.getManufacturer();

        if (currentCar.getPrice() > maxPriceFilter)
            continue;

        if (carTypeFilter != "All" && carType != carTypeFilter)
            continue;

        if (carManufacturerFilter != "All" && carManufacturer != carManufacturerFilter)
            continue;

        string tempBuffer = "";
        tempBuffer += currentCar.getManufacturer() + " " + currentCar.getModelRange() + " ";
        tempBuffer += "[Type: " + currentCar.getType() + "] ";
        tempBuffer += "[Price: " + to_string(currentCar.getPrice()) + "] ";
        tempBuffer += "[Color: " + currentCar.getColor() + "] ";
        tempBuffer += "[Seats Count: " + to_string(currentCar.getSeatsCount()) + "]";

        ui->carList->addItem(QString::fromStdString(tempBuffer));
    }
}

void MainWindow::updateMaxPriceFilter(const QString &price)
{
    maxPriceFilter = price.toInt();
    updateCarList();
}

void MainWindow::updateCarTypeFilter(const QString &carType)
{
    carTypeFilter = carType.toStdString();
    updateCarList();
}

void MainWindow::updateCarManufacturerFilter(const QString &carManufactuer)
{
    carManufacturerFilter = carManufactuer.toStdString();
    updateCarList();
}

MainWindow::~MainWindow()
{
    delete ui;
}
