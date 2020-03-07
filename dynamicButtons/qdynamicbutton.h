#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;   // A static variable counter buttons rooms
    int getID();        // Function to return a local number buttons




private:

      // Pressing and holding for one full second constitutes a "longpress", set whatever value in milliseconds you want here.
      static const quint64 MY_LONG_PRESS_THRESHOLD=1000;
    int buttonID = 0;   // Local variable number of the button
    bool isPressed = false;

protected:
    // Declare that we are overriding QWidget's events for mouse press and release
      void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
      void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;

signals:
          // Our custom signal to emit once a longpress is detected.

        void mousePressedSIGNAL();

public slots:

        void mousePressedSLOT();

};

#endif // QDYNAMICBUTTON_H
