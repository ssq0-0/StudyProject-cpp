/********************************************************************************
** Form generated from reading UI file 'registrations.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONS_H
#define UI_REGISTRATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registrations
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *pass;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameLabel;
    QLineEdit *subnameLabel;
    QLineEdit *numberLabel;
    QLineEdit *addressLabel;
    QLineEdit *passLabel;
    QPushButton *push_reg;
    QPushButton *back_to_auto;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registrations)
    {
        if (registrations->objectName().isEmpty())
            registrations->setObjectName(QString::fromUtf8("registrations"));
        registrations->resize(800, 600);
        centralwidget = new QWidget(registrations);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 100, 361, 281));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 40, 321, 221));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        pass = new QLabel(widget);
        pass->setObjectName(QString::fromUtf8("pass"));

        verticalLayout_3->addWidget(pass);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameLabel = new QLineEdit(widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout_2->addWidget(nameLabel);

        subnameLabel = new QLineEdit(widget);
        subnameLabel->setObjectName(QString::fromUtf8("subnameLabel"));

        verticalLayout_2->addWidget(subnameLabel);

        numberLabel = new QLineEdit(widget);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));

        verticalLayout_2->addWidget(numberLabel);

        addressLabel = new QLineEdit(widget);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        verticalLayout_2->addWidget(addressLabel);

        passLabel = new QLineEdit(widget);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));

        verticalLayout_2->addWidget(passLabel);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        push_reg = new QPushButton(widget);
        push_reg->setObjectName(QString::fromUtf8("push_reg"));

        verticalLayout_4->addWidget(push_reg);

        back_to_auto = new QPushButton(centralwidget);
        back_to_auto->setObjectName(QString::fromUtf8("back_to_auto"));
        back_to_auto->setGeometry(QRect(450, 60, 113, 32));
        registrations->setCentralWidget(centralwidget);
        menubar = new QMenuBar(registrations);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 37));
        registrations->setMenuBar(menubar);
        statusbar = new QStatusBar(registrations);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        registrations->setStatusBar(statusbar);

        retranslateUi(registrations);

        QMetaObject::connectSlotsByName(registrations);
    } // setupUi

    void retranslateUi(QMainWindow *registrations)
    {
        registrations->setWindowTitle(QApplication::translate("registrations", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("registrations", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QApplication::translate("registrations", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QApplication::translate("registrations", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("registrations", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_4->setText(QApplication::translate("registrations", "\320\220\320\264\321\200\320\265\321\201 ", nullptr));
        pass->setText(QApplication::translate("registrations", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        push_reg->setText(QApplication::translate("registrations", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        back_to_auto->setText(QApplication::translate("registrations", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registrations: public Ui_registrations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONS_H
