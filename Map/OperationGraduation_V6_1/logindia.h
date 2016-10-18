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
//#include "mainwindow.h"

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

private:
    QGraphicsScene *scene;
    QString uName;
    QString pass;
    QLabel *uLabel;
    QLabel *pLabel;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *submit;
    QPushButton *exit;
    QPushButton *newPlyr;
    QPushButton *guest;
    QPushButton *git;

private slots:
    void enableSubmitButton();
    void setUser();
    void website();
};

#endif // LOGINDIA_H
