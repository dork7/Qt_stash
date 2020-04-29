#include "mserver.h"

mServer::mServer(QObject *parent) :
    QTcpServer(parent)
{

}
void mServer::startServer(){
    if( !this->listen(QHostAddress::Any,1234))
    {
        qDebug() << " server not started";
    }
    else{
        qDebug() << " listening  ";
    }
}

void mServer::incomingConnection(qintptr handle)
{
    qDebug() << handle  << " connecting .... ";
    mThread *thread = new mThread(handle,this);
  connect(thread, SIGNAL(finished()), thread , SLOT(deleteLater()));
    thread->start();
}
