#ifndef LORETTE_H
#define LORETTE_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QToolBar>
#include <QProgressBar>
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

protected:
    void closeEvent(QCloseEvent *event);

private:
    Matrice *mat;
    Ui::Lorette *ui;
    int methode;
    QString name;
    QPushButton *m_button_exec,*m_button_quit;
    QAction *newAct,*openAct,*saveAct,*saveAsAct,*exitAct,*addAct,*delAct,*genAAct,*genAct;
    QToolBar *fileToolBar,*toolBar;
    QProgressBar *m_progress;
    bool matrice_modified;
    bool mayBeSaved();


private slots:
    void actionOuvrir_Matrice_triggered();
    bool actionEnregistrer_Sous_triggered();
    bool actionEnregistrer_triggered();
    void clickm_button_exec();
    void actionNouvelle_Matrice_triggered();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void pushButton_2_clicked();
    void pushButton_clicked();
    void actionGen_Matrice();
    void actionGen_Matrice_aleatoire();
    void progress_value_changed(int value);
    void delete_matrice();
};

#endif // LORETTE_H
