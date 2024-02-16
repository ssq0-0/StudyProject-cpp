#include "orders.h"
#include "ui_orders.h"
#include <QFile>
#include <QTextStream>

orders::orders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::orders)
{
    ui->setupUi(this);
}

orders::~orders()
{
    delete ui;
}

void orders::writeToFile(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type) {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/orders.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << id << " " << name << " " << price << " " << count << " " << type << "\n";
}

void orders::writeToTableLifting(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type) {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/LiftingTransporEequipment.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << id << " " << name << " " << price << " " << count << " " << type << "\n";

}

void orders::writeToTableConstruct(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type) {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/ConstructEquipment.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << id << " " << name << " " << price << " " << count << " " << type << "\n";

}

void orders::writeToTableHoist(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type) {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/HoistingEquipment.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << id << " " << name << " " << price << " " << count << " " << type << "\n";

}

void orders::writeToTableStorage(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type) {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/StorageEquipment.txt"); // Укажите правильный путь к файлу
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << id << " " << name << " " << price << " " << count << " " << type << "\n";

}
