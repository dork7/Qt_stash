#include "popup.h"


PopUp::PopUp(QWidget *parent) : QWidget(parent)
{
    QObject::connect(&btn1, SIGNAL(clicked()), this, SLOT(setInputVal_SLOT()));

    setWindowFlags(Qt::FramelessWindowHint |        // Disable window decoration
                   Qt::Tool |                       // Discard display in a separate window
                   Qt::WindowStaysOnTopHint);       // Set on top of all windows
    setAttribute(Qt::WA_TranslucentBackground);     // Indicates that the background will be transparent
    setAttribute(Qt::WA_ShowWithoutActivating);     // At the show, the widget does not get the focus automatically

    animation.setTargetObject(this);                // Set the target animation
    animation.setPropertyName("popupOpacity");      //
    connect(&animation, &QAbstractAnimation::finished, this, &PopUp::hide);
    this->setMinimumSize(QSize(200,200));


    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label.setStyleSheet("QLabel { color : white; "
                        "margin-top: 6px;"
                        "margin-bottom: 6px;"
                        "margin-left: 10px;"
                        "margin-right: 10px; }");

    popUpInput.setStyleSheet("background-color: rgb(90, 90, 90);"
                             "border-style: solid;border-color: rgb(90, 90, 90)"
                             ";border-width: 5px;border-radius: 7px;\n"
                             "color:rgb(255, 255, 255)\n");

//    label.setMaximumHeight(/*20*/);
//    QWidget innerWidget;

    btn1.setText("Apply");
    btn1.setMinimumHeight(30);
    btn1.setStyleSheet(blueBtnClr);
    Vlayout.addStretch(1);
    Vlayout.addWidget(&label);
    Vlayout.addWidget(&popUpInput);
    Vlayout.addWidget(&btn1);
    Vlayout.addStretch(1);

    setLayout(&Vlayout);

    timer = new QTimer();

}

QString PopUp::mGetTimeCode()
{
    return mInput;
}

void PopUp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);



    QRect roundedRect;
    roundedRect.setX(rect().x() + 6);
    roundedRect.setY(rect().y() + 6);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);



    painter.setBrush(QBrush(QColor(0,0,0,180)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect, 10, 10);

    // inner rect
    QRect roundedRect2;
    roundedRect2.setX(rect().x() + 5);
    roundedRect2.setY(rect().y() + 50);
    roundedRect2.setWidth(rect().width() - 10);
    roundedRect2.setHeight(rect().height() - 80);

    painter.setBrush(QBrush(QColor(0,0,0,222)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect2, 10, 10);
}

void PopUp::setPopupText(const QString &text)
{
    label.setText(text);    // Set the text in the Label
    adjustSize();           // With the recalculation notice sizes
}

void PopUp::show()
{
    setWindowOpacity(0.0);  // Set the transparency to zero

    animation.setDuration(150);     // Configuring the duration of the animation
    animation.setStartValue(0.0);   // The start value is 0 (fully transparent widget)
    animation.setEndValue(1.0);     // End - completely opaque widget

    setGeometry(QApplication::desktop()->availableGeometry().width() - 36 - width() + QApplication::desktop() -> availableGeometry().x(),
                QApplication::desktop()->availableGeometry().height() - 36 - height() + QApplication::desktop() -> availableGeometry().y(),
                width(),
                height());
    QWidget::show();

    animation.start();
    timer->start(3000);
}

void PopUp::setInputVal_SLOT()
{
    mInput = popUpInput.text();
    qDebug() << " - - " << mInput;
    emit valueEntered_SIGNAL(mInput);


    timer->start(500);
    //connect(timer, &QTimer::timeout, this, &PopUp::hideAnimation);
}

void PopUp::hideAnimation()
{
    timer->stop();
    animation.setDuration(1000);
    animation.setStartValue(1.0);
    animation.setEndValue(0.0);
    animation.start();
}

void PopUp::hide()
{
    // If the widget is transparent, then hide it
    if(getPopupOpacity() == 0.0){
        QWidget::hide();
    }
}

void PopUp::setPopupOpacity(float opacity)
{
    popupOpacity = opacity;

    setWindowOpacity(opacity);
}

float PopUp::getPopupOpacity() const
{
    return popupOpacity;
}
