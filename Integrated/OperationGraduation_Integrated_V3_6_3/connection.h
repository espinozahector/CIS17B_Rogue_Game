#ifndef CONNECTION_H
#define CONNECTION_H

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

#endif // CONNECTION_H
