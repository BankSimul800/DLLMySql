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

void CreateConnection::getInfo(QString idtili)
{
    QSqlQuery infoDB;

    infoDB.prepare("SELECT * FROM tili WHERE idtili=:idtili");
    infoDB.bindValue(":idtili",idtili);
    infoDB.exec();

   //QString enimi;
   //QString snimi;
   //QString osoite;
   //QString puhnum;

    while (infoDB.next())
    {
        enimi=infoDB.value(1).toString();
        snimi=infoDB.value(2).toString();
        osoite=infoDB.value(3).toString();
        puhnum=infoDB.value(4).toString();
    }

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
 * rahamaara
 */
