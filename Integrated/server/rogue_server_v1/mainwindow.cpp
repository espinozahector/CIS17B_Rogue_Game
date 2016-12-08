#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpIn.bind(5045);

    connect(&udpIn, SIGNAL(readyRead()),this, SLOT(getConnect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendData()
{
    qDebug() << "Weather Balloon Running";
    QString color2 = "background-color: green;";
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << color2;

    QHostAddress addOut;
    for(int i = 0; i < L.size(); i++)
    {
        if(L[i] == address) {addOut.setAddress(L[i]); break;}
    }
    //address.setAddress(ipAddrss->text());
    udpOut.writeDatagram(datagram, addOut, 5045);
}

void MainWindow::getConnect()
{
    qDebug() << "Weather Station Running";
    QByteArray datagram;

    do
    {
        datagram.resize(udpIn.pendingDatagramSize());
        udpIn.readDatagram(datagram.data(), datagram.size());
    }while(udpIn.hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_3);
    in >> address >> message;

    L.append(address);
    qDebug() << message;
    sendData();
    //in >> color;

    //cnnctd->setStyleSheet(color);
}
