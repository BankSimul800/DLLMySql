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
    QString getBalance();
    bool cardIDCheck();
    QString getAccIDFromCard();
    QString getPass();
    void setCardNum();

private:
    QString cardNum;
};

#endif // CREATECONNECTION_H
