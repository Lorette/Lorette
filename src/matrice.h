#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>
#include <QSpinBox>
#include <QFile>
#include <QMessageBox>

class Matrice : public QWidget
{
    Q_OBJECT

public:
    explicit Matrice(QWidget *parent,int taille);
    ~Matrice();

private:
    QFile *m_file;
    int taille;
    int **val;
    QSpinBox **m_spin;

public:
    QFile *getm_file();
    void setm_file(QString f);
    void affichMatrice();
    void methode1();
    void methode2();
    void methode3();
    void save();

};

#endif // MATRICE_H
