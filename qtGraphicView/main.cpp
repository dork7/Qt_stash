#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include <superitem.h>
#include <dots.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;

    QGraphicsView view;
    QGraphicsScene* scene = new QGraphicsScene(0,0,300,300);
    scene->setBackgroundBrush(Qt::darkGray);
    view.setScene(scene);


//    // adding image to the grpahic view
//    QPixmap pixmapItem("F:\\QT_Projects\\qtGraphicView\\img.png");
////    QPixmap pixmapItems = pixmapItem.scaled(QSize(30,30));
//    QImage img = QImage("F:\\QT_Projects\\qtGraphicView\\img.png");
//    QPixmap img2pix = QPixmap::fromImage(img);
////    scene->addPixmap(pixmapItem);

//// adding rect item to scene
//    QGraphicsRectItem* rect = new QGraphicsRectItem(50,50,100,100);
//    QGraphicsRectItem* rect2 = new QGraphicsRectItem(33,50,100,100);
////    qDebug() << rect->pos();


//    rect->setFlags(QGraphicsItem::ItemIsMovable);
//    rect2->setFlags(QGraphicsItem::ItemIsMovable);

//    QGraphicsTextItem * txt = scene->addText("hello world");
//    txt->setFlag(QGraphicsItem::ItemIgnoresTransformations);
//////////////////////////////////////////////////////////////////////////
////    QTransform t = QTransform(); // transformations for graphic view
////    t.rotate(45,Qt::ZAxis);
////    t.scale(1.4,1.5);
////    w.setTransform(t);
//////////////////////////////////////////////////////////////////////////
//    scene->addItem(rect);
//    scene->addItem(rect2);


    //    scene->addText("hello lol");

    dots * dotss = new dots;
    scene->addItem(dotss);
    SuperItem * super = new SuperItem[10];


    scene->addItem(super);
    super->setFocus();



//    view.scale(0.5,0.5);
    view.show();
    return a.exec();
}
