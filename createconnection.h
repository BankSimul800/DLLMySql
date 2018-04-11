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
    QString getAccID();
    double getPass();
    void setCardNum(QString cardNumber);

private:
    QString cardNum;
    QString accID;
};

#endif // CREATECONNECTION_H
