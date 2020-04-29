#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QDebug>
#include <QScrollArea>
#include <QVector>
#include <QPushButton>
#include "cstates.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void handleSelections(QString);

private slots:


    void mSelectedSlot(QTreeWidgetItem* item, int col);

    void c_state_SLOT();


    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

private:
    CStates *c_state;

    void setText();
    QVector<QString > mText_VEC;

    QList<QTreeWidgetItem *> items;
    Ui::MainWindow *ui;
    void resetSpinBoxes();
    void resetTextBoxes();

signals:
    void CState_SIGNAL();
};
#endif // MAINWINDOW_H
