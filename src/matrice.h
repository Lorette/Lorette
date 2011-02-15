#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>
#include <QSpinBox>
#include <QTextEdit>
#include <QMessageBox>
#include <QScrollBar>

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
    QScrollBar *m_barre;

public:
    void affichMatrice();

private slots:
    void on_horizontalScrollBar_valueChanged(int value);
};

#endif // MATRICE_H
