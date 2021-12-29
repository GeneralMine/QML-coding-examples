#include "mydatabase.h"

MyDatabase::MyDatabase(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );

    db.setDatabaseName( "./testdatabase.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }
    else
        qDebug( "SQL:Connected!" );


    QSqlQuery qry;

    qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "names:Table created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS ipundport (id INTEGER UNIQUE PRIMARY KEY, ip1 VARCHAR(30), ip2 VARCHAR(30), ip3 VARCHAR(30), ip4 VARCHAR(30), port VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "ipundport:Table created!";

    qry.prepare( "CREATE TABLE IF NOT EXISTS fahrer (id INTEGER UNIQUE PRIMARY KEY, setup1 VARCHAR(30), setup2 VARCHAR(30), setup3 VARCHAR(30), setup4 VARCHAR(30), setup5 VARCHAR(30))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "fahrer:Table created!";

    QString einfuegen;

    einfuegen="INSERT INTO fahrer (id, setup1, setup2, setup3, setup4, setup5) VALUES (4, '4.1','4.2','4.3','4.4','4.5')";


    //    einfuegen ="INSERT INTO names (id, firstname) VALUES (4, 'eric4')";
    qDebug()<<einfuegen;


    qry.prepare( einfuegen );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug( "Inserted!" );
}

MyDatabase::~MyDatabase()
{
}



void MyDatabase::fetchDataFromDatabase(const QString &status)
{
    statusDatabase=status;
    QSqlQuery qry;
    qDebug()<<statusDatabase;
    if(statusDatabase=="set")
    {


        QString id, name;

        qry.prepare( "SELECT * FROM names" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Selected!" );

            QSqlRecord rec = qry.record();

            int cols = rec.count();

            for( int r=0; qry.next(); r++ )
            {
                for( int c=0; c<cols-1; c++ )
                {
                    //qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                    id= QString("%1").arg(qry.value(c).toString());

                }
                for( int c=1; c<cols; c++ )
                {
                    //qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                    name=QString("%1").arg(qry.value(c).toString());
                }

                dataToCacheToSend(id,name);
            }
            emit startTimerSet();
//            emit startTimerGet();
        }
    }
    else if (statusDatabase=="get")
    {
        //qDebug()<<"get noch nicht fertig";

        qry.prepare( "SELECT setup1, setup2, setup3, setup4, setup5 FROM fahrer WHERE id = 2" );
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qDebug( "Test: Selected!" );

            QSqlRecord rec = qry.record();

            int cols = rec.count();

            //      for( int c=0; c<cols; c++ )
            //        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

            for( int r=0; qry.next(); r++ )
                for( int c=0; c<cols; c++ )
                {
                    //qDebug() << QString( "%1" ).arg( qry.value(c).toString() );
                    dataToCacheToSend(QString( "%1" ).arg( qry.value(c).toString() ));
                }
            emit startTimerSet();

        }
    }

}
void MyDatabase::dataToCacheToSend(QString id, QString name)
{
    // qDebug()<<"id:"<<id;
     //qDebug()<<"name:"<<name;
    emit dataToCacheToSend(id);
}
//void MyDatabase::kill()
//{
//    db.close();
//}

void MyDatabase::IpUndPortEinschreiben()
{
    QSqlQuery qry;
    QString ip1,ip2,ip3,ip4,port;

    qry.prepare( "SELECT * FROM ipundport" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        qDebug( "ipundport: Selected!" );

        QSqlRecord rec = qry.record();

        int cols = rec.count();

        for( int c=0; c<cols; c++ )
            //qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

            for( int r=0; qry.next(); r++ )
                for( int c=0; c<cols; c++ )
                {
                    //qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                    switch(c)
                    {
                    case 1:
                        ip1=QString("%1").arg(qry.value(c).toString() );
                        break;

                    case 2:
                        ip2=QString("%1").arg(qry.value(c).toString() );
                        break;

                    case 3:
                        ip3=QString("%1").arg(qry.value(c).toString() );
                        break;
                    case 4:
                        ip4=QString("%1").arg(qry.value(c).toString() );
                        break;
                    case 5:
                        port=QString("%1").arg(qry.value(c).toString() );
                        break;
                    }
                }
    }

    /*qDebug()<<"ip1:"<<ip1;
    qDebug()<<"ip2:"<<ip2;
    qDebug()<<"ip3:"<<ip3;
    qDebug()<<"ip4:"<<ip4;
    qDebug()<<"port:"<<port;*/


    emit ipAndPortEinschrieben(ip1,ip2,ip3,ip4,port);
}


void MyDatabase::ipundportspeichern(const QString &ip1, const QString &ip2, const QString &ip3, const QString &ip4, const QString &port)
{
    QString einfuegen;
    QSqlQuery qry;

    einfuegen =" DELETE FROM ipundport WHERE id = 0";
    qDebug()<<einfuegen;

    qry.prepare( einfuegen );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug( "Deleted!" );

    einfuegen ="INSERT INTO ipundport (id, ip1, ip2, ip3, ip4, port) VALUES (0, '"+ip1+"', '"+ip2+"', '"+ip3+"', '"+ip4+"', '"+port+"')";
    qDebug()<<einfuegen;

    QSqlQuery qry1;

    qry1.prepare( einfuegen );
    if( !qry1.exec() )
        qDebug() << qry1.lastError();
    else
        qDebug( "Inserted! ip gespeichert" );


    /*qry.prepare( "SELECT * FROM ipundport" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
    {
        qDebug( "Selected!" );

        QSqlRecord rec = qry.record();

        int cols = rec.count();

        for( int c=0; c<cols; c++ )
            qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; qry.next(); r++ )
            for( int c=0; c<cols; c++ )
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
    }*/

}


/*void MyDatabase::testDerDatenbank()
{
    QSqlQuery qry;


    qry.prepare( "SELECT setup1, setup2, setup3, setup4, setup5 FROM fahrer WHERE id = 2" );
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
      qDebug( "Test: Selected!" );

      QSqlRecord rec = qry.record();

      int cols = rec.count();

//      for( int c=0; c<cols; c++ )
//        qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

      for( int r=0; qry.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "%1" ).arg( qry.value(c).toString() );
    }
}*/
