#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mydatabase.h"
#include "mycache.h"
#include "mysocket.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyDatabase myDatabase;
    MyCache myCache;
    MySocket mySocket;

    QObject::connect(&myDatabase,SIGNAL(dataToCacheToSend(QString)),&myCache,SLOT(putDataInCache(QString)));
    QObject::connect(&myCache,SIGNAL(sendsDataToSocket(QString)),&mySocket,SLOT(fetchData(QString)));
    QObject::connect(&myDatabase,SIGNAL(startTimerSet()),&myCache,SLOT(startTimerSet()));
//    QObject::connect(&myDatabase,SIGNAL(startTimerGet()),&myCache,SLOT(startTimerGet()));

    engine.rootContext()->setContextProperty("MyDatabase", &myDatabase);
    engine.rootContext()->setContextProperty("MySocket",&mySocket);
//    engine.rootContext()->setContextProperty("MyCache",&myCache);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    myCache.timerInit();
    myDatabase.IpUndPortEinschreiben();

    //myDatabase.testDerDatenbank();

    return app.exec();
}
