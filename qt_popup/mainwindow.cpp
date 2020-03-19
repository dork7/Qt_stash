#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    popUp = new PopUp();
    popUp->setPopupText("lol");
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
