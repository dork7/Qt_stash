#ifndef MCLIENT_H
#define MCLIENT_H

#include <QObject>

class mClient : public QObject
{
    Q_OBJECT
public:
    explicit mClient(QObject *parent = 0);
    void setSocket(int descriptor);
signals:

public slots:
    void connected();
    void disconneced();
    void readyRead();
    void taskResult(int Number);
};

#endif // MCLIENT_H
