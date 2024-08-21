#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearButton_clicked()
{
    QString inputText = ui->originalTextInput->toPlainText();
    if (inputText.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("You have not entered any text in the input box!");
        msgBox.exec();
        return;
    }

    vector<QString> badWords = getBadWordsList();
    for (const QString& badWord : badWords) {
        inputText.replace(badWord, (ui->replaceWithStarsCheck->isChecked()) ? "******" : "", Qt::CaseInsensitive);
    }

    ui->filteredTextInput->setText(inputText);
}

vector<QString> getBadWordsList() {
    vector<QString> badWords;

    QFile file(BAD_WORDS_FILE);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(QString("File \"%1\" with bad words list not found!").arg(BAD_WORDS_FILE));
        msgBox.exec();
        exit(0);
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString badWord = in.readLine();
        badWords.emplace_back(badWord);
    }

    return badWords;
}

