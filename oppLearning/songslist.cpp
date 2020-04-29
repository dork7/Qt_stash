#include "songslist.h"



songsList::songsList()
{
    songID = 0;
}

songsList::songsList(int id, QString name, QString timeCode)
{
    songID = id;
    songName = name;
    songTimeCode = timeCode;
}
songsList::~songsList(){

}
void songsList::setSongsList(int id, QString name, QString timeCode)
{
    songID = id;
    songName = name;
    songTimeCode = timeCode;
}

void songsList::setCue(QString name)
{
    Cue mCue;
    mCue.cueName = name;
    mCue.cueID = 111;
    mCue.timeCode = "dummy";
    cueVec.push_back(mCue);
}


QString songsList::getSongName() const
{
    return songName;
}

QString songsList::getTimeCode() const
{
    return songTimeCode;
}

QString songsList::getCueName() const
{
    return cueVec[0].cueName;
}

int songsList::getSongID() const
{
    return songID;
}
