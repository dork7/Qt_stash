#include "mthread.h"

mThread::mThread(int ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}
void mThread::run()
{
    // thread starts here
    qDebug() << " thread started";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Connected";

    exec();
}
void mThread::readyRead(){
    QByteArray data = socket->readAll();

    qDebug() << "client ->" << socketDescriptor << "sent data :: "<< data;

    socket->write(data);
}

void mThread::disconnected()
{
    qDebug() << "client ->" <<  socketDescriptor << " Disconnected :: ";
    socket->deleteLater();
    exit(0);
}
