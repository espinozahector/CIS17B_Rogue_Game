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
    isChat = false;
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
    minichild->setAttribute(Qt::WA_ShowWithoutActivating);
    minichild->show();
    minichild->move(925,5);

    connect(roomchild->game->player,SIGNAL(eatTaco(int,int)),minichild->tacobell,SLOT(miniUpdate(int,int)));
    connect(roomchild->game,SIGNAL(clearMini()),minichild,SLOT(newTacos()));

    connect(minichild,SIGNAL(reconnect()),this,SLOT(miniReconnect()));
    connect(minichild,SIGNAL(miniClick()),this,SLOT(giveFocus()));
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
    connect(loginchild->login->cnnct, SIGNAL(clicked(bool)),this, SLOT(getServer()));
}

void MainWindow::crRmCh()
{
    isRoom = true;
    ui->mdiArea->setBackground(QColor("black"));
    roomchild = new RoomChild(ui->mdiArea);
    roomchild->setAttribute(Qt::WA_DeleteOnClose);
    roomchild->setWindowFlags(Qt::FramelessWindowHint);
//    roomchild->setWindowModality(Qt::ApplicationModal);
    roomchild->show();
    roomchild->move(5,155);

    connect(roomchild,SIGNAL(gameClick()),this,SLOT(giveFocus()));
    connect(roomchild->game->player,SIGNAL(playToStat(int,int,int)),statchild,SLOT(updateStats(int,int,int)));
    connect(roomchild->game->player,SIGNAL(playLvlUpdate(int,int,int)),statchild,SLOT(updateDisplay(int,int,int)));

    crMnCh();
    roomchild->setFocus();
    roomchild->game->player->setFocus();
}

void MainWindow::crStCh()
{
    isStat = true;
//    ui->mdiArea->setBackground(QColor("black"));
    statchild = new StatChild(ui->mdiArea);
    statchild->setAttribute(Qt::WA_DeleteOnClose);
    statchild->setWindowFlags(Qt::FramelessWindowHint);
    statchild->setAttribute(Qt::WA_ShowWithoutActivating);
    statchild->setFixedSize(900,150);
    statchild->show();
    statchild->move(5,0);

    //connect(statchild,SIGNAL(statClick()),this,SLOT(giveFocus()));
}

void MainWindow::crChCh()
{
    isChat = true;
    chat = new ChatChild(ui->mdiArea);
    chat->setAttribute(Qt::WA_DeleteOnClose);
    chat->setWindowFlags(Qt::FramelessWindowHint);
    chat->setAttribute(Qt::WA_ShowWithoutActivating);
    chat->setFixedSize(350,500);
    chat->show();
    chat->move(925,170);

    chat->setServ(server);
}


void MainWindow::newGame()
{
    qDebug() << "starting new game";
    if(isStat)
    {
        statchild->close();
        isStat = false;
    }
    if(isChat)
    {
        chat->close();
        isChat = false;
    }
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
        crStCh();
        crRmCh();
        crChCh();
    }
    else
    {
        if(isLogin)
        {
           loginchild->close();
           isLogin = false;
        }
        crStCh();
        crRmCh();
        crChCh();
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
    if(!connection.connected) connection = createConnection();
    if ( !connection.connected ){
            regchild->nUser->setEChck(tr("No connection found."));
            //exit(1);
    }else{
        //qDebug() << "Connected!";
        QSqlQuery query;
        query.exec("SELECT username, password FROM rogue_table");
        while (query.next()) {
            QString uName = query.value(0).toString();
            if(uName == regchild->nUser->getTwo())
            {
                found = true;
                break;
            }
            //else found = false;
        }

        if(!found)
        {
            query.prepare("INSERT INTO rogue_table(username,password) VALUE(?,?)");
            query.addBindValue(regchild->nUser->getTwo());
            query.addBindValue(hashed);
            query.exec();
        }
        else regchild->nUser->setEChck(tr("The username you entered is already taken."));

        //connection.db.close();
    }
}

void MainWindow::checkUser()
{
    bool found = false;

    QByteArray hashed;
    hashed.append(loginchild->login->getOne());
    hashed = QCryptographicHash::hash(hashed,QCryptographicHash::Sha1);
    qDebug() << "hashed:" << hashed;
    if(!connection.connected) connection = createConnection();
    if ( !connection.connected ){
            loginchild->login->setEChck(tr("No connection found."));
            //exit(1);
    }else{
        qDebug() << "Connected!";
        QSqlQuery query;
        query.exec("SELECT username, password FROM rogue_table");
        while (query.next()) {
            QString uName = query.value(0).toString();
            if(uName == loginchild->login->getTwo())
            {
                qDebug() << query.value(1).toByteArray();
                if(query.value(1).toByteArray() == hashed) found = true;
                break;
            }
        }

        if(found)
        {
            qDebug() << "Welcome Back," << query.value(0).toString();
            newGame();
        }
        else loginchild->login->setEChck(tr("The username and/or password that you<br>entered did not match any of our records."));

        //connection.db.close();
    }
}

void MainWindow::miniReconnect()
{
    connect(roomchild->game->player,SIGNAL(eatTaco(int,int)),minichild->tacobell,SLOT(miniUpdate(int,int)));
    giveFocus();
}

void MainWindow::giveFocus()
{
    qDebug() << "Giving Focus";
    roomchild->setFocus();
    roomchild->game->player->setFocus();
}

void MainWindow::getServer()
{
    server = loginchild->login->getIp();
}
