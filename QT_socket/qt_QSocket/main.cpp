#include <QCoreApplication>
#include "socketclass.h"
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    socketClass cTest;
//    cTest.Connect();

    socketTest mTest;
    mTest.test();

    return a.exec();
}
