#include "chatchild.h"
#include "ui_chatchild.h"

ChatChild::ChatChild(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::ChatChild)
{
    udpIn.bind(5045);
    server =
    connect(&udpIn,SIGNAL(readyRead()),this,SLOT(receive()));

    ui->setupUi(this);

    chat = new QPlainTextEdit(this);
    chat->setGeometry(0,0,350,475);

    message = new QLineEdit(this);
    message->setGeometry(0,480,350,20);

}

ChatChild::~ChatChild()
{
    delete ui;
    delete chat;
    delete message;
}

void ChatChild::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::EnterKeyReturn)
    {
        emit sendMessage();
    }
}

void ChatChild::send()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << message->text();

    QHostAddress address;
    address.setAddress(message->text());
    udpOut.writeDatagram(datagram, address, 5045);
}

void ChatChild::receive()
{
    QByteArray datagram;

    do
    {
        datagram.resize(udpIn.pendingDatagramSize());
        udpIn.readDatagram(datagram.data(), datagram.size());
    }while(udpIn.hasPendingDatagrams());

    QString message;
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_3);
    in >> message;

    chat->appendPlainText(message);
}
