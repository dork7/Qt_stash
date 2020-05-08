#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "popup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();
    void setBtnVal_SLOT(QString);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    PopUp *popUp;
    int iXdeffarace = -1;
    int iYdeffarance  = -1;
    bool b_mousePressed;
protected:
    void resizeEvent(QResizeEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
