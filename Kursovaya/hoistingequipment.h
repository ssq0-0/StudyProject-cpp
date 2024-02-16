#ifndef HOISTINGEQUIPMENT_H
#define HOISTINGEQUIPMENT_H

#include <QMainWindow>

namespace Ui {
class HoistingEquipment;
}

class HoistingEquipment : public QMainWindow
{
    Q_OBJECT

public:
    explicit HoistingEquipment(QWidget *parent = nullptr);
    ~HoistingEquipment();

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
    void tablehoistequip();
    void on_pushButton_clicked();
    void onButtonClicked();
    void updateEquipmentFile();
    void on_push_to_hoist_clicked();
    bool isAdmin();

private:
    Ui::HoistingEquipment *ui;

    QString id;
    QString name;
    QString type;
    double price;
    int count;
};

#endif // HOISTINGEQUIPMENT_H
