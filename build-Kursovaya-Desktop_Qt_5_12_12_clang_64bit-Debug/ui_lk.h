/********************************************************************************
** Form generated from reading UI file 'lk.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LK_H
#define UI_LK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LK
{
public:
    QWidget *centralwidget;
    QPushButton *back;
    QTableWidget *orderstable;
    QLabel *orderslabel;
    QGroupBox *groupBox;
    QLabel *nameLabel;
    QLabel *address;
    QLabel *surname;
    QLabel *surnameLabel;
    QLabel *name;
    QLabel *number;
    QLabel *numberLabel;
    QLabel *addressLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LK)
    {
        if (LK->objectName().isEmpty())
            LK->setObjectName(QString::fromUtf8("LK"));
        LK->resize(800, 600);
        centralwidget = new QWidget(LK);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(680, 10, 113, 32));
        orderstable = new QTableWidget(centralwidget);
        orderstable->setObjectName(QString::fromUtf8("orderstable"));
        orderstable->setGeometry(QRect(20, 110, 521, 311));
        orderslabel = new QLabel(centralwidget);
        orderslabel->setObjectName(QString::fromUtf8("orderslabel"));
        orderslabel->setGeometry(QRect(30, 80, 121, 16));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(550, 90, 241, 191));
        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(130, 20, 60, 16));
        address = new QLabel(groupBox);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(10, 110, 111, 16));
        surname = new QLabel(groupBox);
        surname->setObjectName(QString::fromUtf8("surname"));
        surname->setGeometry(QRect(10, 50, 60, 16));
        surnameLabel = new QLabel(groupBox);
        surnameLabel->setObjectName(QString::fromUtf8("surnameLabel"));
        surnameLabel->setGeometry(QRect(130, 50, 60, 16));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 20, 60, 16));
        number = new QLabel(groupBox);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(10, 80, 60, 16));
        numberLabel = new QLabel(groupBox);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));
        numberLabel->setGeometry(QRect(130, 80, 60, 16));
        addressLabel = new QLabel(groupBox);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));
        addressLabel->setGeometry(QRect(10, 130, 231, 51));
        LK->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LK);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        LK->setMenuBar(menubar);
        statusbar = new QStatusBar(LK);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LK->setStatusBar(statusbar);

        retranslateUi(LK);

        QMetaObject::connectSlotsByName(LK);
    } // setupUi

    void retranslateUi(QMainWindow *LK)
    {
        LK->setWindowTitle(QApplication::translate("LK", "MainWindow", nullptr));
        back->setText(QApplication::translate("LK", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        orderslabel->setText(QApplication::translate("LK", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        groupBox->setTitle(QApplication::translate("LK", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265", nullptr));
        nameLabel->setText(QString());
        address->setText(QApplication::translate("LK", "\320\220\320\264\321\200\320\265\321\201 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
        surname->setText(QApplication::translate("LK", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        surnameLabel->setText(QString());
        name->setText(QApplication::translate("LK", "\320\230\320\274\321\217", nullptr));
        number->setText(QApplication::translate("LK", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        numberLabel->setText(QString());
        addressLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LK: public Ui_LK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LK_H
