#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>


class socketClass : public QObject
{
    Q_OBJECT
public:
    explicit socketClass(QObject *parent = 0);

    void Connect();
public slots:

private:
    QTcpSocket *socket;
};

#endif // SOCKETCLASS_H
