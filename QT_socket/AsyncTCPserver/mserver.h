#ifndef MSERVER_H
#define MSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class mServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit mServer(QObject *parent = 0);
    void StartServer();
signals:

public slots:


protected:
    void incomingConnection(qintptr handle);
};

#endif // MSERVER_H
