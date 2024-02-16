#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autoriztion.h"
#include "lk.h"
#include "constructionequipment.h"
#include "storageequipment.h"
#include "liftingtransporeequipment.h"
#include "hoistingequipment.h"
#include <QTextStream>
#include <QDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString stylesheet;
        QFile file("/Users/ssq/Desktop/kursach/Kursovaya/mainStyle.css");
        if (file.open(QFile::ReadOnly)) {
            QTextStream stream(&file);
            stylesheet = stream.readAll();
        }

        stylesheet += "QMainWindow { background-image: url('/Users/ssq/Downloads/2.png'); }";

        this->setStyleSheet(stylesheet);

        QPixmap pix("/Users/ssq/Downloads/1.png");
        ui->image->setPixmap(pix.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_clicked()
{
    Autoriztion *authWindow = new Autoriztion();
    authWindow->show();
    this->close();
}


void MainWindow::on_lk_clicked()
{
    LK *lk = new LK();
    lk -> show();
    this->close();
}


void MainWindow::on_ConstructionEquipment_2_clicked()
{
    ConstructionEquipment *ce = new ConstructionEquipment();
    ce -> show();
    this ->close();
}


void MainWindow::on_commandLinkButton_2_clicked()
{
    StorageEquipment *se = new StorageEquipment();
    se -> show();
    this -> close();
}


void MainWindow::on_commandLinkButton_3_clicked()
{
    LiftingTransporEequipment *le = new LiftingTransporEequipment();
    le -> show();
    this -> close();
}


void MainWindow::on_ConstructionEquipment_clicked()
{
    HoistingEquipment *he = new HoistingEquipment();
    he -> show();
    this -> close();
}

