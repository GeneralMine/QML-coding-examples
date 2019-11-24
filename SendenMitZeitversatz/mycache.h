#ifndef MYCACHE_H
#define MYCACHE_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QQueue>

class MyCache : public QObject
{
    Q_OBJECT
public:
    explicit MyCache(QObject *parent = 0);
    ~MyCache();


    void timerInit();


    QTimer *timerSet;
//    QTimer *timerGet;

private:
    QQueue<QString> SetQueue;

signals:
    void sendsDataToSocket(QString Data);

public slots:
    void putDataInCache(QString data);
    void outputSet();
//    void outputGet();
    void startTimerSet();
//    void startTimerGet();

};

#endif // MYCACHE_H
