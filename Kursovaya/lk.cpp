#include "lk.h"
#include "ui_lk.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LK::LK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LK)
{
    ui->setupUi(this);
    fillTableWithData();
    loadUserData();
    QFile file(":/Users/ssq/Desktop/kursach/Kursovaya/lkStyle.css"); // Путь к файлу в ресурсах
    if (file.open(QFile::ReadOnly)) {
        QString stylesheet = file.readAll();
        this->setStyleSheet(stylesheet);
    }
}

LK::~LK()
{
    delete ui;
}

void LK::on_back_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    this->close();
}

void LK::fillTableWithData() {
    ui->orderstable->clear();
        ui->orderstable->setRowCount(0);
        ui->orderstable->setColumnCount(5);
        QStringList headers = {"Id", "Name", "Price", "Count", "Type"};
        ui->orderstable->setHorizontalHeaderLabels(headers);

        QFile file("/Users/ssq/Desktop/kursach/Kursovaya/orders.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(" ");

            if (fields.size() < 5) continue;

            int row = ui->orderstable->rowCount();
            ui->orderstable->insertRow(row);

            for (int i = 0; i < fields.size(); ++i) {
                ui->orderstable->setItem(row, i, new QTableWidgetItem(fields[i]));
            }
        }
    }

void LK::loadUserData() {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/users.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QString name, pass, surname, number, address;
    in >> name >> pass>> surname >> number >> address;

    ui->nameLabel->setText(name);
    ui->surnameLabel->setText(surname);
    ui->numberLabel->setText(number);
    ui->addressLabel->setText(address);
}

