#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include "matrice.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *m_button_exec;
    QPushButton *m_button_quit;
    Matrice *mat;
    Ui::MainWindow *ui;
    int methode;

private slots:
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

#endif // MAINWINDOW_H
