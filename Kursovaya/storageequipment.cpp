#include "storageequipment.h"
#include "ui_storageequipment.h"
#include "mainwindow.h"
#include "orders.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QInputDialog>

StorageEquipment::StorageEquipment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StorageEquipment)
{
    ui->setupUi(this);
    ui->tablestorage->setColumnCount(6);
    fillTableWithData();
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

StorageEquipment::~StorageEquipment()
{
    delete ui;
}
QString StorageEquipment::getId() const {
    return id;
}

QString StorageEquipment::getName() const {
    return name;
}

QString StorageEquipment::getType() const {
    return type;
}

double StorageEquipment::getPrice() const {
    return price;
}

int StorageEquipment::getCount() const {
    return count;
}

void StorageEquipment::setId(const QString &value) {
    id = value;
}

void StorageEquipment::setName(const QString &value) {
    name = value;
}

void StorageEquipment::setType(const QString &value) {
    type = value;
}

void StorageEquipment::setPrice(double value) {
    price = value;
}

void StorageEquipment::setCount(int value) {
    count = value;
}

void StorageEquipment::on_exit_clicked()
{
    MainWindow *mw = new MainWindow();
    mw -> show();
    this -> close();
}

void StorageEquipment::fillTableWithData() {
    ui->tablestorage->setRowCount(0);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/StorageEquipment.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QStringList headers;
    if (!in.atEnd()) {
        headers = in.readLine().split(" ");
    }

    ui->tablestorage->setColumnCount(headers.size() + 1);
    for (int i = 0; i < headers.size(); ++i) {
        ui->tablestorage->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
    }
    ui->tablestorage->setHorizontalHeaderItem(headers.size(), new QTableWidgetItem("Action"));

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        if(fields.size() < 5) continue;

        setId(fields[0]);
        setName(fields[1]);
        setType(fields[2]);
        setCount(fields[3].toInt());
        setPrice(fields[4].toDouble());

        int row = ui->tablestorage->rowCount();
        ui->tablestorage->insertRow(row);
        ui->tablestorage->setItem(row, 0, new QTableWidgetItem(getId()));
        ui->tablestorage->setItem(row, 1, new QTableWidgetItem(getName()));
        ui->tablestorage->setItem(row, 2, new QTableWidgetItem(getType()));
        ui->tablestorage->setItem(row, 3, new QTableWidgetItem(QString::number(getCount())));
        ui->tablestorage->setItem(row, 4, new QTableWidgetItem(QString::number(getPrice())));


        QPushButton *button = new QPushButton("Buy");
        ui->tablestorage->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &StorageEquipment::onButtonClicked);
    }
    ui->push_to_storage->setVisible(isAdmin());
}

bool StorageEquipment::isAdmin() {
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

void StorageEquipment::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (button) {
            int row = ui->tablestorage->indexAt(button->pos()).row();
            QString id = ui->tablestorage->item(row, 0)->text();
            QString name = ui->tablestorage->item(row, 1)->text();
            QString type = ui->tablestorage->item(row, 2)->text();
            double price = ui->tablestorage->item(row, 3)->text().toDouble();
            int availableCount = ui->tablestorage->item(row, 4)->text().toInt();

            bool ok;
            int userCount = QInputDialog::getInt(this, tr("Количество товара"),
                                                    tr("Введите количество:"), 1, 1, availableCount, 1, &ok);

            if (ok && userCount <= availableCount) {
                availableCount -= userCount;
                ui->tablestorage->item(row, 4)->setText(QString::number(availableCount));
                updateEquipmentFile();
                orders orderWindow;
                orderWindow.writeToFile(id, name, QString::number(price), QString::number(userCount), type);
           }
       }
   }

   void StorageEquipment::updateEquipmentFile() {
           QFile file("/Users/ssq/Desktop/kursach/Kursovaya/StorageEquipment.txt");
           if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
               return;
           }

           QTextStream out(&file);
           out << "id name type price count" << "\n";
           for (int row = 0; row < ui->tablestorage->rowCount(); ++row) {
               QString id = ui->tablestorage->item(row, 0)->text();
               QString name = ui->tablestorage->item(row, 1)->text();
               QString type = ui->tablestorage->item(row, 2)->text();
               QString price = ui->tablestorage->item(row, 3)->text();
               QString count = ui->tablestorage->item(row, 4)->text();

               out << id << " " << name << " " << type << " " << price << " " << count << "\n";
           }
           file.close();
       }


   void StorageEquipment::on_push_to_storage_clicked(){
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

           int row = ui->tablestorage->rowCount();
           ui->tablestorage->insertRow(row);
           ui->tablestorage->setItem(row, 0, new QTableWidgetItem(id));
           ui->tablestorage->setItem(row, 1, new QTableWidgetItem(name));
           ui->tablestorage->setItem(row, 2, new QTableWidgetItem(type));
           ui->tablestorage->setItem(row, 3, new QTableWidgetItem(price));
           ui->tablestorage->setItem(row, 4, new QTableWidgetItem(count));

           QPushButton *button = new QPushButton("Купить");
           ui->tablestorage->setCellWidget(row, 5, button);
           connect(button, &QPushButton::clicked, this, &StorageEquipment::onButtonClicked);

           orders orderWindow;
           orderWindow.writeToTableStorage(id, name, price, count, type);
           updateEquipmentFile();

       }
   }

