#include "server.h"

server::server(QObject *parent) : QObject(parent)
{

    mServer = new QTcpServer(this);

    connect(mServer,SIGNAL(newConnection()),this , SLOT(newConnection()));

    if (mServer->listen(QHostAddress::Any, 1234)){
        qDebug() << "server started";
    }
    else {
        qDebug() << "server could not start ";
    }

}

void server::newConnection()
{
    qDebug() << "Client aya ha";

    QTcpSocket *socket = mServer->nextPendingConnection();
    socket->write("hello client \r\n");

    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
   //exit(0);
}
