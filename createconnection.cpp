#include "createconnection.h"

CreateConnection::CreateConnection()
{

}
CreateConnection::~CreateConnection()
{

}

bool CreateConnection::openConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("mysli.oamk.fi");
    db.setDatabaseName("opisk_t6puos00");
    db.setUserName("t6puos00");
    db.setPassword("T8Xm7Ye6E3gjh8mE");
    db.open();
    if (!db.open())
    {
        qDebug()<<"ei toimi"<<endl;
        return false;
    }
    qDebug()<<db.isOpenError();
    return true;
}

QString CreateConnection::getBalance()
{
    QSqlQuery balanceDB;

    balanceDB.prepare("SELECT * FROM tili WHERE idtili=:tili");
    balanceDB.bindValue(":tili",idtili);
    balanceDB.exec();
}

bool CreateConnection::cardIDCheck(QString id)
{
    QSqlQuery cardCheckDB;

    cardCheckDB.prepare("Select idkortti FROM kortti WHERE idkortti=:id");
    cardCheckDB.bindValue(":id", id);
    cardCheckDB.exec();
    if(cardCheckDB.exec())
    {
        return true;
    }
            else
    {
            return false;
    }


}

/*
 * saldokysely
 * salasanakysely
 * asiakastietokysely
 * tapahtumakysely
 * nostorajakysely
 * kortinnumeroksely
 *
 */
