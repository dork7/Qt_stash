#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    AddRoot("helo 1", "world");
    AddRoot("helo 2", "world");
    AddRoot("helo 3", "world");
    AddRoot("helo 4", "world");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);
    itm->setText(1, Description);
    ui->treeWidget->addTopLevelItem(itm);

    AddChild(itm,"one", "ss");
    AddChild(itm,"two" , "bb");
    AddChild(itm,"three" , "ss");
}

void MainWindow::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, name);
    itm->setText(1, Description);
    parent->addChild(itm);

}

