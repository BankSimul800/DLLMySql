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
    bool cardIDCheck();
    QString getAccID();
    double getPass();
    void setCardNum(QString cardNumber);

    QString getInfoLastname();
    QString getInfoAddress();
    QString getInfoPhone();
    QString getInfo();

private:
    QString cardNum;
    QString accID;
};

#endif // CREATECONNECTION_H
