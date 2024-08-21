#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->recordsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addRecordButton_clicked()
{
    int currentRowIndex = ui->recordsTable->rowCount();

    ui->recordsTable->insertRow(currentRowIndex);
    ui->recordsTable->setVerticalHeaderItem(currentRowIndex, new QTableWidgetItem("*"));

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->recordsTable->setItem(currentRowIndex, 4, new QTableWidgetItem(currentDateTime.toString("yyyy-MM-dd hh:mm:ss")));
}

void MainWindow::on_removeRecordButton_clicked()
{
    int selectedRow = ui->recordsTable->currentRow();
    records.erase(selectedRow);
    ui->recordsTable->hideRow(selectedRow);
}

void MainWindow::on_confirmButton_clicked()
{
    int rowsCount = ui->recordsTable->rowCount();

    for (int rowIndex = 0; rowIndex < rowsCount; rowIndex++)
    {
        QTableWidgetItem *currentRowHeader = ui->recordsTable->verticalHeaderItem(rowIndex);
        if (!currentRowHeader->text().contains("*"))
            continue;

        QTableWidgetItem *name = ui->recordsTable->item(rowIndex, 0);
        QTableWidgetItem *author = ui->recordsTable->item(rowIndex, 1);
        QTableWidgetItem *type = ui->recordsTable->item(rowIndex, 2);
        QTableWidgetItem *address = ui->recordsTable->item(rowIndex, 3);
        QTableWidgetItem *creationDate = ui->recordsTable->item(rowIndex, 4);

        if (!name || !author || !type || !address || !creationDate) {
            showConfirmError(rowIndex);
            return;
        }

        if (name->text().isEmpty() ||
            author->text().isEmpty() ||
            type->text().isEmpty() ||
            address->text().isEmpty() ||
            creationDate->text().isEmpty()) {
            showConfirmError(rowIndex);
            return;
        }

        if (!records.count(rowIndex)) {
            records.insert({rowIndex, Card(name->text(), author->text(), type->text(), address->text(), creationDate->text())});
        } else {
            Card *record = &records.at(rowIndex);

            record->setName(name->text());
            record->setAuthor(author->text());
            record->setRecordType(type->text());
            record->setLibraryAddress(address->text());
            record->setRecordCreationDate(creationDate->text());
        }

        currentRowHeader->setText(QString::number(rowIndex + 1));
    }
}

void MainWindow::on_recordsTable_cellChanged(int row)
{
    QTableWidgetItem *currentRowHeader = ui->recordsTable->verticalHeaderItem(row);
    if (currentRowHeader->text().contains("*"))
        return;

    currentRowHeader->setText("*");
}

void MainWindow::on_searchButton_clicked()
{
    QString searchValue = ui->searchInput->text();

    for (auto const& [recordIndex, card] : records) {
        QString name = card.getName();
        QString author = card.getAuthor();
        QString recordType = card.getRecordType();
        QString libraryAddress = card.getLibraryAddress();
        QString recordCreationDate = card.getRecordCreationDate();

        if (name.contains(searchValue, Qt::CaseInsensitive) ||
            author.contains(searchValue, Qt::CaseInsensitive) ||
            recordType.contains(searchValue, Qt::CaseInsensitive) ||
            libraryAddress.contains(searchValue, Qt::CaseInsensitive) ||
            recordCreationDate.contains(searchValue, Qt::CaseInsensitive)) {
            ui->recordsTable->showRow(recordIndex);
            continue;
        }

        ui->recordsTable->hideRow(recordIndex);
    }
}

void showConfirmError(int rowIndex) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText(QString("Failed to add (or update) entry №%1. Check if there are no empty cells in the record.").arg(rowIndex + 1));
    msgBox.exec();
}
