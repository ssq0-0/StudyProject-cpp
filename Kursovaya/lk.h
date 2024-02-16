#ifndef LK_H
#define LK_H

#include <QMainWindow>

namespace Ui {
class LK;
}

class LK : public QMainWindow
{
    Q_OBJECT

public:
    explicit LK(QWidget *parent = nullptr);
    ~LK();

private slots:
    void on_back_clicked();
    void fillTableWithData();
    void loadUserData();
private:
    Ui::LK *ui;
};

#endif // LK_H
