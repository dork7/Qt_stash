#include "sockettest.h"


socketTest::socketTest(QObject *parent) : QObject(parent)
{

}
void socketTest::test()
{
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()) , this, SLOT(connected()));
    connect(socket,SIGNAL(disconnected()) , this, SLOT(disconnected()));

    connect(socket,SIGNAL(readyRead()) , this, SLOT(readyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)) , this, SLOT(bytesWritten(qint64)));

    qDebug() << " connection.... ";
    socket->connectToHost("www.google.com.pk",80);

    if (!socket->waitForConnected(1000)){
        qDebug() << " error in socket connection.... ";
    }
    //    else {
    //        qdebug() << " CONNECTEDs.... ";

    //    }
}

void socketTest::connected()
{
    qDebug() << " CONNECTEDs....  :)";

    socket->write("READ / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void socketTest::disconnected()
{
    qDebug() << " DISCONNECTEDs.... :\  ";

}

void socketTest::bytesWritten(qint64 bytes)
{
    qDebug() << "WE wrote ------------------------------ :"<< bytes;
}

void socketTest::readyRead()
{
    qDebug() << "Reading : " << socket->readAll();
}
