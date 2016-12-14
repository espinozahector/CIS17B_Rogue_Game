#ifndef CHATCHILD_H
#define CHATCHILD_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QKeyEvent>
#include <QUdpSocket>
#include <QHostAddress>
#include <QPlainTextEdit>

namespace Ui {
class ChatChild;
}

class ChatChild : public QMdiSubWindow
{
    Q_OBJECT

public:
    explicit ChatChild(QWidget *parent = 0);
    ~ChatChild();
    void keyPressEvent(QKeyEvent *event);
    void setServ(QString data) {server = data;}

private:
    Ui::ChatChild *ui;
    QPlainTextEdit *chat;
    QLineEdit *message;
    QUdpSocket udpOut;
    QUdpSocket udpIn;
    QString server;

signals:
    void sendMessage();

private slots:
    void send();
    void receive();
};

#endif // CHATCHILD_H
