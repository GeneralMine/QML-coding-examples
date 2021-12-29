#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QObject(parent)
{
    socket =new QTcpSocket(this);
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
}

MySocket::~MySocket()
{

}

void MySocket::doConnect(const QString &ip1, const QString &ip2, const QString &ip3, const QString &ip4, const quint16 &port)
{
    QString string =ip1+"."+ip2+"."+ip3+"."+ip4;
    qDebug()<<string;
    qDebug()<<port;





    qDebug() << "connecting...";

    // this is not blocking call
    socket->connectToHost(string, port);

    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
//        emit notConnectedqml();
    }
}

void MySocket::connected()
{
    qDebug()<<"connected";
    emit connectedqml();
}

void MySocket::disconnected()
{
    emit notConnectedqml();
}

void MySocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MySocket::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    QString text = socket->readAll();

    qDebug()<<text;
}

void MySocket::fetchData(QString Data)
{
    qDebug()<<"datensenden";
    sendData(Data);
}
void MySocket::sendData(const QString text)
{
    QByteArray ba =text.toLatin1();
    const char *c_str2 =ba.data();
    socket->write(c_str2);
}
void MySocket::kill()
{
     socket->disconnectFromHost();
}

