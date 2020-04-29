#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddRoot(QString name,  QString Description);

    void AddChild(QTreeWidgetItem * parent, QString name,  QString Description);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
