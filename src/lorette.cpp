#include "lorette.h"
#include "ui_lorette.h"


Lorette::Lorette(QWidget *parent) : QMainWindow(parent),ui(new Ui::Lorette)
{
    ui->setupUi(this);
    name = this->windowTitle();
    m_button_exec = new QPushButton("Executer",ui->buttonBox);
    m_button_quit = new QPushButton("Quitter",ui->buttonBox);
    ui->buttonBox->addButton(m_button_exec,QDialogButtonBox::NoRole);
    ui->buttonBox->addButton(m_button_quit,QDialogButtonBox::NoRole);

    connect(m_button_exec,SIGNAL(clicked()),this,SLOT(on_clickm_button_exec()));
    connect(m_button_quit,SIGNAL(clicked()),this,SLOT(on_actionQuitter_triggered()));

    mat = NULL;
    methode = 1;
}

Lorette::~Lorette()
{
    delete ui;
    if(mat != NULL)
        delete mat;

    delete m_button_exec;
    delete m_button_quit;
}

void Lorette::on_actionNouvelle_Matrice_activated()
{
    mat = new Matrice(ui->scrollArea);
    ui->scrollArea->setWidget(mat);
    this->setWindowTitle(name +" - Nouvelle Matrice");
    mat->show();
}

void Lorette::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void Lorette::on_clickm_button_exec()
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


void Lorette::on_radioButton_clicked()
{
    methode = 1;
}

void Lorette::on_radioButton_2_clicked()
{
    methode = 2;
}

void Lorette::on_radioButton_3_clicked()
{
    methode = 3;
}

void Lorette::on_actionEnregistrer_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::information(this,"Mais arrete ....","Batard ya rien a enregistrer",QMessageBox::Close);
        return;
    }

    if(mat->getm_file() == NULL)
        on_actionEnregistrer_Sous_triggered();
    else
        mat->save();

}

void Lorette::on_actionEnregistrer_Sous_triggered()
{
    if(mat == NULL)
        return;

    QString str = QFileDialog::getSaveFileName(0,0,0,"Lorette Files (*.lor)");
    if(str != NULL)
    {
        mat->setm_file(str);
        this->setWindowTitle(name +" - " +str);
        mat->save();
    }

}

void Lorette::on_actionOuvrir_Matrice_triggered()
{

    QString file = QFileDialog::getOpenFileName();
    if(file != "")
    {
        if(mat != NULL)
            mat->~Matrice();
        mat = new Matrice(ui->scrollArea,file);
        ui->scrollArea->setWidget(mat);
        mat->show();
        this->setWindowTitle(name + " - " +file);
    }
}

void Lorette::on_pushButton_clicked()
{
    if(mat == NULL)
        on_actionNouvelle_Matrice_activated();

    mat->modify_taille(1);
}

void Lorette::on_pushButton_2_clicked()
{
    if(mat != NULL)
        mat->modify_taille(-1);
}

