#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QQuickItem>
#include <QDebug>
#include <QtSql>
#include <QtSql/QSqlDatabase>

class MyDatabase : public QObject
{
    Q_OBJECT
public:
    explicit MyDatabase(QObject *parent = 0);
    ~MyDatabase();

    Q_INVOKABLE void fetchDataFromDatabase(const QString &status);

//    Q_INVOKABLE void kill();
    Q_INVOKABLE void ipundportspeichern(const QString &ip1,const QString &ip2,const QString &ip3,const QString &ip4,const QString &port);
    void IpUndPortEinschreiben();
    void dataToCacheToSend(QString id,QString name);

//    void testDerDatenbank();


private:
    QSqlDatabase db;
    QString statusDatabase;

signals:
    void dataToCacheToSend(QString data);
    void startTimerSet();
//    void startTimerGet();
    void ipAndPortEinschrieben(QString ip1,QString ip2,QString ip3,QString ip4,QString port);


public slots:
};

#endif // MYDATABASE_H
