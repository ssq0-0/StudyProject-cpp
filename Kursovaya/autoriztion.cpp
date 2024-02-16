#include "autoriztion.h"
#include "ui_autoriztion.h"
#include "user.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "registrations.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>

Autoriztion::Autoriztion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Autoriztion)
{
    ui->setupUi(this);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/style.css");
        if (file.open(QFile::ReadOnly)) {
            QTextStream stream(&file);
            QString stylesheet = stream.readAll();
            this->setStyleSheet(stylesheet);
        }

}

Autoriztion::~Autoriztion()
{
    delete ui;
}

void Autoriztion::on_LogIn_clicked()
{
    QString login = ui->login_place->text();
    QString pass = ui->pass_place->text();

    if (User::validateLogin(login.toStdString(), pass.toStdString())) {
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Авторизация", "Неправильный логин или пароль!");
    }
}

void Autoriztion::on_registration_clicked()
{
    registrations *reg = new registrations();
    reg -> show();
    this -> close();
}

