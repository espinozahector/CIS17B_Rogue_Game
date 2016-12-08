#ifndef LOGINDIA_H
#define LOGINDIA_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QUdpSocket>
#include <QHostAddress>
#include <QPlainTextEdit>

class MainWindow;
class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog : public QGraphicsView
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = 0);
    void checkLineEdits();
    QPushButton *submit;
    QPushButton *exit;
    QPushButton *newPlyr;
    QString getTwo(){return username->text();}
    QString getOne(){return password->text();}
    void setEChck(QString data) {eCheck->setText(data);}

private:
    QGraphicsScene *scene;
    QLabel *uLabel;
    QLabel *pLabel;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *guest;
    QPushButton *git;
    QLabel *eCheck;
    QLineEdit *message;

    //for testing network to another computer
    QLabel *ipLabel;        //label for ip address line edit
    QLineEdit *ipAddrss;    //line edit for ip address
    QPushButton *cnnct;     //connect button for ip address
    QLabel *cnnctd;         //changes color if connected or not

    QUdpSocket udpSocket;
    QUdpSocket udpSocket2;

private slots:
    void enableSubmitButton();
    void website();
    void sendData();
    void getConnect();

signals:
    void receive();
    /*
     * for checking the connection
     *  when the login dialog appears, check the connection
     *      - if connection is good, submit button available,
     *      - else submit button unavailable
     *  when you click submit, recheck the connection.
     *      - if connection is good, check username and password
     *      - else return to login dialog with submit button disabled and guest option only available
     *  Do we need a check connection button if we lose connection?
     *
     * */
};

#endif // LOGINDIA_H
