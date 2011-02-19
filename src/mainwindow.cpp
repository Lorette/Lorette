#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_button_exec = new QPushButton("Executer",ui->buttonBox);
    m_button_quit = new QPushButton("Quitter",ui->buttonBox);
    ui->buttonBox->addButton(m_button_exec,QDialogButtonBox::NoRole);
    ui->buttonBox->addButton(m_button_quit,QDialogButtonBox::NoRole);

    connect(m_button_exec,SIGNAL(clicked()),this,SLOT(on_clickm_button_exec()));
    connect(m_button_quit,SIGNAL(clicked()),this,SLOT(on_actionQuitter_triggered()));

    mat = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(mat != NULL)
        delete mat;

    delete m_button_exec;
    delete m_button_quit;
}

void MainWindow::on_actionNouvelle_Matrice_activated()
{
    mat = new Matrice(ui->scrollArea,3);
    ui->scrollArea->setWidget(mat);
    mat->show();
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_clickm_button_exec()
{
    if(mat == NULL)
    {
        QMessageBox::information(this,"Mais arrete ....","Eh ! Y'a pas de matrice charger",QMessageBox::Close);
        return;
    }


    switch(methode)
    {
        case 1 : mat->methode1();
            break;
        case 2 : mat->methode2();
            break;
        case 3 : mat->methode3();
            break;
    }
}


void MainWindow::on_radioButton_clicked()
{
    methode = 1;
}

void MainWindow::on_radioButton_2_clicked()
{
    methode = 2;
}

void MainWindow::on_radioButton_3_clicked()
{
    methode = 3;
}

void MainWindow::on_actionEnregistrer_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::information(this,"Mais arrete ....","Eh ! Y'a pas de matrice charger",QMessageBox::Close);
        return;
    }

    if(mat->getm_file() == NULL)
        on_actionEnregistrer_Sous_triggered();
    else
        mat->save();

}

void MainWindow::on_actionEnregistrer_Sous_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::information(this,"Mais arrete ....","Eh ! Y'a pas de matrice charger",QMessageBox::Close);
        return;
    }

    mat->setm_file(QFileDialog::getSaveFileName(0,0,0,".lor"));

     mat->save();

}

void MainWindow::on_actionOuvrir_Matrice_triggered()
{
    if(mat != NULL)
        mat->~Matrice();
    mat = NULL;
    mat = new Matrice(ui->scrollArea,QFileDialog::getOpenFileName());
    ui->scrollArea->setWidget(mat);
    mat->show();
}
