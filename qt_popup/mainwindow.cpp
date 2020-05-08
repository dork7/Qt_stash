#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    qDebug() << this->geometry().x();
    //    qDebug() << this->geometry().y();

    QRect widgetRect = ui->centralWidget->geometry();

    //    qDebug() << widgetRect.x();
    //    qDebug() << widgetRect.y();
    qDebug() << "- - - - - - - - - - - - - - - - - - --";

    //    qDebug() << this->pos().x();
    //    qDebug() << this->pos().y();

    popUp = new PopUp();
    popUp->setPopupText("popup");
    //    ui->centralWidget->size().height() ; ui->centralWidget->size().width();
    popUp->show();
    connect(popUp, SIGNAL(valueEntered_SIGNAL(QString)) , this, SLOT(setBtnVal_SLOT(QString)));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBtnVal_SLOT(QString val)
{
    qDebug() << "Main" <<  val;
}

void MainWindow::on_pushButton_2_clicked()
{
    popUp->hideAnimation();
}

void MainWindow::on_pushButton_clicked()
{
    popUp->setPopupText("popup");
    popUp->show();
}
void MainWindow::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event)
    popUp->setSize(ui->widget->size().height() , ui->widget->size().width());
    QPoint qpAppNewLoc(  (QCursor::pos().x() - iXdeffarace) , (QCursor::pos().y() - iYdeffarance)  );
    qDebug() << qpAppNewLoc.x();
    qDebug() << qpAppNewLoc.y();
    popUp->rePosition(qpAppNewLoc.x() ,qpAppNewLoc.y());
    this->setProperty("pos", qpAppNewLoc);
}
void MainWindow::mouseReleaseEvent ( QMouseEvent * event )
{
    Q_UNUSED(event)
    b_mousePressed = false;
}

void MainWindow::mouseMoveEvent ( QMouseEvent * event )
{
    Q_UNUSED(event)

    if(b_mousePressed)
    {
        QPoint qpAppNewLoc(  (QCursor::pos().x() - iXdeffarace) , (QCursor::pos().y() - iYdeffarance)  );
        qDebug() << qpAppNewLoc.x();
        qDebug() << qpAppNewLoc.y();
        popUp->rePosition(qpAppNewLoc.x() ,qpAppNewLoc.y());
        this->setProperty("pos", qpAppNewLoc);
    }
}
void MainWindow::mousePressEvent ( QMouseEvent * event)
{
    Q_UNUSED(event)
    b_mousePressed = true;
    QPoint qpMousePressedPoint = QCursor::pos();
    QPoint qpApploc = this->pos();
    iXdeffarace = qpMousePressedPoint.x() - qpApploc.x();
    iYdeffarance = qpMousePressedPoint.y() - qpApploc.y();
}

