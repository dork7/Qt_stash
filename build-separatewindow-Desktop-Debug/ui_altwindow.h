/********************************************************************************
** Form generated from reading UI file 'altwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTWINDOW_H
#define UI_ALTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AltWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *backBtn;
    QHBoxLayout *horizontalLayout;

    void setupUi(QMainWindow *AltWindow)
    {
        if (AltWindow->objectName().isEmpty())
            AltWindow->setObjectName(QStringLiteral("AltWindow"));
        AltWindow->resize(495, 325);
        centralwidget = new QWidget(AltWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName(QStringLiteral("backBtn"));

        verticalLayout->addWidget(backBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        AltWindow->setCentralWidget(centralwidget);

        retranslateUi(AltWindow);

        QMetaObject::connectSlotsByName(AltWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AltWindow)
    {
        AltWindow->setWindowTitle(QApplication::translate("AltWindow", "Alternative Window", Q_NULLPTR));
        backBtn->setText(QApplication::translate("AltWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AltWindow: public Ui_AltWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTWINDOW_H
