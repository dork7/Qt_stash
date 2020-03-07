#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->widget_2->setWindowFlag(Qt::Popup);
//    ui->widget_2->show();

     popUp = new PopUp();
     popUp->setPopupText("lol");
     popUp->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
