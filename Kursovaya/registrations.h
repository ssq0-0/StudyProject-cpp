#ifndef REGISTRATIONS_H
#define REGISTRATIONS_H

#include <QMainWindow>

namespace Ui {
class registrations;
}

class registrations : public QMainWindow
{
    Q_OBJECT

public:
    explicit registrations(QWidget *parent = nullptr);
    ~registrations();

private slots:
    void on_back_to_auto_clicked();

    void on_push_reg_clicked();

private:
    Ui::registrations *ui;
};

#endif // REGISTRATIONS_H
