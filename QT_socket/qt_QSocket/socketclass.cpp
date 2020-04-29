#include "socketclass.h"


socketClass::socketClass(QObject *parent):
    QObject(parent)
{

}
void socketClass::Connect(){
    // connected
    socket = new QTcpSocket(this);
    socket->connectToHost("www.google.com.pk",80);

    if (socket->waitForConnected(3000)){
        qDebug() << "connected :";
        //send data
        socket->write("hello sever \n\r\n\r\n\r\n\r\n\r\n\r\n");

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        //read
        qDebug() << "Reading:" << socket->bytesAvailable();

        qDebug() << ": data :  "<< socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected";
    }
    //sent data

    // got data

    // close the conneciton
}
