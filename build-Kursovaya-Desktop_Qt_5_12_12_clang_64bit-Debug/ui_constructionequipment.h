/********************************************************************************
** Form generated from reading UI file 'constructionequipment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRUCTIONEQUIPMENT_H
#define UI_CONSTRUCTIONEQUIPMENT_H

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

class Ui_ConstructionEquipment
{
public:
    QWidget *centralwidget;
    QPushButton *exit;
    QTableWidget *constuctionequipment;
    QPushButton *push_to_contsuct;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConstructionEquipment)
    {
        if (ConstructionEquipment->objectName().isEmpty())
            ConstructionEquipment->setObjectName(QString::fromUtf8("ConstructionEquipment"));
        ConstructionEquipment->resize(800, 600);
        centralwidget = new QWidget(ConstructionEquipment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(650, 20, 113, 32));
        constuctionequipment = new QTableWidget(centralwidget);
        constuctionequipment->setObjectName(QString::fromUtf8("constuctionequipment"));
        constuctionequipment->setGeometry(QRect(0, 60, 791, 471));
        push_to_contsuct = new QPushButton(centralwidget);
        push_to_contsuct->setObjectName(QString::fromUtf8("push_to_contsuct"));
        push_to_contsuct->setGeometry(QRect(530, 20, 113, 32));
        ConstructionEquipment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConstructionEquipment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        ConstructionEquipment->setMenuBar(menubar);
        statusbar = new QStatusBar(ConstructionEquipment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConstructionEquipment->setStatusBar(statusbar);

        retranslateUi(ConstructionEquipment);

        QMetaObject::connectSlotsByName(ConstructionEquipment);
    } // setupUi

    void retranslateUi(QMainWindow *ConstructionEquipment)
    {
        ConstructionEquipment->setWindowTitle(QApplication::translate("ConstructionEquipment", "MainWindow", nullptr));
        exit->setText(QApplication::translate("ConstructionEquipment", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        push_to_contsuct->setText(QApplication::translate("ConstructionEquipment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConstructionEquipment: public Ui_ConstructionEquipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRUCTIONEQUIPMENT_H
