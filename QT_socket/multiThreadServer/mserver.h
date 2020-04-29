#ifndef MSERVER_H
#define MSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include "mthread.h"

class mServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit mServer(QObject *parent = 0);
    void startServer();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // MSERVER_H
