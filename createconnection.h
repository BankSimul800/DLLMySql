#ifndef CREATECONNECTION_H
#define CREATECONNECTION_H

#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>

class CreateConnection
{
public:
    CreateConnection();
    ~CreateConnection();
    bool openConnection();
};

#endif // CREATECONNECTION_H
