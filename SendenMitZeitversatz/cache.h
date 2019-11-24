#ifndef CACHE_H
#define CACHE_H

#include <QObject>

class Cache : public QObject
{
    Q_OBJECT
public:
    explicit Cache(QObject *parent = 0);
    ~Cache();

signals:

public slots:
};

#endif // CACHE_H
