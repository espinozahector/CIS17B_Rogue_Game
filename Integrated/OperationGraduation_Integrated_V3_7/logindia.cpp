#include <iostream>
#include <QtNetwork>
using namespace std;

#include "logindia.h"

LoginDialog::LoginDialog(QWidget *parent) : QGraphicsView(parent)
{
    udpSocket.bind(5045);


    connect(&udpSocket, SIGNAL(readyRead()),this, SLOT(getConnect()));

    uLabel = new QLabel;
    pLabel = new QLabel;
    eCheck = new QLabel;
    ipLabel = new QLabel;   //network connection test

    uLabel->setText(tr("Username: "));
    pLabel->setText(tr("Password: "));
    eCheck->setText(tr(""));
    eCheck->setStyleSheet("color: red;");
    ipLabel->setText(tr("Address: "));

    submit = new QPushButton(tr("Submit"));
    exit = new QPushButton(tr("Close"));
    newPlyr = new QPushButton(tr("Register"));
    guest = new QPushButton(tr("Play as Guest"));
    git = new QPushButton(tr("Rogue GitHub"));
    cnnct = new QPushButton(tr("Connect")); //network connection test

    submit->setDefault(true);
    submit->setEnabled(false);

    username = new QLineEdit;
    password = new QLineEdit;
    ipAddrss = new QLineEdit;   //network connection test

    //"offline mode" connection
    connect(guest, SIGNAL(clicked(bool)), this->parent()->parent()->parent()->parent(), SLOT(newGame()));

    //line edit connections
    connect(username, SIGNAL(textChanged(QString)),
            this, SLOT(enableSubmitButton()));
    connect(password, SIGNAL(textChanged(QString)),
            this, SLOT(enableSubmitButton()));

    //repository connection
    connect(git, SIGNAL(clicked()), this, SLOT(website()));

    uLabel->setBuddy(username);
    pLabel->setBuddy(password);
    ipLabel->setBuddy(ipAddrss);    //network connection test

    password->setEchoMode(QLineEdit::Password);

    // set widget backgrounds transparent
    uLabel->setAttribute(Qt::WA_TranslucentBackground);
    pLabel->setAttribute(Qt::WA_TranslucentBackground);
    submit->setAttribute(Qt::WA_TranslucentBackground);
    exit->setAttribute(Qt::WA_TranslucentBackground);
    git->setAttribute(Qt::WA_TranslucentBackground);
    newPlyr->setAttribute(Qt::WA_TranslucentBackground);
    guest->setAttribute(Qt::WA_TranslucentBackground);
    eCheck->setAttribute(Qt::WA_TranslucentBackground);
    ipLabel->setAttribute(Qt::WA_TranslucentBackground);    //network connection test
    ipAddrss->setAttribute(Qt::WA_TranslucentBackground);   //network connection test
    cnnct->setAttribute(Qt::WA_TranslucentBackground);      //network connection test

    cnnctd = new QLabel;
    cnnctd->setStyleSheet("background-color: red;");

    // initializing and setting the scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,400,301);

    setScene(scene);

    // adding the widgets to the scene
    scene->addWidget(uLabel);
    scene->addWidget(username);
    scene->addWidget(pLabel);
    scene->addWidget(password);
    scene->addWidget(submit);
    scene->addWidget(newPlyr);
    scene->addWidget(guest);
    scene->addWidget(exit);
    scene->addWidget(git);
    scene->addWidget(eCheck);
    scene->addWidget(ipLabel);  //network connection test
    scene->addWidget(ipAddrss); //network connection test
    scene->addWidget(cnnct);    //network connection test
    scene->addWidget(cnnctd);

    // setting the placement of each widget
    //                 ( X,Y  , W,H )
    uLabel->setGeometry(95,100,50,20);
    username->setGeometry(150,100,150,20);
    pLabel->setGeometry(95,125,50,20);
    password->setGeometry(150,125,150,20);
    submit->setGeometry(95,150,205,25);
    newPlyr->setGeometry(95,175,100,25);
    guest->setGeometry(200,175,100,25);
    git->setGeometry(95,200,205,25);
    exit->setGeometry(95,225,205,25);
    eCheck->setGeometry(95,250,250,50);
    ipLabel->setGeometry(95,300,50,20);
    ipAddrss->setGeometry(150,300,150,20);
    cnnct->setGeometry(95,325,205,25);
    cnnctd->setGeometry(320,325,50,20);

    connect(cnnct,SIGNAL(clicked(bool)),this,SLOT(sendData()));
}

void LoginDialog::enableSubmitButton()
{
    bool ok = !username->text().isEmpty()
           && !password->text().isEmpty();
    submit->setEnabled(ok);
}

void LoginDialog::website()
{
    QDesktopServices::openUrl(QUrl("https://github.com/espinozahector/CIS17B_Rogue_Game"));
}

void LoginDialog::sendData()
{
    qDebug() << "Weather Balloon Running";
    sAddress = ipAddrss->text();
    QHostInfo info;
    QList<QHostAddress> ip;

    info = QHostInfo::fromName(QHostInfo::localHostName());
    ip =  info.addresses();

    //QString ip1 = ip[0].toString();
    ip1 = ip[0].toString();

    qDebug() << ip1;

    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << ip1;

    QHostAddress address;
    address.setAddress(sAddress);
    udpSocket2.writeDatagram(datagram, address, 5045);

}

void LoginDialog::getConnect()
{
    qDebug() << "Weather Station Running";
    QByteArray datagram;

    do
    {
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());
    }while(udpSocket.hasPendingDatagrams());

    QString color;
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_3);
    in >> color;

    cnnctd->setStyleSheet(color);

}
