/********************************************************************************
** Form generated from reading UI file 'storageequipment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORAGEEQUIPMENT_H
#define UI_STORAGEEQUIPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StorageEquipment
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tablestorage;
    QPushButton *exit;
    QPushButton *push_to_storage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StorageEquipment)
    {
        if (StorageEquipment->objectName().isEmpty())
            StorageEquipment->setObjectName(QString::fromUtf8("StorageEquipment"));
        StorageEquipment->resize(800, 600);
        centralwidget = new QWidget(StorageEquipment);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 50, 791, 481));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 479));
        tablestorage = new QTableWidget(scrollAreaWidgetContents);
        if (tablestorage->columnCount() < 6)
            tablestorage->setColumnCount(6);
        if (tablestorage->rowCount() < 1)
            tablestorage->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablestorage->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablestorage->setItem(0, 0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablestorage->setItem(0, 1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablestorage->setItem(0, 2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablestorage->setItem(0, 3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablestorage->setItem(0, 4, __qtablewidgetitem5);
        tablestorage->setObjectName(QString::fromUtf8("tablestorage"));
        tablestorage->setGeometry(QRect(-5, 21, 771, 471));
        tablestorage->setColumnCount(6);
        scrollArea->setWidget(scrollAreaWidgetContents);
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(660, 10, 113, 32));
        push_to_storage = new QPushButton(centralwidget);
        push_to_storage->setObjectName(QString::fromUtf8("push_to_storage"));
        push_to_storage->setGeometry(QRect(530, 10, 113, 32));
        StorageEquipment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StorageEquipment);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        StorageEquipment->setMenuBar(menubar);
        statusbar = new QStatusBar(StorageEquipment);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StorageEquipment->setStatusBar(statusbar);

        retranslateUi(StorageEquipment);

        QMetaObject::connectSlotsByName(StorageEquipment);
    } // setupUi

    void retranslateUi(QMainWindow *StorageEquipment)
    {
        StorageEquipment->setWindowTitle(QApplication::translate("StorageEquipment", "MainWindow", nullptr));

        const bool __sortingEnabled = tablestorage->isSortingEnabled();
        tablestorage->setSortingEnabled(false);
        tablestorage->setSortingEnabled(__sortingEnabled);

        exit->setText(QApplication::translate("StorageEquipment", "\320\275\320\260\320\267\320\260\320\264", nullptr));
        push_to_storage->setText(QApplication::translate("StorageEquipment", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StorageEquipment: public Ui_StorageEquipment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORAGEEQUIPMENT_H
