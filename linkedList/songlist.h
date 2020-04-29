#ifndef SONGLIST_H
#define SONGLIST_H

#include <QApplication>
#include "mainwindow.h"

class songList
{
public:
    songList(int , QString , QString);

    QString getSongName() const;
    QString getTimeCode() const;

    void setSongsList(int , QString , QString);

    songList *nextNode;
    friend class MainWindow;
  //  songList *prevNode;

private:
    int songID;
    QString songName;
    QString songTimeCode;

};

#endif // SONGLIST_H
