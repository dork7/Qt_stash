#ifndef SONGSLIST_H
#define SONGSLIST_H

#include <QApplication>
#include "globalData.h"
class songsList
{
public:
    songsList();

    songsList(int , QString , QString);


    ~songsList();
    // setter
    void setCue(QString);
    void setSongsList(int , QString , QString);

    // getters

    QString getSongName() const;
    QString getTimeCode() const;

    QString getCueName() const;

//    QVector<

    int getSongID() const;

    songsList * nextNode;

    songsList * prevNode;
    int data;
private:
    QString songName;
    QString songTimeCode;
    int songID;

    QVector<QString> mVec;

    QVector<Cue> cueVec;
    QVector<Cue> stepVec;



};

#endif // SONGSLIST_H
