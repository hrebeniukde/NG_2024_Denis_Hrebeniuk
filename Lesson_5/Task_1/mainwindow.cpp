#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(ui->carManufacturerList, &QComboBox::currentTextChanged, this, &MainWindow::updateCarManufacturerFilter);

    setUpFilters();
}

void MainWindow::setUpFilters() {
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

void MainWindow::updateCarList() {
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

void MainWindow::updateMaxPriceFilter(const QString &price) {
    maxPriceFilter = price.toInt();
    updateCarList();
}

void MainWindow::updateCarTypeFilter(const QString &carType) {
    carTypeFilter = carType.toStdString();
    updateCarList();
}

void MainWindow::updateCarManufacturerFilter(const QString &carManufactuer) {
    carManufacturerFilter = carManufactuer.toStdString();
    updateCarList();
}

MainWindow::~MainWindow()
{
    delete ui;
}
