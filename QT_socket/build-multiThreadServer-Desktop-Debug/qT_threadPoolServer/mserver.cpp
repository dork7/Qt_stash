#include "mserver.h"
#include "mrunnable.h"

mServer::mServer(QObject *parent)
    : QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}
void mServer::startServer(){
    if(this->listen(QHostAddress::Any, 1231)){
        qDebug() << "S E R V E R    S T A R T E D";
    }
    else{
        qDebug() << "E R R O R in starting server ";
    }
}

void mServer::incomingConnection(qintptr handle){

    mRunnable * task = new mRunnable();
   // task->setAutoDelete(true);
    task->socketDescriptor = handle;
    pool->start(task);
}
