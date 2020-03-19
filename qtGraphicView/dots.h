#ifndef DOTS_H
#define DOTS_H
#include <QGraphicsItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

class dots: public QGraphicsItem
{
public:
    dots(QGraphicsItem* parent = nullptr);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
     QRectF boundingRect() const;
};

#endif // DOTS_H
