#ifndef MTHREAD_H
#define MTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>


class mThread : public QThread
{
    Q_OBJECT
public:
    explicit mThread(int ID,QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // MTHREAD_H
