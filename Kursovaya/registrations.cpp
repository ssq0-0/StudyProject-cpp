#include "registrations.h"
#include "ui_registrations.h"
#include "autoriztion.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


registrations::registrations(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registrations)
{
    ui->setupUi(this);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/style.css");
        if (file.open(QFile::ReadOnly)) {
            QTextStream stream(&file);
            QString stylesheet = stream.readAll();
            this->setStyleSheet(stylesheet);
        }
}

registrations::~registrations()
{
    delete ui;
}

void registrations::on_back_to_auto_clicked()
{
    Autoriztion *auth = new Autoriztion();
    auth -> show();
    this -> close();
}


void registrations::on_push_reg_clicked()
{
    QString name = ui->nameLabel->text();
    QString surname = ui->subnameLabel->text();
    QString phone = ui->numberLabel->text();
    QString address = ui->addressLabel->text();
    QString pass = ui -> passLabel -> text();

    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/users.txt"); // Укажите путь к файлу
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out <<"\n"<< name << " "<< pass << " " << surname << " " << phone << " " << address << "\n";
    }
}
