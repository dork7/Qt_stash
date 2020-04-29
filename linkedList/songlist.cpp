#include "songlist.h"



songList::songList(int id, QString name, QString time):
    songID(id), songName(name) , songTimeCode(time) // initializing list
{
    nextNode = nullptr;
}
