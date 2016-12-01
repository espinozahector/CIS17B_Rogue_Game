#include "registeruser.h"

RegisterUser::RegisterUser(QWidget *parent) : QGraphicsView(parent)
{
    // initializing labels
    uLabel = new QLabel;
    pLabel = new QLabel;
    pLabelC = new QLabel;

    uLabel->setText(tr("Username:"));
    pLabel->setText(tr("Password:"));
    pLabelC->setText(tr("Confirm:"));

    // initializing line edits
    username = new QLineEdit;
    password = new QLineEdit;
    passConfirm = new QLineEdit;

    // setting label-line edit buddies
    uLabel->setBuddy(username);
    pLabel->setBuddy(password);
    pLabelC->setBuddy(passConfirm);

    // initializing push buttons
    submit = new QPushButton(tr("Submit"));
    back = new QPushButton(tr("Back"));

    // initializing validation labels
    eCheck = new QLabel;
    eCheck->setText(tr(""));

    // setting submit default to true and enabled to false
    submit->setDefault(true);
    submit->setEnabled(false);

    // connecting S&S for checking if all fields are filled in
    // line edit connections
    connect(username, SIGNAL(textChanged(QString)),
            this, SLOT(enableSubmit()));
    connect(password, SIGNAL(textChanged(QString)),
            this, SLOT(enableSubmit()));
    connect(passConfirm, SIGNAL(textChanged(QString)),
            this, SLOT(enableSubmit()));

    // connecting SIGNALS and SLOTS for checking
    // if the password and confirm password are identical
    connect(password,SIGNAL(textChanged(QString)),
            this,SLOT(passChck()));
    connect(passConfirm,SIGNAL(textChanged(QString)),
            this,SLOT(passChck()));

    password->setEchoMode(QLineEdit::Password);
    passConfirm->setEchoMode(QLineEdit::Password);

    // set widget backgrounds transparent
    uLabel->setAttribute(Qt::WA_TranslucentBackground);
    pLabel->setAttribute(Qt::WA_TranslucentBackground);
    pLabelC->setAttribute(Qt::WA_TranslucentBackground);
    submit->setAttribute(Qt::WA_TranslucentBackground);
    back->setAttribute(Qt::WA_TranslucentBackground);
    eCheck->setAttribute(Qt::WA_TranslucentBackground);

    eCheck->setStyleSheet("color: red;");

    // initializing and setting the scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,400,301);

    setScene(scene);
    // adding the widgets to the scene
    scene->addWidget(uLabel);
    scene->addWidget(username);
    scene->addWidget(pLabel);
    scene->addWidget(password);
    scene->addWidget(pLabelC);
    scene->addWidget(passConfirm);
    scene->addWidget(submit);
    scene->addWidget(back);
    scene->addWidget(eCheck);

    // setting the placement of each widget
    //                 ( X,Y  , W,H )
    uLabel->setGeometry(95,100,50,20);
    username->setGeometry(150,100,150,20);
    pLabel->setGeometry(95,125,50,20);
    password->setGeometry(150,125,150,20);
    pLabelC->setGeometry(95,150,50,20);
    passConfirm->setGeometry(150,150,150,20);
    submit->setGeometry(95,175,100,20);
    back->setGeometry(200,175,100,20);
    eCheck->setGeometry(95,200,250,20);
}

RegisterUser::~RegisterUser()
{
    delete scene;
    delete uLabel;
    delete pLabel;
    delete pLabelC;
    delete username;
    delete password;
    delete passConfirm;
    delete submit;
    delete back;
    delete eCheck;
}

void RegisterUser::passChck()
{
    if(password->text() == passConfirm->text()) submit->setEnabled(true);
    else submit->setEnabled(false);
}

void RegisterUser::enableSubmit()
{
    bool ok = !username->text().isEmpty()
           && !password->text().isEmpty()
           && !passConfirm->text().isEmpty();
    submit->setEnabled(ok);
}
