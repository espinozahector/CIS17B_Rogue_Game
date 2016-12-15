#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QPlainTextEdit>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void sendData();
    void getConnect();
    void sendMessage();
    void checkConnection();
    void getMessage();

private:
    Ui::MainWindow *ui;
    QList<QString> L;
    QList<bool> connection;
    QUdpSocket udpIn;
    QUdpSocket udpMessage;
    QUdpSocket udpOut;
    QString address;
    QString message;
    QPlainTextEdit *chat;
    QTimer *time;
};

#endif // MAINWINDOW_H
