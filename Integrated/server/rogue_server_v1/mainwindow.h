#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
    QList<QString> L;
    QList<QString> M;
    QUdpSocket udpIn;
    QUdpSocket udpOut;
    QString address;
    QString message;
};

#endif // MAINWINDOW_H
