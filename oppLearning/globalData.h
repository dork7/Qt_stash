#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <QApplication>
#include <QDebug>

// glabal vars
struct Cue{
    int cueID;
    QString cueName;
    QString timeCode;

};

struct steps{
    int stepID;
    QString stepName;
};

#endif // GLOBALDATA_H
