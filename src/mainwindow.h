#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QHBoxLayout>

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
    Matrice *mat;
    Ui::MainWindow *ui;

private slots:
    void on_actionNouvelle_Matrice_activated();
};

#endif // MAINWINDOW_H
