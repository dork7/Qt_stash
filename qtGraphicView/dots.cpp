#include "dots.h"

dots::dots(QGraphicsItem *parent)
{
 setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}


QRectF dots::boundingRect() const{
    return QRectF(0,0,30,30);
}

void dots::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    // making green box
    painter->setBrush(Qt::green);
    painter->drawRoundedRect(5,5,25,25,0,0);
//    for (int i = 0; i < 1000 ; i+=10)
//    painter->drawRoundedRect(0,0,i,i,5,5);
//    making yellow pie over green box
//    painter->translate(15,15);
//     painter->translate(-15,-15);
//    painter->setBrush(Qt::yellow);
//    painter->drawPie(0,0,30,30, - 45* 16 , -270*16);

    if (collidingItems().size() > 0)
    {
        qDebug() << "colided";
    }
    else{
        qDebug() <<  " - ";
    }
    update();
}

