#ifndef MATRICE_H
#define MATRICE_H

#include <QDialog>

namespace Ui {
    class new_Matrice;
}

class Matrice : public QDialog
{
    Q_OBJECT

public:
    explicit Matrice(QWidget *parent = 0);
    ~Matrice();

private:
    QString name;
    uint taille;
    Ui::new_Matrice *new_matrice;

public:
    QString getName();

private slots:
    void on_buttonBox_accepted();
};

#endif // MATRICE_H
