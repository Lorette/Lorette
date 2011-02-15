#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mat = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(mat != NULL)
        delete mat;
}

void MainWindow::on_actionNouvelle_Matrice_activated()
{
    mat = new Matrice(3);
    mat->affichMatrice(ui->centralWidget);
}
