#include "hoistingequipment.h"
#include "ui_hoistingequipment.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include "orders.h"
#include <QInputDialog>
#include <QLabel>
#include <QFormLayout>
#include <QDialogButtonBox>

HoistingEquipment::HoistingEquipment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HoistingEquipment)
{
    ui->setupUi(this);
    ui->hoistequip->setColumnCount(6);
    tablehoistequip();
    QString stylesheet;
     QFile file("/Users/ssq/Desktop/kursach/Kursovaya/mainStyle.css");
     if (file.open(QFile::ReadOnly)) {
         QTextStream stream(&file);
         stylesheet = stream.readAll();
     }
     stylesheet += "QMainWindow { background-image: url('/Users/ssq/Downloads/2.png'); }";
     this->setStyleSheet(stylesheet);

     QPixmap pix("/Users/ssq/Downloads/1.png"); // Укажите путь к вашему изображению
}

HoistingEquipment::~HoistingEquipment()
{
    delete ui;
}
QString HoistingEquipment::getId() const {
    return id;
}

QString HoistingEquipment::getName() const {
    return name;
}

QString HoistingEquipment::getType() const {
    return type;
}

double HoistingEquipment::getPrice() const {
    return price;
}

int HoistingEquipment::getCount() const {
    return count;
}

void HoistingEquipment::setId(const QString &value) {
    id = value;
}

void HoistingEquipment::setName(const QString &value) {
    name = value;
}

void HoistingEquipment::setType(const QString &value) {
    type = value;
}

void HoistingEquipment::setPrice(double value) {
    price = value;
}

void HoistingEquipment::setCount(int value) {
    count = value;
}

void HoistingEquipment::tablehoistequip() {
    ui->hoistequip->setRowCount(0);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/HoistingEquipment.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QStringList headers;
    if (!in.atEnd()) {
        headers = in.readLine().split(" ");
    }
    ui->hoistequip->setColumnCount(headers.size() + 1);
    for (int i = 0; i < headers.size(); ++i) {
        ui->hoistequip->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
    }
    ui->hoistequip->setHorizontalHeaderItem(headers.size(), new QTableWidgetItem("Действие"));

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        if(fields.size() < 5) continue;

        setId(fields[0]);
        setName(fields[1]);
        setType(fields[2]);
        setCount(fields[3].toInt());
        setPrice(fields[4].toDouble());

        int row = ui->hoistequip->rowCount();
        ui->hoistequip->insertRow(row);
        ui->hoistequip->setItem(row, 0, new QTableWidgetItem(getId()));
        ui->hoistequip->setItem(row, 1, new QTableWidgetItem(getName()));
        ui->hoistequip->setItem(row, 2, new QTableWidgetItem(getType()));
        ui->hoistequip->setItem(row, 3, new QTableWidgetItem(QString::number(getCount())));
        ui->hoistequip->setItem(row, 4, new QTableWidgetItem(QString::number(getPrice())));

        QPushButton *button = new QPushButton("Купить");
        ui->hoistequip->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &HoistingEquipment::onButtonClicked);
    }
    ui->push_to_hoist->setVisible(isAdmin());
}

bool HoistingEquipment::isAdmin() {
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

void HoistingEquipment::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        int row = ui->hoistequip->indexAt(button->pos()).row();

        QString id = ui->hoistequip->item(row, 0)->text();
        QString name = ui->hoistequip->item(row, 1)->text();
        QString type = ui->hoistequip->item(row, 2)->text();
        double price = ui->hoistequip->item(row, 3)->text().toDouble();
        int availableCount = ui->hoistequip->item(row, 4)->text().toInt();

        bool ok;
        int userCount = QInputDialog::getInt(this, tr("Количество товара"),
                                             tr("Введите количество:"), 1, 1, availableCount, 1, &ok);

        if (ok && userCount <= availableCount) {
            availableCount -= userCount;
            ui->hoistequip->item(row, 4)->setText(QString::number(availableCount));
            updateEquipmentFile();
            orders orderWindow;
            orderWindow.writeToFile(id, name, QString::number(price), QString::number(userCount), type);
        }
    }
}

void HoistingEquipment::updateEquipmentFile() {
        QFile file("/Users/ssq/Desktop/kursach/Kursovaya/HoistingEquipment.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
        }

        QTextStream out(&file);
        out << "id name type price count" << "\n";
        for (int row = 0; row < ui->hoistequip->rowCount(); ++row) {
            QString id = ui->hoistequip->item(row, 0)->text();
            QString name = ui->hoistequip->item(row, 1)->text();
            QString type = ui->hoistequip->item(row, 2)->text();
            QString price = ui->hoistequip->item(row, 3)->text();
            QString count = ui->hoistequip->item(row, 4)->text();

            out << id << " " << name << " " << type << " " << price << " " << count << "\n";
        }
        file.close();
    }


void HoistingEquipment::on_push_to_hoist_clicked(){
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

        int row = ui->hoistequip->rowCount();
        ui->hoistequip->insertRow(row);
        ui->hoistequip->setItem(row, 0, new QTableWidgetItem(id));
        ui->hoistequip->setItem(row, 1, new QTableWidgetItem(name));
        ui->hoistequip->setItem(row, 2, new QTableWidgetItem(type));
        ui->hoistequip->setItem(row, 3, new QTableWidgetItem(price));
        ui->hoistequip->setItem(row, 4, new QTableWidgetItem(count));

        QPushButton *button = new QPushButton("Купить");
        ui->hoistequip->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &HoistingEquipment::onButtonClicked);

        orders orderWindow;
        orderWindow.writeToTableHoist(id, name, price, count, type);
        updateEquipmentFile();

    }
}

void HoistingEquipment::on_pushButton_clicked()
{
    MainWindow *mw = new MainWindow();
    mw -> show();
    this -> close();
}




