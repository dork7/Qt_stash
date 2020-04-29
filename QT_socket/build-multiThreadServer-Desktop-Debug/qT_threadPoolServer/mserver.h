#ifndef MSERVER_H
#define MSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>

class mServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit mServer(QObject *parent = 0);
    void startServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr handle);

private:
    QThreadPool *pool;
};

#endif // MSERVER_H
