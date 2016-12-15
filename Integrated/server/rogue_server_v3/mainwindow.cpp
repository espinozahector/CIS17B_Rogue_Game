#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpIn.bind(5045);
    udpMessage.bind(5047);

    connect(&udpIn, SIGNAL(readyRead()),this, SLOT(getConnect()));
    connect(&udpMessage, SIGNAL(readyRead()),this, SLOT(getMessage()));

    chat = new QPlainTextEdit(this);
    chat->setReadOnly(true);
    chat->setGeometry(0,0,400,300);

    time = new QTimer(this);

//    connect(time, SIGNAL(timeout()), this, SLOT(checkConnection()));
//    time->start(1000);
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
    in >> address;
    bool found = false;
    for(int i = 0; i < L.size(); i++)
    {
        if(address == L[i])
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        L.append(address);
        chat->appendPlainText(address);
        connection.append(true);
        sendData();
    }

    //in >> color;

    //cnnctd->setStyleSheet(color);
}

void MainWindow::sendMessage()
{
    qDebug() << "Weather Balloon Running";
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << message;

    QHostAddress addOut;
    for(int i = 0; i < L.size(); i++)
    {
        addOut.setAddress(L[i]);
        udpOut.writeDatagram(datagram, addOut, 5047);
    }
}

void MainWindow::checkConnection()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
//    message = "true";
    out << message;

    QHostAddress addOut;
    for(int i = 0; i < L.size(); i++)
    {
        addOut.setAddress(L[i]);
        udpOut.writeDatagram(datagram, addOut, 5045);
    }
    for(int i = 0; i < L.size(); i++)
    {

    }
}

void MainWindow::getMessage()
{
    qDebug() << "Weather Station Running";
    QByteArray datagram;

    do
    {
        datagram.resize(udpMessage.pendingDatagramSize());
        udpMessage.readDatagram(datagram.data(), datagram.size());
    }while(udpMessage.hasPendingDatagrams());

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_3);
    in >> message;

    chat->appendPlainText(message);
    sendMessage();
}
