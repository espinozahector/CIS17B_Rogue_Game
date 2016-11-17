#ifndef LOGINDIA_H
#define LOGINDIA_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>
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
    void prntAll();
    QPushButton *exit;
private:
    QGraphicsScene *scene;
    QString uName;          //stored username
    QString pass;           //stored password
    QLabel *uLabel;
    QLabel *pLabel;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *submit;
    QPushButton *newPlyr;
    QPushButton *guest;
    QPushButton *git;

private slots:
    void enableSubmitButton();
    void setUser();
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
