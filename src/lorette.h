#ifndef LORETTE_H
#define LORETTE_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
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

private:
    QPushButton *m_button_exec;
    QPushButton *m_button_quit;
    Matrice *mat;
    Ui::Lorette *ui;
    int methode;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_actionOuvrir_Matrice_triggered();
    void on_actionEnregistrer_Sous_triggered();
    void on_actionEnregistrer_triggered();
    void on_radioButton_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_2_clicked();
    void on_actionQuitter_triggered();
    void on_actionNouvelle_Matrice_activated();
    void on_clickm_button_exec();
};

#endif // LORETTE_H
