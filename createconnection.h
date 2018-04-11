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
    void getInfo(QString idtili);
    bool cardIDCheck(QString id);

private:
    QString enimi;
    QString snimi;
    QString osoite;
    QString puhnum;
};

#endif // CREATECONNECTION_H
