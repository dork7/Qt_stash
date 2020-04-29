#include "mserver.h"

mServer::mServer(QObject *parent) : QTcpServer(parent)
{

}
void mServer::StartServer(){
    if(this->listen(QHostAddress::Any, 123)){
        qDebug() << "S E R V E R    S T A R T E D";
    }
    else{
        qDebug() << "E R R O R in starting server ";
    }
}
