#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>

class Matrice
{

public:
    explicit Matrice(int taille);
    ~Matrice();

private:
    int taille;
    uint **val;

public:
    int getTaille();
    void affichMatrice(QWidget* parent);
};

#endif // MATRICE_H
