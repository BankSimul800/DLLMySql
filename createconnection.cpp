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

bool CreateConnection::cardIDCheck()
{
    QSqlQuery cardCheckDB;
    QString idTili;

    cardCheckDB.prepare("Select idtili FROM kortti WHERE korttinum=:id");
    cardCheckDB.bindValue(":id", cardNum);
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

QString CreateConnection::getPass(QString idtili)
{
    QString pass;
    QSqlQuery getPassDB;

    getPassDB.prepare("SELECT tunnusluku FROM tili WHERE idtili=:idtili");
    getPassDB.bindValue(":cardNum", idtili);
    getPassDB.exec();
    if(getPassDB.next())
    {
        pass = getPassDB.value(0).toString();
        return pass;
    }
    else return "Password couldn't be retrieved";
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
