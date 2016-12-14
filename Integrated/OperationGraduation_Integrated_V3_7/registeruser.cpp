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

bool RegisterUser::regEx()
{
    //http://stackoverflow.com/questions/12018245/regular-expression-to-validate-username

    //initializing regular expression stuff
    passRgX = new QRegularExpression("^((?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})$");
    nameRgX = new QRegularExpression("^(?=.{6,20}$)(?![_.])(?!.*[_.]{2})[a-zA-Z0-9._]+(?<![_.])$");
    //bools
    bool one = false, two = false;
    //check password
    passMatch = new QRegularExpressionMatch(passRgX->match(password->text()));
    one = passMatch->hasMatch();
    //check name
    nameMatch = new QRegularExpressionMatch(nameRgX->match(username->text()));
    two = nameMatch->hasMatch();
    //return results
    if(one && two)return true;
    else return false;
}

void RegisterUser::enableSubmit()
{
    //set the bools to false
    bool ok1 = false, ok2 = false, ok3 = false;
    //check to make sure all fields are filled
    ok1 = !username->text().isEmpty()
           && !password->text().isEmpty()
           && !passConfirm->text().isEmpty();
    //check to make sure the two passwords are the same
    if(password->text() == passConfirm->text()) ok2=true;
    //check regular expression matches
    if(ok1 && ok2) ok3 = regEx();
    //set the submit to enabled or disabled
    if(ok1 && ok2 && ok3) submit->setEnabled(true);
    else submit->setEnabled(false);
}
