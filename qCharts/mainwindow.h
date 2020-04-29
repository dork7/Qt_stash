#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "qcustomplot.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addPoint(double x, double y);
    void clearData();
    void plot();
    QCPBars *bars1;
private slots:
    void makePlot();

    void barGraph();
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> q_vx ,q_vy;
    QVector<double> regenData;
    QCPBars *regen;

    double c_val = 0;
    double hwp_val = 0;
    double t_state = 0;
    double sdc_state = 0;

    QCPItemText *c_textLabel;
    QCPItemText *hwp_textLabel;
    QCPItemText *t_textLabel;
    QCPItemText *sdc_textLabel;


    int valX;
    int valY;
};
#endif // MAINWINDOW_H
