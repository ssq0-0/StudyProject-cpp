/********************************************************************************
** Form generated from reading UI file 'liftingtransporeequipment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIFTINGTRANSPOREEQUIPMENT_H
#define UI_LIFTINGTRANSPOREEQUIPMENT_H

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

class Ui_LiftingTransporEequipment
{
public:
    QWidget *centralwidget;
    QPushButton *exit;
    QTableWidget *tablelifting;
    QPushButton *push_to_lifting;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LiftingTransporEequipment)
    {
        if (LiftingTransporEequipment->objectName().isEmpty())
            LiftingTransporEequipment->setObjectName(QString::fromUtf8("LiftingTransporEequipment"));
        LiftingTransporEequipment->resize(800, 600);
        centralwidget = new QWidget(LiftingTransporEequipment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(670, 20, 113, 32));
        tablelifting = new QTableWidget(centralwidget);
        tablelifting->setObjectName(QString::fromUtf8("tablelifting"));
        tablelifting->setGeometry(QRect(10, 70, 781, 461));
        push_to_lifting = new QPushButton(centralwidget);
        push_to_lifting->setObjectName(QString::fromUtf8("push_to_lifting"));
        push_to_lifting->setGeometry(QRect(540, 20, 113, 32));
        LiftingTransporEequipment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LiftingTransporEequipment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        LiftingTransporEequipment->setMenuBar(menubar);
        statusbar = new QStatusBar(LiftingTransporEequipment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LiftingTransporEequipment->setStatusBar(statusbar);

        retranslateUi(LiftingTransporEequipment);

        QMetaObject::connectSlotsByName(LiftingTransporEequipment);
    } // setupUi

    void retranslateUi(QMainWindow *LiftingTransporEequipment)
    {
        LiftingTransporEequipment->setWindowTitle(QApplication::translate("LiftingTransporEequipment", "MainWindow", nullptr));
        exit->setText(QApplication::translate("LiftingTransporEequipment", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        push_to_lifting->setText(QApplication::translate("LiftingTransporEequipment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiftingTransporEequipment: public Ui_LiftingTransporEequipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIFTINGTRANSPOREEQUIPMENT_H
