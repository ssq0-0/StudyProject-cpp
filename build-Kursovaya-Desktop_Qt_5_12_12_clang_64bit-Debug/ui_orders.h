/********************************************************************************
** Form generated from reading UI file 'orders.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERS_H
#define UI_ORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orders
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *orders)
    {
        if (orders->objectName().isEmpty())
            orders->setObjectName(QString::fromUtf8("orders"));
        orders->resize(800, 600);
        menubar = new QMenuBar(orders);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        orders->setMenuBar(menubar);
        centralwidget = new QWidget(orders);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        orders->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(orders);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        orders->setStatusBar(statusbar);

        retranslateUi(orders);

        QMetaObject::connectSlotsByName(orders);
    } // setupUi

    void retranslateUi(QMainWindow *orders)
    {
        orders->setWindowTitle(QApplication::translate("orders", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orders: public Ui_orders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERS_H
