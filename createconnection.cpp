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

QString CreateConnection::getInfo(QString idtili)
{
    QString enimi;
    QSqlQuery infoDB;

    infoDB.prepare("SELECT nimi FROM asiakas WHERE idtili=:idtili");
    infoDB.bindValue(":idtili",idtili);
    infoDB.exec();

   //QString enimi;
   //QString snimi;
   //QString osoite;
   //QString puhnum;

    if (infoDB.next())
    {
        enimi=infoDB.value(1).toString();
        //snimi=infoDB.value(2).toString();
        //osoite=infoDB.value(3).toString();
        //puhnum=infoDB.value(4).toString();
        return enimi;
    }
else return "ei toimi";
}

void CreateConnection::setCardNum(QString cardNumber)
{
    cardNum = cardNumber;
}

bool CreateConnection::cardIDCheck()
{
    QSqlQuery cardCheckDB;

    cardCheckDB.prepare("Select idtili FROM kortti WHERE korttinum=:id");
    cardCheckDB.bindValue(":id", cardNum);
    cardCheckDB.exec();
    if(cardCheckDB.exec())
    {
        if(cardCheckDB.next())
        {
            accID = cardCheckDB.value(0).toString();
            return true;
        }
    }

    else
    {
            return false;
    }
}



double CreateConnection::getPass()
{
    double pass;
    QSqlQuery getPassDB;

    getPassDB.prepare("SELECT tunnusluku FROM tili WHERE idtili=:idtili");
    getPassDB.bindValue(":idtili", accID);
    getPassDB.exec();
    if(getPassDB.next())
    {
        pass = getPassDB.value(0).toDouble();
        return pass;
    }
    else return 0;
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
