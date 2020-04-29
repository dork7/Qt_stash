#include "mrunnable.h"

mRunnable::mRunnable()
{

}
void mRunnable::run(){
    if (!socketDescriptor) return;

    QTcpSocket socket;
    socket.setSocketDescriptor(socketDescriptor);

    socket.write("hello socket here xD \r\n");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}
