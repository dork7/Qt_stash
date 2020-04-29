#ifndef SOCKETTESTT_H
#define SOCKETTESTT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>

class socketTest : public QObject
{
    Q_OBJECT
public:
    explicit socketTest(QObject *parent = 0);
    void test();
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCKETTESTT_H
