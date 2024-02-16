#ifndef STORAGEEQUIPMENT_H
#define STORAGEEQUIPMENT_H

#include <QMainWindow>

namespace Ui {
class StorageEquipment;
}

class StorageEquipment : public QMainWindow
{
    Q_OBJECT

public:
    explicit StorageEquipment(QWidget *parent = nullptr);
    ~StorageEquipment();

    QString getId() const;
    QString getName() const;
    QString getType() const;
    double getPrice() const;
    int getCount() const;

    void setId(const QString &value);
    void setName(const QString &value);
    void setType(const QString &value);
    void setPrice(double value);
    void setCount(int value);

private slots:
    void on_exit_clicked();
    void fillTableWithData();
    void onButtonClicked();
    void updateEquipmentFile();
    void on_push_to_storage_clicked();
    bool isAdmin();

private:
    Ui::StorageEquipment *ui;

    QString id;
    QString name;
    QString type;
    double price;
    int count;
};

#endif // STORAGEEQUIPMENT_H
