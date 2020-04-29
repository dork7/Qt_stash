#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include "songslist.h"
#include "globalData.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<songsList> mSongVec;
    void createSongVec(QVector<songsList>&);
    void displaySongVec(QVector<songsList>&);

private:
    int songId;
    QString songName;
    QString songTimeCode;

    songsList *newSong;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
