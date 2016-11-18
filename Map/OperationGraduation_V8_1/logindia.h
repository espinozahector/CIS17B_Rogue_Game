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

class MainWindow;
class QLabel;
class QLineEdit;
class QPushButton;

//class LoginDialog : public QDialog, public QGraphicsView
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

private:
    QGraphicsScene *scene;
    QLabel *uLabel;
    QLabel *pLabel;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *guest;
    QPushButton *git;

private slots:
    void enableSubmitButton();
    void website();

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
