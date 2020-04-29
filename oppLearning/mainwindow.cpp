#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    createSongVec(mSongVec);
//    displaySongVec(mSongVec);

}

MainWindow::~MainWindow()
{
    delete ui;
}

songsList* getNode(int data)
{
    // allocating space
    songsList* newNode = new songsList();
    // inserting the required data
    newNode->data = data;
    newNode->prevNode = NULL;
    return newNode;
}

void MainWindow::createSongVec(QVector<songsList> & vec)
{
    qDebug() << "addingData";
    for ( int k = 0 ; k < 10 ; k++ ){
        newSong =new songsList();//( k , "song"+ QString::number(k) , "time" + QString::number(k));

        newSong->setSongsList( k , "song"+ QString::number(k) , "time" + QString::number(k));
//        newSong->setCue("lol");
//        vec.push_back(newSong);
    }
}

void MainWindow::displaySongVec(QVector<songsList> & vec)
{

        for ( int k = 0 ; k < 10 ; k++ ){
            qDebug() << " -------------------------- ";
            qDebug() << newSong[k].getSongName();
        }
    //    for ( int k = 0 ; k < vec.size() ; k++ ){
    //        qDebug() << " -------------------------- ";
    ////        qDebug() << vec[k].setCue("lol2");

    //        qDebug() << vec.at(k).getSongID();
    //        qDebug() << vec.at(k).getSongName();
    //        qDebug() << vec.at(k).getTimeCode();
    //        qDebug() << vec.at(k).getCueName();

    //    }
}



