#include "constructionequipment.h"
#include "ui_constructionequipment.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include "orders.h"
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDialogButtonBox>
#include <QInputDialog>
#include <QDebug>

ConstructionEquipment::ConstructionEquipment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConstructionEquipment)
{
    ui->setupUi(this);
    ui->constuctionequipment->setColumnCount(6);
    constructequip();


    QString stylesheet;

    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/mainStyle.css");
    if (file.open(QFile::ReadOnly)) {
         QTextStream stream(&file);
         stylesheet = stream.readAll();
     }
     stylesheet += "QMainWindow { background-image: url('/Users/ssq/Downloads/2.png'); }";

     this->setStyleSheet(stylesheet);

     QPixmap pix("/Users/ssq/Downloads/1.png");
}

ConstructionEquipment::~ConstructionEquipment()
{
    delete ui;
}

QString ConstructionEquipment::getId() const {
    return id;
}

QString ConstructionEquipment::getName() const {
    return name;
}

QString ConstructionEquipment::getType() const {
    return type;
}

double ConstructionEquipment::getPrice() const {
    return price;
}

int ConstructionEquipment::getCount() const {
    return count;
}

void ConstructionEquipment::setId(const QString &value) {
    id = value;
}

void ConstructionEquipment::setName(const QString &value) {
    name = value;
}

void ConstructionEquipment::setType(const QString &value) {
    type = value;
}

void ConstructionEquipment::setPrice(double value) {
    price = value;
}

void ConstructionEquipment::setCount(int value) {
    count = value;
}

void ConstructionEquipment::on_exit_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    this->close();
}

void ConstructionEquipment::constructequip(){
    ui->constuctionequipment->setRowCount(0);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/ConstructEquipment.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    QTextStream in(&file);

    QStringList headers;
        if (!in.atEnd()) {
            headers = in.readLine().split(" ");
        }

        ui->constuctionequipment->setColumnCount(headers.size() + 1); // +1 для столбца кнопки
        for (int i = 0; i < headers.size(); ++i) {
            ui->constuctionequipment->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
        }
        ui->constuctionequipment->setHorizontalHeaderItem(headers.size(), new QTableWidgetItem("Действие"));

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        if(fields.size() < 5) continue;
        setId(fields[0]);
        setName(fields[1]);
        setType(fields[2]);
        setCount(fields[3].toInt());
        setPrice(fields[4].toDouble());

        int row = ui->constuctionequipment->rowCount();
        ui->constuctionequipment->insertRow(row);
        ui->constuctionequipment->setItem(row, 0, new QTableWidgetItem(getId()));
        ui->constuctionequipment->setItem(row, 1, new QTableWidgetItem(getName()));
        ui->constuctionequipment->setItem(row, 2, new QTableWidgetItem(getType()));
        ui->constuctionequipment->setItem(row, 3, new QTableWidgetItem(QString::number(getCount())));
        ui->constuctionequipment->setItem(row, 4, new QTableWidgetItem(QString::number(getPrice())));


        QPushButton *button = new QPushButton("Купить");
        ui->constuctionequipment->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &ConstructionEquipment::onButtonClicked);
    }
    ui->push_to_contsuct->setVisible(isAdmin());
}

bool ConstructionEquipment::isAdmin() {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if (fields.size() >= 6 && fields[5] == "1") { // Проверка наличия прав администратора
            return true;
        }
    }
    return false;
}


void ConstructionEquipment::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        int row = ui->constuctionequipment->indexAt(button->pos()).row();

        QString id = ui->constuctionequipment->item(row, 0)->text();
        QString name = ui->constuctionequipment->item(row, 1)->text();
        QString type = ui->constuctionequipment->item(row, 2)->text();
        double price = ui->constuctionequipment->item(row, 3)->text().toDouble();
        int availableCount = ui->constuctionequipment->item(row, 4)->text().toInt();

        bool ok;
        int userCount = QInputDialog::getInt(this, tr("Количество товара"),
                                             tr("Введите количество:"), 1, 1, availableCount, 1, &ok);

        if (ok && userCount <= availableCount) {
            availableCount -= userCount;
            ui->constuctionequipment->item(row, 4)->setText(QString::number(availableCount));
            updateEquipmentFile();
            orders orderWindow;
            orderWindow.writeToFile(id, name, QString::number(price), QString::number(userCount), type);
        }
    }
}


void ConstructionEquipment::updateEquipmentFile() {
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/ConstructEquipment.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }

    QTextStream out(&file);
    out << "id name type price count" << "\n";
    for (int row = 0; row < ui->constuctionequipment->rowCount(); ++row) {
        QString id = ui->constuctionequipment->item(row, 0)->text();
        QString name = ui->constuctionequipment->item(row, 1)->text();
        QString type = ui->constuctionequipment->item(row, 2)->text();
        QString price = ui->constuctionequipment->item(row, 3)->text();
        QString count = ui->constuctionequipment->item(row, 4)->text();

        out << id << " " << name << " " << type << " " << price << " " << count << "\n";
    }
    file.close();
}


void ConstructionEquipment::on_push_to_contsuct_clicked()
{
    QDialog dialog(this);
        QFormLayout form(&dialog);

        QLineEdit *editId = new QLineEdit(&dialog);
        QLineEdit *editName = new QLineEdit(&dialog);
        QLineEdit *editPrice = new QLineEdit(&dialog);
        QLineEdit *editCount = new QLineEdit(&dialog);
        QLineEdit *editType = new QLineEdit(&dialog);

        form.addRow(new QLabel("ID:"), editId);
        form.addRow(new QLabel("Name:"), editName);
        form.addRow(new QLabel("Price:"), editPrice);
        form.addRow(new QLabel("Count:"), editCount);
        form.addRow(new QLabel("Type:"), editType);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                   Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        if (dialog.exec() == QDialog::Accepted) {
            QString id = editId->text();
            QString name = editName->text();
            QString price = editPrice->text();
            QString count = editCount->text();
            QString type = editType->text();

            int row = ui->constuctionequipment->rowCount();
            ui->constuctionequipment->insertRow(row);
            ui->constuctionequipment->setItem(row, 0, new QTableWidgetItem(id));
            ui->constuctionequipment->setItem(row, 1, new QTableWidgetItem(name));
            ui->constuctionequipment->setItem(row, 2, new QTableWidgetItem(type));
            ui->constuctionequipment->setItem(row, 3, new QTableWidgetItem(price));
            ui->constuctionequipment->setItem(row, 4, new QTableWidgetItem(count));

            QPushButton *button = new QPushButton("Купить");
            ui->constuctionequipment->setCellWidget(row, 5, button);
            connect(button, &QPushButton::clicked, this, &ConstructionEquipment::onButtonClicked);

            orders orderWindow;
            orderWindow.writeToTableConstruct(id, name, price, count, type);
            updateEquipmentFile();

        }
}

