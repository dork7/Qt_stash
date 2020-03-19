#include "superitem.h"
SuperItem::SuperItem(QGraphicsItem *parent)
{
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}
QRectF SuperItem::boundingRect() const{
    return QRectF(0,0,30,30);
}
void SuperItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    // making green box
//    painter->setBrush(Qt::green);
//    painter->drawRoundedRect(0,0,30,30,5,5);
//    for (int i = 0; i < 1000 ; i+=10)
//    painter->drawRoundedRect(0,0,i,i,5,5);
//    making yellow pie over green box
    painter->translate(15,15);
    painter->rotate(m_rotation);
    painter->translate(-15,-15);
    painter->setBrush(Qt::yellow);
    painter->drawPie(0,0,30,30, - 45* 16 , -270*16);
}

void SuperItem::keyPressEvent(QKeyEvent * e){
    switch (e->key()) {
    case Qt::Key_Right:
        moveBy(20,0);
        m_rotation = 0;
        break;
    case Qt::Key_Left:
        moveBy(-20,0);
         m_rotation = 180;
        break;
    case Qt::Key_Down:
        moveBy(0,20);
         m_rotation = 90;
        break;
    case Qt::Key_Up:
        moveBy(0,-20);
         m_rotation = 270;
        break;
    }
    update();
}
