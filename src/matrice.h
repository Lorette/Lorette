#ifndef MATRICE_H
#define MATRICE_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QString>
#include <QSpinBox>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "label.h"

class Matrice : public QWidget
{
    Q_OBJECT

public:
    explicit Matrice(QWidget *parent,int taille);
    explicit Matrice(QWidget *parent,QString f);
    ~Matrice();

private:
    QFile *m_file;
    int taille;
    int **val;
    QSpinBox *m_spin;
    Label *m_label_modifying;

public:
    QFile *getm_file();
    void setm_file(QString f);
    void affichMatrice();
    void methode1();
    void methode2();
    void methode3();
    void save();
    void createMatrice();

private slots:
    void on_click();
    void on_label_click(Label *l);
    void on_finished_changed(int value);
    void mouseReleaseEvent ( QMouseEvent * event )
    {
        emit(clicked());
         event->accept();
    }


    signals:
        void clicked();

};

#endif // MATRICE_H
