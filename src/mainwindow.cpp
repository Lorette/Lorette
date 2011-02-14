#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mat;
}

void MainWindow::on_actionNouvelle_Matrice_activated()
{
    mat = new Matrice(QInputDialog::getInteger(this, "Nouvelle Matrice", "Entrez la taille de votre matrice",1,1));
    mat->affichMatrice(ui->centralWidget);
    QMenu *fileMenu = ui->menuBar->addMenu("Matrice");
}

