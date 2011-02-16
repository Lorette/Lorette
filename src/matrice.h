#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>
#include <QSpinBox>

class Matrice : public QWidget
{
    Q_OBJECT

public:
    explicit Matrice(QWidget *parent,int taille);
    ~Matrice();

private:
    int taille;
    int **val;
    QSpinBox **m_spin;

public:
    void affichMatrice();

};

#endif // MATRICE_H
