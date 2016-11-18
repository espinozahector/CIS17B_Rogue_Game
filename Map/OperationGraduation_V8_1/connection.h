#ifndef CONNECTION
#define CONNECTION

#include <QApplication>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>

struct Connection
{
    QSqlDatabase db;
    bool connected;
};

#endif // CONNECTION

