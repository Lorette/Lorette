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
#include <QVector>
#include <QLayout>
#include <QLayoutItem>
#include <QInputDialog>
#include <QProgressBar>
#include <qmath.h>
#include "resultat.h"
#include "label.h"
#include "settings.h"

class Matrice : public QWidget
{
    Q_OBJECT

public:
    explicit Matrice(QWidget *parent,Settings *settings);
    explicit Matrice(QWidget *parent,QString f,Settings *settings);
    ~Matrice();

private:
    QFile *m_file;
    QVector< QVector<float> > val;
    QSpinBox *m_spin;
    QVector< QVector<Label*> > m_label;
    Resultat *m_result;
    Label *m_label_modifying;
    Settings *set;
    int taille;

public:
    QFile *getm_file();
    void setm_file(QString f);
    void affichMatrice();
    void methode1();
    void methode2();
    void methode3();
    void save();
    void createMatrice();
    void add_line();
    void del_line();
    void genMatrice(bool aleatoire);
    bool verif_matrice();

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
        void progress_value_changed(int);

};

#endif // MATRICE_H
