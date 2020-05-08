#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPushButton>
#include <QLineEdit>
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QLineEdit>

#include <QVBoxLayout>

class PopUp : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

    void setPopupOpacity(float opacity);
    float getPopupOpacity() const;

public:
    explicit PopUp(QWidget *parent = nullptr);
    QString mGetTimeCode();

    void rePosition(int x, int y);
protected:
    void paintEvent(QPaintEvent *event);    // The background will be drawn through the redraw method

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
public slots:
    void setPopupText(const QString& text); // Setting text notification
    void show();                            /* own widget displaying method
                                             * It is necessary to pre-animation settings
                                               * */
    void setSize(int h, int w);
    void setInputVal_SLOT();
    void hideAnimation();                   // Slot start the animation hide
    void hide();                            /* At the end of the animation, it is checked in a given slot,
private slots:
                                             * Does the widget visible, or to hide
                                             * */

signals:
    void valueEntered_SIGNAL(QString);
private:

    int iXdeffarace = -1;
    int iYdeffarance  = -1;
    bool b_mousePressed;

    QLabel label;
    QPushButton btn1;
    QLineEdit popUpInput;
    QVBoxLayout Vlayout;
    QGridLayout layout;
    QPropertyAnimation animation;
    float popupOpacity;
    QTimer *timer;
    QString mInput;
    QString blueBtnClr = "QPushButton{color:white;background-color:qlineargradient(spread:pad, x1:0, y1:0.573, x2:1, y2:0.545, stop:0 rgba(25, 15, 140, 255), stop:1 rgba(1, 0, 91, 255));border-style: solid;border-color: rgb(0, 0, 127);border-width: 1px;border-radius: 5px;}";

    QString greyBtnClr = "QPushButton{color:white;background-color: qlineargradient(spread:pad, x1:0, y1:0.568, x2:1, y2:0.574, stop:0 rgba(79, 79, 79, 255), stop:1 rgba(39, 38, 38, 255));border-style: solid;border-color: rgb(90, 90, 90);border-width: 1px;border-radius: 5px;}";

};

#endif // POPUP_H
