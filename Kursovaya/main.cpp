#include "mainwindow.h"
#include "autoriztion.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Autoriztion w;
    w.show();
    return a.exec();
}
