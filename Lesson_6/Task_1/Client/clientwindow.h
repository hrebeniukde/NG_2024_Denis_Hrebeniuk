#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientWindow;
}
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_connectButton_clicked();

    void on_selectFileButton_clicked();

    void on_sendFileButton_clicked();

    void connectionEstablished();

    void connectionClosed();

private:
    Ui::ClientWindow *ui;

    QTcpSocket *tcpSocket;

    QString selectedFilePath;

    void log(const QString& message);
};
#endif // CLIENTWINDOW_H
