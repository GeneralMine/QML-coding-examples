#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class MySocket : public QObject
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = 0);
     ~MySocket();

    Q_INVOKABLE void doConnect(const QString &ip1,const QString &ip2,const QString &ip3,const QString &ip4,const quint16 &port);
    Q_INVOKABLE void kill();
    void sendData(const QString text);

private:
    QTcpSocket *socket;

signals:
    void connectedqml();
    void notConnectedqml();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void fetchData(QString data);


};

#endif // MYSOCKET_H
