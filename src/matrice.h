#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>
#include <QSpinBox>
#include <QTextEdit>
#include <QMessageBox>
class Matrice : public QWidget
{
public:
    explicit Matrice(int taille);
    ~Matrice();

private:
    int taille;
    int **val;
    QSpinBox **sb;

public:
    int getTaille();
    void affichMatrice(QWidget* parent);
};

#endif // MATRICE_H
