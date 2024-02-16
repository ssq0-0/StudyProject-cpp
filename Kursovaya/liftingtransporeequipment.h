#ifndef LIFTINGTRANSPOREEQUIPMENT_H
#define LIFTINGTRANSPOREEQUIPMENT_H

#include <QMainWindow>

namespace Ui {
class LiftingTransporEequipment;
}

class LiftingTransporEequipment : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiftingTransporEequipment(QWidget *parent = nullptr);
    ~LiftingTransporEequipment();

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
    void tableliftingtransport();
    void onButtonClicked();
    void updateEquipmentFile();
    void on_push_to_lifting_clicked();
    bool isAdmin();

private:
    Ui::LiftingTransporEequipment *ui;

    QString id;
    QString name;
    QString type;
    double price;
    int count;
};

#endif // LIFTINGTRANSPOREEQUIPMENT_H
