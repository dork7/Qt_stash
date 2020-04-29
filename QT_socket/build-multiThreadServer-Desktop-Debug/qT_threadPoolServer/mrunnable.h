#ifndef MRUNNABLE_H
#define MRUNNABLE_H
#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

class mRunnable : public QRunnable // QRunnable is not a thread .. its a task that runs on a thread in the threadpool
{
public:
    mRunnable();
    int socketDescriptor;

protected:
    void run();
};

#endif // MRUNNABLE_H
