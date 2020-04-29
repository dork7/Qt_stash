#include "cstates.h"
#include "ui_mainwindow.h"

CStates::CStates(QWidget *parent) : QObject(parent)
{


}

void CStates::PassUi(Ui::MainWindow *ui)
{
    rui = ui;
    connect(rui->btn_C1, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C3, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C6, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C7, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C8, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C9, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
    connect(rui->btn_C10, SIGNAL(clicked()), this, SLOT(c_state_SLOT()));
}

void CStates::c_state_SLOT()
{

    QObject* button = QObject::sender();
    if (button == rui->btn_C1)
    {
        btnTxt = rui->btn_C1->text();
    }
    else if (button == rui->btn_C3)
    {
        btnTxt = rui->btn_C3->text();
    }
    else if (button == rui->btn_C6)
    {
        btnTxt = rui->btn_C6->text();
    }
    else if (button == rui->btn_C7)
    {
        btnTxt = rui->btn_C7->text();
    }
    else if (button == rui->btn_C8)
    {
        btnTxt = rui->btn_C8->text();
    }
    else if (button == rui->btn_C9)
    {
        btnTxt = rui->btn_C9->text();
    }
    else if (button == rui->btn_C10)
    {
        btnTxt = rui->btn_C10->text();
    }
    qDebug() << " State class " << btnTxt;

    emit CState_SIGNAL();
//    mText_VEC.push_back(btnTxt);
//    setText();
}

