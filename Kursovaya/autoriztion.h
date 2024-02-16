#ifndef AUTORIZTION_H
#define AUTORIZTION_H

#include <QWidget>

namespace Ui {
class Autoriztion;
}

class Autoriztion : public QWidget
{
    Q_OBJECT

public:
    explicit Autoriztion(QWidget *parent = nullptr);
    ~Autoriztion();

private slots:
    void on_LogIn_clicked();

    void on_registration_clicked();

private:
    Ui::Autoriztion *ui;
};

#endif // AUTORIZTION_H
