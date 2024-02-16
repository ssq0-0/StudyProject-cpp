#include "liftingtransporeequipment.h"
#include "ui_liftingtransporeequipment.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include "orders.h"
#include <QInputDialog>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

LiftingTransporEequipment::LiftingTransporEequipment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LiftingTransporEequipment)
{
    ui->setupUi(this);
    ui->tablelifting->setColumnCount(6);
    tableliftingtransport();
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

LiftingTransporEequipment::~LiftingTransporEequipment()
{
    delete ui;
}
QString LiftingTransporEequipment::getId() const {
    return id;
}

QString LiftingTransporEequipment::getName() const {
    return name;
}

QString LiftingTransporEequipment::getType() const {
    return type;
}

double LiftingTransporEequipment::getPrice() const {
    return price;
}

int LiftingTransporEequipment::getCount() const {
    return count;
}
void LiftingTransporEequipment::setId(const QString &value) {
    id = value;
}

void LiftingTransporEequipment::setName(const QString &value) {
    name = value;
}

void LiftingTransporEequipment::setType(const QString &value) {
    type = value;
}

void LiftingTransporEequipment::setPrice(double value) {
    price = value;
}

void LiftingTransporEequipment::setCount(int value) {
    count = value;
}

void LiftingTransporEequipment::on_exit_clicked()
{
    MainWindow *mw = new MainWindow();
    mw -> show();
    this -> close();
}

void LiftingTransporEequipment::tableliftingtransport() {
    ui->tablelifting->setRowCount(0);
    QFile file("/Users/ssq/Desktop/kursach/Kursovaya/LiftingTransporEequipment.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QStringList headers;
    if (!in.atEnd()) {
        headers = in.readLine().split(" ");
    }

    ui->tablelifting->setColumnCount(headers.size() + 1);
    for (int i = 0; i < headers.size(); ++i) {
        ui->tablelifting->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
    }
    ui->tablelifting->setHorizontalHeaderItem(headers.size(), new QTableWidgetItem("Действие"));

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");

        if(fields.size() < 5) continue;

        setId(fields[0]);
        setName(fields[1]);
        setType(fields[2]);
        setCount(fields[3].toInt());
        setPrice(fields[4].toDouble());

        int row = ui->tablelifting->rowCount();
        ui->tablelifting->insertRow(row);
        ui->tablelifting->setItem(row, 0, new QTableWidgetItem(getId()));
        ui->tablelifting->setItem(row, 1, new QTableWidgetItem(getName()));
        ui->tablelifting->setItem(row, 2, new QTableWidgetItem(getType()));
        ui->tablelifting->setItem(row, 3, new QTableWidgetItem(QString::number(getCount())));
        ui->tablelifting->setItem(row, 4, new QTableWidgetItem(QString::number(getPrice())));


        QPushButton *button = new QPushButton("Купить");
        ui->tablelifting->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &LiftingTransporEequipment::onButtonClicked);
    }
    ui->push_to_lifting->setVisible(isAdmin());
}

bool LiftingTransporEequipment::isAdmin() {
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

void LiftingTransporEequipment::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
         int row = ui->tablelifting->indexAt(button->pos()).row();

         QString id = ui->tablelifting->item(row, 0)->text();
         QString name = ui->tablelifting->item(row, 1)->text();
         QString type = ui->tablelifting->item(row, 2)->text();
         double price = ui->tablelifting->item(row, 3)->text().toDouble();
         int availableCount = ui->tablelifting->item(row, 4)->text().toInt();

         bool ok;
         int userCount = QInputDialog::getInt(this, tr("Количество товара"),
                                                 tr("Введите количество:"), 1, 1, availableCount, 1, &ok);

         if (ok && userCount <= availableCount) {
             availableCount -= userCount;
             ui->tablelifting->item(row, 4)->setText(QString::number(availableCount));
             updateEquipmentFile();
             orders orderWindow;
             orderWindow.writeToFile(id, name, QString::number(price), QString::number(userCount), type);
        }
    }
}

void LiftingTransporEequipment::updateEquipmentFile() {
        QFile file("/Users/ssq/Desktop/kursach/Kursovaya/LiftingTransporEequipment.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
        }

        QTextStream out(&file);
        //file.resize(0);
        out << "id name type price count" << "\n";
        for (int row = 0; row < ui->tablelifting->rowCount(); ++row) {
            QString id = ui->tablelifting->item(row, 0)->text();
            QString name = ui->tablelifting->item(row, 1)->text();
            QString type = ui->tablelifting->item(row, 2)->text();
            QString price = ui->tablelifting->item(row, 3)->text();
            QString count = ui->tablelifting->item(row, 4)->text();

            out << id << " " << name << " " << type << " " << price << " " << count << "\n";
        }
        file.close();
    }


void LiftingTransporEequipment::on_push_to_lifting_clicked(){
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

        int row = ui->tablelifting->rowCount();
        ui->tablelifting->insertRow(row);
        ui->tablelifting->setItem(row, 0, new QTableWidgetItem(id));
        ui->tablelifting->setItem(row, 1, new QTableWidgetItem(name));
        ui->tablelifting->setItem(row, 2, new QTableWidgetItem(type));
        ui->tablelifting->setItem(row, 3, new QTableWidgetItem(price));
        ui->tablelifting->setItem(row, 4, new QTableWidgetItem(count));

        QPushButton *button = new QPushButton("Купить");
        ui->tablelifting->setCellWidget(row, 5, button);
        connect(button, &QPushButton::clicked, this, &LiftingTransporEequipment::onButtonClicked);

        orders orderWindow;
        orderWindow.writeToTableLifting(id, name, price, count, type);
        updateEquipmentFile();

    }
}

