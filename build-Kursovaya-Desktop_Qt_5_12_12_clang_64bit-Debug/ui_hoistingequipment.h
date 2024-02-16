/********************************************************************************
** Form generated from reading UI file 'hoistingequipment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOISTINGEQUIPMENT_H
#define UI_HOISTINGEQUIPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoistingEquipment
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableWidget *hoistequip;
    QPushButton *push_to_hoist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HoistingEquipment)
    {
        if (HoistingEquipment->objectName().isEmpty())
            HoistingEquipment->setObjectName(QString::fromUtf8("HoistingEquipment"));
        HoistingEquipment->resize(800, 600);
        centralwidget = new QWidget(HoistingEquipment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 20, 113, 32));
        hoistequip = new QTableWidget(centralwidget);
        hoistequip->setObjectName(QString::fromUtf8("hoistequip"));
        hoistequip->setGeometry(QRect(10, 70, 781, 461));
        push_to_hoist = new QPushButton(centralwidget);
        push_to_hoist->setObjectName(QString::fromUtf8("push_to_hoist"));
        push_to_hoist->setGeometry(QRect(540, 20, 113, 32));
        HoistingEquipment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HoistingEquipment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        HoistingEquipment->setMenuBar(menubar);
        statusbar = new QStatusBar(HoistingEquipment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HoistingEquipment->setStatusBar(statusbar);

        retranslateUi(HoistingEquipment);

        QMetaObject::connectSlotsByName(HoistingEquipment);
    } // setupUi

    void retranslateUi(QMainWindow *HoistingEquipment)
    {
        HoistingEquipment->setWindowTitle(QApplication::translate("HoistingEquipment", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("HoistingEquipment", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        push_to_hoist->setText(QApplication::translate("HoistingEquipment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HoistingEquipment: public Ui_HoistingEquipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOISTINGEQUIPMENT_H
