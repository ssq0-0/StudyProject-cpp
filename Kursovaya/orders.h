#ifndef ORDERS_H
#define ORDERS_H

#include <QMainWindow>

namespace Ui {
class orders;
}

class orders : public QMainWindow
{
    Q_OBJECT

public:
    explicit orders(QWidget *parent = nullptr);
    ~orders();
    void writeToFile(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type);
    void writeToTableLifting(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type);
    void writeToTableConstruct(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type);
    void writeToTableHoist(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type);
    void writeToTableStorage(const QString &id, const QString &name, const QString &price, const QString &count, const QString &type);

private:
    Ui::orders *ui;
};

#endif // ORDERS_H
