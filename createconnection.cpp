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

QString CreateConnection::getInfo()
{
    QString enimi;
    QSqlQuery infoDB;

    infoDB.prepare("SELECT etunimi FROM asiakas WHERE idtili=:idtili");
    infoDB.bindValue(":idtili",accID);
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

QString CreateConnection::getInfoLastname()
{
    QString snimi;
    QSqlQuery getLastnameDB;


    getLastnameDB.prepare("SELECT sukunimi FROM asiakas WHERE idtili=:idtili");
    getLastnameDB.bindValue(":idtili",accID);
    getLastnameDB.exec();


    if (getLastnameDB.next())
    {
        snimi=getLastnameDB.value(2).toString();

        return snimi;
    }
else return "ei toimi";
}

QString CreateConnection::getInfoAddress()
{
    QString osoite;
    QSqlQuery getAddressDB;


    getAddressDB.prepare("SELECT osoite FROM asiakas WHERE idtili=:idtili");
    getAddressDB.bindValue(":idtili",accID);
    getAddressDB.exec();


    if (getAddressDB.next())
    {
        snimi=getAddressDB.value(3).toString();

        return osoite;
    }
else return "ei toimi";
}

QString CreateConnection::getInfoPhone()
{
    QString puhnum;
    QSqlQuery getPhoneDB;


    getPhoneDB.prepare("SELECT puhnum FROM asiakas WHERE idtili=:idtili");
    getPhoneDB.bindValue(":idtili",accID);
    getPhoneDB.exec();


    if (getAddressDB.next())
    {
        snimi=getAddressDB.value(4).toString();

        return puhnum;
    }
else return "ei toimi";
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
