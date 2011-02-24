#ifndef LORETTE_H
#define LORETTE_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QToolBar>
#include "matrice.h"

namespace Ui {
    class Lorette;
}

class Lorette : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lorette(QWidget *parent = 0);
    ~Lorette();
    void createForm();


private:
    QPushButton *m_button_exec;
    QPushButton *m_button_quit;
    Matrice *mat;
    Ui::Lorette *ui;
    int methode;
    QString name;


private slots:
    void pushButton_clicked();
    void pushButton_clicked_2();
    void actionOuvrir_Matrice_triggered();
    void actionEnregistrer_Sous_triggered();
    void actionEnregistrer_triggered();
    void actionQuitter_triggered();
    void clickm_button_exec();
    void actionNouvelle_Matrice_triggered();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();


};

#endif // LORETTE_H
