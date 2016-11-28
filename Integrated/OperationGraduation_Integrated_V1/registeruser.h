#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>

class MainWindow;
class QLabel;
class QLineEdit;
class QPushButton;

class RegisterUser : public QGraphicsView
{
    Q_OBJECT

public:
    RegisterUser(QWidget *parent = 0);
    ~RegisterUser();
    QPushButton *submit;
    QPushButton *back;
    QString getOne() {return password->text();}
    QString getTwo() {return username->text();}
    void setEChck(QString data) {eCheck->setText(data);}
    void setOne(QString data) {password->setPlaceholderText(data); passConfirm->setPlaceholderText(data);}

private:
    QGraphicsScene *scene;
    QLabel *uLabel;         // label for new username
    QLabel *pLabel;         // label for new password
    QLabel *pLabelC;        // label for password confirmation
    QLineEdit *username;    // line edit for new username
    QLineEdit *password;    // line edit for new password
    QLineEdit *passConfirm; // line edit for password confirmation
    QLabel *eCheck;         // label for error message

private slots:
    void passChck();
    void enableSubmit();
};

#endif // REGISTERUSER_H
