#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    roomchild = 0;
    isRoom = false;
    isStat = false;
    isLogin = true;
    ui->setupUi(this);
    lgnScrn();
//    this->setCursor(Qt::BlankCursor); //only makes cursor visible, needs to remove it totally
}

MainWindow::~MainWindow()
{
    delete ui;
}

Connection MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("209.129.8.7");
        db.setDatabaseName("48037");
        db.setUserName("48037");
        db.setPassword("48037cis17b");
        Connection connection;
        connection.db = db;
        if (!db.open()) {
            qDebug() << "Database error occurred";
            connection.connected = false;
            return connection;
        }
        connection.connected = true;

        return connection;
}

void MainWindow::crMnCh()
{
    minichild = new MiniMapChild(ui->mdiArea);
    minichild->setStyleSheet("background-color: #555;");
    minichild->setAttribute(Qt::WA_DeleteOnClose);
    minichild->setWindowFlags(Qt::FramelessWindowHint);
    minichild->show();
    minichild->move(925,5);

    connect(roomchild->game->player,SIGNAL(eatTaco(int,int)),minichild->tacobell,SLOT(miniUpdate(int,int)));
}

void MainWindow::lgnScrn()
{
    isLogin = true;
    ui->mdiArea->setBackground(QColor("black"));
    loginchild = new LoginChild(ui->mdiArea);
    loginchild->setAttribute(Qt::WA_DeleteOnClose);
    loginchild->setWindowFlags(Qt::FramelessWindowHint);
    loginchild->show();

    connect(loginchild->login->exit, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(loginchild->login->newPlyr, SIGNAL(clicked(bool)),
            this, SLOT(newUser()));
    connect(loginchild->login->submit, SIGNAL(clicked(bool)),
            this, SLOT(checkUser()));
}

void MainWindow::crRmCh()
{
    isRoom = true;
    ui->mdiArea->setBackground(QColor("black"));
    roomchild = new RoomChild(ui->mdiArea);
    roomchild->setAttribute(Qt::WA_DeleteOnClose);
    roomchild->setWindowFlags(Qt::FramelessWindowHint);
    roomchild->show();
    roomchild->move(5,155);

    crMnCh();
}

void MainWindow::crStCh()
{
    isStat = true;
//    ui->mdiArea->setBackground(QColor("black"));
    statchild = new StatChild(ui->mdiArea);
    statchild->setAttribute(Qt::WA_DeleteOnClose);
    statchild->setWindowFlags(Qt::FramelessWindowHint);
    statchild->setFixedSize(900,150);
    statchild->show();
    statchild->move(5,0);
}


void MainWindow::newGame()
{
    qDebug() << "starting new game";
    if(isRoom)
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        if(roomchild->game->getMusic()->state() == QMediaPlayer::PlayingState)
        {
            delete roomchild->game->getMusic();
        }
        roomchild->close();
        isRoom = false;
        qDebug() << "1";
        crStCh();
        crRmCh();
    }
    else
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        qDebug() << "2";
        crStCh();
        crRmCh();
    }
}

void MainWindow::newUser()
{
    if(isLogin)
    {
        loginchild->close();
        isLogin = false;
    }

    isNUser = true;
    regchild = new RegisterChild(ui->mdiArea);
    regchild->setAttribute(Qt::WA_DeleteOnClose);
    regchild->setWindowFlags(Qt::FramelessWindowHint);
    regchild->show();

    connect(regchild->nUser->back, SIGNAL(clicked(bool)),
            this, SLOT(lgnScrn()));
    connect(regchild->nUser->submit, SIGNAL(clicked(bool)),
            this, SLOT(validate()));
}

void MainWindow::goBack()
{
    regchild->close();
    isNUser = false;
    lgnScrn();
}

void MainWindow::validate()
{
    bool found = false;

    QByteArray hashed;
    hashed.append(regchild->nUser->getOne());
    hashed = QCryptographicHash::hash(hashed,QCryptographicHash::Sha1);
    qDebug() << "hashed:" << hashed;
//    qDebug() << "new user hash:" << hashed;
    connection = createConnection();
    if ( !connection.connected ){
            qDebug() << "Not connected!";
            exit(1);
    }else{
        qDebug() << "Connected!";
        QSqlQuery query;
        query.exec("SELECT username, password, hi_score, class FROM rogue_table");
        while (query.next()) {
            QString uName = query.value(0).toString();
            if(uName == regchild->nUser->getTwo())
            {
                found = true;
                break;
            }
            else found = false;
        }

        if(!found)
        {
            query.prepare("INSERT INTO rogue_table(username,password) VALUE(?,?)");
            query.addBindValue(regchild->nUser->getTwo());
            query.addBindValue(hashed);
            query.exec();
        }
        else qDebug() << "The username you entered is already taken";

        connection.db.close();
    }
}

void MainWindow::checkUser()
{
    bool found = false;

    QByteArray hashed;
    hashed.append(loginchild->login->getOne());
    hashed = QCryptographicHash::hash(hashed,QCryptographicHash::Sha1);
//    qDebug() << "hashed:" << hashed;
    connection = createConnection();
    if ( !connection.connected ){
            qDebug() << "Not connected!";
            exit(1);
    }else{
        qDebug() << "Connected!";
        QSqlQuery query;
        query.exec("SELECT username, password FROM rogue_table");
        while (query.next()) {
            QString uName = query.value(0).toString();
            if(uName == loginchild->login->getTwo())
            {
                if(query.value(1).toByteArray().constData() == hashed) found = true;
                break;
            }
        }

        if(found)
        {
            qDebug() << "Welcome Back," << query.value(0).toString();
            newGame();
        }
        else qDebug() << "The username and/or password that you entered did not match any of our records";

        connection.db.close();
    }
}
