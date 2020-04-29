#include <QCoreApplication>
#include "mserver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mServer server;
    server.startServer();

    return a.exec();
}
