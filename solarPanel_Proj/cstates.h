#ifndef CSTATES_H
#define CSTATES_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QVector>

#include "ui_mainwindow.h"

namespace Ui
{
    class CStates;
}


class CStates : public QObject
{
    Q_OBJECT
public:
    explicit CStates(QWidget *parent = nullptr);
    void PassUi(Ui::MainWindow *ui);
    Ui::MainWindow *rui;
     QString btnTxt;
    QString getBtnTxt(){
        return btnTxt;
    }

signals:

public slots:
    void c_state_SLOT();

private:
        //QVector<QString > mText_VEC;

signals:
    void CState_SIGNAL();
};

#endif // CSTATES_H
