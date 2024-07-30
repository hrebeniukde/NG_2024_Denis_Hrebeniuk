#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

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

    int maxPriceFilter;
    string carTypeFilter;
    string carManufacturerFilter;

    void setUpFilters();
    void updateCarList();
};
#endif // MAINWINDOW_H
