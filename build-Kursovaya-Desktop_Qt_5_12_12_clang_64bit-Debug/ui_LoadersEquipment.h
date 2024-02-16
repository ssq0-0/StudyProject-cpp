/********************************************************************************
** Form generated from reading UI file 'loadersequipment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADERSEQUIPMENT_H
#define UI_LOADERSEQUIPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadersEquipment
{
public:
    QWidget *centralwidget;
    QLabel *image2;
    QPushButton *exit2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoadersEquipment)
    {
        if (LoadersEquipment->objectName().isEmpty())
            LoadersEquipment->setObjectName(QString::fromUtf8("LoadersEquipment"));
        LoadersEquipment->resize(800, 600);
        centralwidget = new QWidget(LoadersEquipment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image2 = new QLabel(centralwidget);
        image2->setObjectName(QString::fromUtf8("image2"));
        image2->setGeometry(QRect(0, 0, 571, 461));
        exit2 = new QPushButton(centralwidget);
        exit2->setObjectName(QString::fromUtf8("exit2"));
        exit2->setGeometry(QRect(660, 10, 113, 32));
        LoadersEquipment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoadersEquipment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        LoadersEquipment->setMenuBar(menubar);
        statusbar = new QStatusBar(LoadersEquipment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoadersEquipment->setStatusBar(statusbar);

        retranslateUi(LoadersEquipment);

        QMetaObject::connectSlotsByName(LoadersEquipment);
    } // setupUi

    void retranslateUi(QMainWindow *LoadersEquipment)
    {
        LoadersEquipment->setWindowTitle(QApplication::translate("LoadersEquipment", "MainWindow", nullptr));
        image2->setText(QString());
        exit2->setText(QApplication::translate("LoadersEquipment", "\320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadersEquipment: public Ui_LoadersEquipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADERSEQUIPMENT_H
