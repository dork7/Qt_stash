#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   /* Assigning a button number which will be further work with buttons
                         * */
//     connect(this, SIGNAL(mousePressedSIGNAL() ), this, SLOT(mousePressedSLOT()));

}

QDynamicButton::~QDynamicButton()
{

}

/* Method to return the value of the button numbers
 * */
int QDynamicButton::getID()
{
    return buttonID;
}


/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
int QDynamicButton::ResID = 0;

//void QDynamicButton::mousePressEvent(QMouseEvent *event)
//{
//    // Remeber last time mousr was pressed
//     qDebug() << " mousePressEvent";

//    isPressed = true;

//    QTimer::singleShot(MY_LONG_PRESS_THRESHOLD, this, SLOT(mousePressedSLOT()));
//}

//void QDynamicButton::mouseReleaseEvent(QMouseEvent *event)
//{
//    isPressed = false;

//    qDebug() << " mouseReleaseEvent";

//}
//void QDynamicButton::mousePressedSLOT()
//{
//    if(isPressed){
//        qDebug() << "worked";
//    }

//}
