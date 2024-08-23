#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket();
    selectedFilePath.clear();

    connect(tcpSocket, &QTcpSocket::connected, this, &ClientWindow::connectionEstablished);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &ClientWindow::connectionClosed);
}

ClientWindow::~ClientWindow()
{
    tcpSocket->close();

    delete tcpSocket;
    delete ui;
}

void ClientWindow::on_connectButton_clicked()
{
    QString address = ui->ipInput->text();
    int port = ui->portInput->value();

    tcpSocket->connectToHost(QHostAddress(address), port);
}

void ClientWindow::on_selectFileButton_clicked()
{
    selectedFilePath.clear();

    QString fileName = QFileDialog::getOpenFileName(this, "Select file to send", "", "All Files (*)");

    if (!fileName.isEmpty()) {
        selectedFilePath = fileName;
        ui->fileStatusLabel->setText("File was selected!");
        ui->fileStatusLabel->setStyleSheet("color: green");
        log(QString("Selected file path: %1").arg(fileName));
    }
}

void ClientWindow::on_sendFileButton_clicked()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("You have not selected a file to send. Select a file by clicking on the \"Select file\" button!");
        msgBox.exec();
        return;
    }

    QFile file(selectedFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Unable to open the selected file, try selecting again...");
        msgBox.exec();
        return;
    }

    QFileInfo fileInfo(file.fileName());
    QString fileName = fileInfo.fileName();
    QByteArray fileData = file.readAll();

    QByteArray sendDataBlock;
    QDataStream sendDataStream(&sendDataBlock, QIODeviceBase::WriteOnly);
    sendDataStream.setVersion(QDataStream::Qt_6_7);

    sendDataStream << fileName;
    sendDataStream << fileData;

    tcpSocket->write(sendDataBlock);

    QFile localFile(fileName);
    localFile.open(QIODevice::WriteOnly);
    localFile.write(fileData);
    localFile.close();

    selectedFilePath.clear();
    ui->fileStatusLabel->setText("File not selected!");
    ui->fileStatusLabel->setStyleSheet("color: red");

    log(QString("File (%1) was sent to the server...").arg(fileName));
}

void ClientWindow::connectionEstablished()
{
    ui->stackedWidget->setCurrentIndex(1);
    log(QString("Connection established with %1:%2...").arg(ui->ipInput->text(), QString::number(ui->portInput->value())));
    log("<i><b>WARNING:</b> It is recommended not to transfer large files!</i>");
}

void ClientWindow::connectionClosed()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->logInput->clear();
    ui->logInput->append("Connection closed...");
}

void ClientWindow::log(const QString& message)
{
    ui->logInput->append(message);
}
