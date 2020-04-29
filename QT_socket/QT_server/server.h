#ifndef SERVER_H
#define SERVER_H

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

#include <QObject>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = 0);

signals:



public slots:
    void newConnection();

private:
    QTcpServer *mServer;

};

#endif // SERVER_H
