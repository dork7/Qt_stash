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

private:
    Ui::MainWindow *ui;
    PopUp *popUp;
};

#endif // MAINWINDOW_H
