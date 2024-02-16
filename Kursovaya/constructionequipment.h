#ifndef CONSTRUCTIONEQUIPMENT_H
#define CONSTRUCTIONEQUIPMENT_H

#include <QMainWindow>

namespace Ui {
class ConstructionEquipment;
}

class ConstructionEquipment : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConstructionEquipment(QWidget *parent = nullptr);
    ~ConstructionEquipment();


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
    void constructequip();
    void onButtonClicked();
    void updateEquipmentFile();
    void on_push_to_contsuct_clicked();
    bool isAdmin();

private:
    Ui::ConstructionEquipment *ui;

    QString id;
    QString name;
    QString type;
    double price;
    int count;
};

#endif // CONSTRUCTIONEQUIPMENT_H
