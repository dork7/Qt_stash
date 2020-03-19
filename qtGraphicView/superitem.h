#ifndef SUPERITEM_H
#define SUPERITEM_H
#include <QGraphicsItem>

#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>


class SuperItem : public QGraphicsItem
{
public:
    SuperItem(QGraphicsItem* parent = nullptr);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
     QRectF boundingRect() const;

     virtual void keyPressEvent(QKeyEvent *event);
     int m_rotation= 0;

};

#endif // SUPERITEM_H
