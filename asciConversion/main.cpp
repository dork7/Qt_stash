#include "mainwindow.h"

#include <QApplication>
#include <QtDebug>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    string str = "abc";
    for (int i = 0 ; i < str.length() ; i++ )
    {
        qDebug() << str[i];
    }

    /// size of char array
    char arr[] = "aaaaa";
    int length = sizeof(arr)/sizeof(char); // length=6
    qDebug () << " Size of char array " << length << " - " << arr[length];
    qDebug () << " Size of char array usign strlen" << strlen(arr);
    ///
    qDebug() << " Asci value " << char(int('A')+1);
//    MainWindow w;
//    w.show();
    return a.exec();
}
