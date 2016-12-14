#include "chatchild.h"
#include "ui_chatchild.h"

ChatChild::ChatChild(QWidget *parent) :
    QMdiSubWindow(parent),
    ui(new Ui::ChatChild)
{
    udpIn.bind(5045);
    connect(&udpIn,SIGNAL(readyRead()),this,SLOT(receive()));

    ui->setupUi(this);

    chat = new QPlainTextEdit(this);
    chat->setGeometry(0,0,350,475);

    message = new QLineEdit(this);
    message->setGeometry(0,480,350,20);

    connect(this,SIGNAL(sendMessage()),this,SLOT(send()));
}

ChatChild::~ChatChild()
{
    delete ui;
    delete chat;
    delete message;
}

void ChatChild::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return)
    {
        qDebug () << "enter";
        emit sendMessage();
        message->setText("");
    }
}

void ChatChild::send()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << server << message->text();

    QHostAddress address;
    qDebug() << server;
    address.setAddress(server);
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
    qDebug() << message;
    chat->appendPlainText(message);
}
