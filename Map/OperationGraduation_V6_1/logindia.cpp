#include <iostream>
using namespace std;

#include "LoginDia.h"

LoginDialog::LoginDialog(QWidget *parent) : QGraphicsView(parent)
{
    uLabel = new QLabel;
    pLabel = new QLabel;

    uLabel->setText(tr("Username: "));
    pLabel->setText(tr("Password: "));

    submit = new QPushButton(tr("Submit"));
    exit = new QPushButton(tr("Close"));
    newPlyr = new QPushButton(tr("Register"));
    guest = new QPushButton(tr("Play as Guest"));
    git = new QPushButton(tr("Rogue GitHub"));

    submit->setDefault(true);
    submit->setEnabled(false);

    username = new QLineEdit;
    password = new QLineEdit;

    connect(guest, SIGNAL(clicked(bool)), this, SLOT(newGame()));
    connect(username, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableSubmitButton()));
    connect(password, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableSubmitButton()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(submit, SIGNAL(clicked()), this, SLOT(setUser()));
    connect(git, SIGNAL(clicked()), this, SLOT(website()));

    uLabel->setBuddy(username);
    pLabel->setBuddy(password);

    password->setEchoMode(QLineEdit::Password);

    // set widget backgrounds transparent
    uLabel->setAttribute(Qt::WA_TranslucentBackground);
    pLabel->setAttribute(Qt::WA_TranslucentBackground);
    submit->setAttribute(Qt::WA_TranslucentBackground);
    exit->setAttribute(Qt::WA_TranslucentBackground);
    git->setAttribute(Qt::WA_TranslucentBackground);

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
    scene->addWidget(exit);
    scene->addWidget(git);

    // setting the placement of each widget
    //                   ( X,Y  , W,H )
    uLabel->setGeometry(95,100,50,20);
    username->setGeometry(150,100,150,20);
    pLabel->setGeometry(95,125,50,20);
    password->setGeometry(150,125,150,20);
    submit->setGeometry(95,150,100,20);
    exit->setGeometry(200,150,100,20);
    git->setGeometry(95,175,205,25);
}

void LoginDialog::enableSubmitButton()
{
    bool ok = !uLabel->text().isEmpty()
           && !pLabel->text().isEmpty();
    submit->setEnabled(ok);
}

void LoginDialog::setUser()
{
    uName = uLabel->text();
    pass = pLabel->text();
    prntAll();
}

void LoginDialog::prntAll()
{
    string temp1 = uName.toStdString();
    string temp2 = pass.toStdString();
    cout << "Username: " << temp1 << endl;
    cout << "Password: " << temp2 << endl;
}

void LoginDialog::website()
{
    QDesktopServices::openUrl(QUrl("https://github.com/espinozahector/CIS17B_Rogue_Game"));
}
