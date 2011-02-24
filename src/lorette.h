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
    Matrice *mat;
    Ui::Lorette *ui;
    int methode;
    QString name;
    QPushButton *m_button_exec,*m_button_quit;
    QAction *newAct,*openAct,*saveAct,*saveAsAct,*exitAct,*addAct,*delAct;
    QToolBar *fileToolBar,*toolBar;


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
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
