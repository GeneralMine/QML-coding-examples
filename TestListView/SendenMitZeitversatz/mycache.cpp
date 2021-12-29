#include "mycache.h"

MyCache::MyCache(QObject *parent) : QObject(parent)
{

}

MyCache::~MyCache()
{

}

void MyCache::timerInit()
{
    //creat a timer
    timerSet = new QTimer(this);
//    timerGet = new QTimer(this);

//    //signals and slots
    connect(timerSet,SIGNAL(timeout()),this,SLOT(outputSet()));
//    connect(timerGet,SIGNAL(timeout()),this,SLOT(outputGet()));



}

void MyCache::putDataInCache(QString data)
{
    SetQueue.enqueue(data);
}

void MyCache::startTimerSet()
{
    timerSet->start(200);
}

//void MyCache::startTimerGet()
//{
//    timerGet->start(2000);
//}



void MyCache::outputSet()
{
    QString output;
    if(!SetQueue.isEmpty())
    {
        output=SetQueue.dequeue();// daten an socket uebergeben
        sendsDataToSocket(output);

    }
    else
    {
        timerSet->stop();

        sendsDataToSocket("timer gestoppt");
    }
}


//void MyCache::outputGet()
//{

//}



