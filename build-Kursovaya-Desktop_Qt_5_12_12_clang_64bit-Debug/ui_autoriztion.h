/********************************************************************************
** Form generated from reading UI file 'autoriztion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORIZTION_H
#define UI_AUTORIZTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Autoriztion
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *login;
    QLineEdit *login_place;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *pass_place;
    QPushButton *LogIn;
    QPushButton *registration;

    void setupUi(QWidget *Autoriztion)
    {
        if (Autoriztion->objectName().isEmpty())
            Autoriztion->setObjectName(QString::fromUtf8("Autoriztion"));
        Autoriztion->resize(708, 405);
        gridLayoutWidget = new QWidget(Autoriztion);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(190, 100, 341, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 311, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(-1);
#endif
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 10, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        login = new QLabel(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);

        login_place = new QLineEdit(layoutWidget);
        login_place->setObjectName(QString::fromUtf8("login_place"));

        horizontalLayout->addWidget(login_place);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        password = new QLabel(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));

        horizontalLayout_2->addWidget(password);

        pass_place = new QLineEdit(layoutWidget);
        pass_place->setObjectName(QString::fromUtf8("pass_place"));

        horizontalLayout_2->addWidget(pass_place);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        LogIn = new QPushButton(layoutWidget);
        LogIn->setObjectName(QString::fromUtf8("LogIn"));

        verticalLayout_2->addWidget(LogIn);

        registration = new QPushButton(layoutWidget);
        registration->setObjectName(QString::fromUtf8("registration"));

        verticalLayout_2->addWidget(registration);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(Autoriztion);

        QMetaObject::connectSlotsByName(Autoriztion);
    } // setupUi

    void retranslateUi(QWidget *Autoriztion)
    {
        Autoriztion->setWindowTitle(QApplication::translate("Autoriztion", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Autoriztion", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        login->setText(QApplication::translate("Autoriztion", "Login", nullptr));
        password->setText(QApplication::translate("Autoriztion", " Pass", nullptr));
        LogIn->setText(QApplication::translate("Autoriztion", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        registration->setText(QApplication::translate("Autoriztion", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Autoriztion: public Ui_Autoriztion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORIZTION_H
