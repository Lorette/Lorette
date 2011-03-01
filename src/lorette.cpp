/*
Lorette
Copyright (C) 2011  Lorette Inc

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "lorette.h"
#include "ui_lorette.h"
#include "ui_settings.h"


Lorette::Lorette(QWidget *parent) : QMainWindow(parent),ui(new Ui::Lorette),set(new Settings(this))
{
    ui->setupUi(this);
    name = this->windowTitle();
    createForm();
    m_button_exec = new QPushButton("Executer",ui->buttonBox);
    m_button_quit = new QPushButton("Quitter",ui->buttonBox);
    ui->buttonBox->addButton(m_button_exec,QDialogButtonBox::NoRole);
    ui->buttonBox->addButton(m_button_quit,QDialogButtonBox::NoRole);

    connect(m_button_exec,SIGNAL(clicked()),this,SLOT(clickm_button_exec()));
    connect(m_button_quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(set,SIGNAL(closeW()),this,SLOT(closeSettings()));
    mat = NULL;
    methode = 1;
    matrice_modified = false;
}

Lorette::~Lorette()
{
    delete ui;
    if(mat != NULL)
        delete mat;

    delete m_button_exec;
    delete m_button_quit;
    delete newAct;
    delete openAct;
    delete saveAct;
    delete saveAsAct;
    delete exitAct;
    delete addAct;
    delete delAct;
    delete fileToolBar;
    delete toolBar;
    delete set;
    delete aboutAct;
}


void Lorette::clickm_button_exec()
{
    if(mat == NULL)
    {
        QMessageBox::critical(this,"Erreur","Vous devez dabord charger une matrice",QMessageBox::Close);
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

bool Lorette::actionEnregistrer_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::critical(this,"Erreur","Vous devez dabord charger une matrice",QMessageBox::Close);
        return false;
    }

    if(mat->getm_file() == NULL)
        return actionEnregistrer_Sous_triggered();
    else
        mat->save();
    return true;
}

bool Lorette::actionEnregistrer_Sous_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::critical(this,"Erreur","Vous devez dabord charger une matrice",QMessageBox::Close);
        return false;
    }
    QString str = QFileDialog::getSaveFileName(0,0,0,"Lorette Files (*.lor)");
    if(str != NULL)
    {
        mat->setm_file(str);
        this->setWindowTitle(name +" - " +str);
        mat->save();
        return true;
    }
    return false;

}

void Lorette::actionOuvrir_Matrice_triggered()
{
    if(matrice_modified)
        if(!mayBeSaved())
            return;
    QString file = QFileDialog::getOpenFileName();


    if(file != "")
    {
        if(mat != NULL)
            delete mat;

        mat = new Matrice(ui->scrollArea,file,set);
        connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
        ui->scrollArea->setWidget(mat);
        mat->show();
        this->setWindowTitle(name + " - " +file);
    }
}



void Lorette::actionNouvelle_Matrice_triggered()
{
    if(matrice_modified)
        if(!mayBeSaved())
            return;

    if(mat != NULL)
        delete mat;

    mat = new Matrice(ui->scrollArea,set);
    connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
    ui->scrollArea->setWidget(mat);
    this->setWindowTitle(name +" - Nouvelle Matrice");
    mat->show();
    matrice_modified = true;
}


void Lorette::createForm()
{
    m_progress = new QProgressBar(this);
    toolBar = new QToolBar(tr("Outils"),this);
    toolBar->setMovable(false);
    fileToolBar = addToolBar(tr("File"));
    this->addToolBar(Qt::LeftToolBarArea,toolBar);
    fileToolBar->setMovable(false);



    newAct = new QAction(QIcon(":/images/new.png"), tr("Nouveau"), this);
    newAct->setShortcuts(QKeySequence::New);
    connect(newAct, SIGNAL(triggered()), this, SLOT(actionNouvelle_Matrice_triggered()));

    openAct = new QAction(QIcon(":/images/open.png"), tr("Ouvrir"), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(actionOuvrir_Matrice_triggered()));

    saveAct = new QAction(QIcon(":/images/save.png"), tr("Sauvegarder"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(actionEnregistrer_triggered()));

    saveAsAct = new QAction(QIcon(":/images/save-as.png"), tr("Sauvegarder Sous ..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(actionEnregistrer_Sous_triggered()));

    exitAct = new QAction(QIcon(":/images/exit.png"),tr("Fermer"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(delete_matrice()));

    genAct = new QAction(QIcon(":/images/gen.png"), tr("Générer"), this);
    connect(genAct, SIGNAL(triggered()), this, SLOT(actionGen_Matrice()));

    genAAct = new QAction(QIcon(":/images/gen_ale.png"), tr("Générer Aléatoirement"), this);
    connect(genAAct, SIGNAL(triggered()), this, SLOT(actionGen_Matrice_aleatoire()));

    addAct = new QAction(QIcon(":/images/add.png"), tr("Ajouter"), this);
    connect(addAct, SIGNAL(triggered()), this, SLOT(pushButton_clicked()));

    delAct = new QAction(QIcon(":/images/del.png"), tr("Supprimer"), this);
    connect(delAct, SIGNAL(triggered()), this, SLOT(pushButton_2_clicked()));

    setAct = new QAction(QIcon(":/images/options.png"), tr("Options"), this);
    connect(setAct, SIGNAL(triggered()), this, SLOT(actionSettings()));

    aboutAct = new QAction(QIcon(":/images/Lorette.png"), tr("A Propos"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(actionAbout()));

    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addAction(exitAct);
    fileToolBar->addSeparator();
    fileToolBar->addWidget(m_progress);
    fileToolBar->addSeparator();
    fileToolBar->addAction(setAct);
    fileToolBar->addAction(aboutAct);
    toolBar->addAction(addAct);
    toolBar->addAction(delAct);
    toolBar->addSeparator();
    toolBar->addAction(genAct);
    toolBar->addAction(genAAct);
    m_progress->show();
}

void Lorette::on_radioButton_3_clicked()
{
    methode = 3;
}

void Lorette::on_radioButton_2_clicked()
{
    methode = 2;
}

void Lorette::on_radioButton_clicked()
{
       methode = 1;
}

void Lorette::pushButton_clicked()
{
    if(mat == NULL)
        actionNouvelle_Matrice_triggered();

    mat->add_line();
    matrice_modified = true;
}

void Lorette::pushButton_2_clicked()
{
    if(mat != NULL)
        mat->del_line();
    matrice_modified = true;
}

void Lorette::actionGen_Matrice_aleatoire()
{
    if(matrice_modified)
        if(!mayBeSaved())
            return;

    if(mat != NULL)
        delete mat;

    mat = new Matrice(ui->scrollArea,set);
    connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
    ui->scrollArea->setWidget(mat);
    setWindowTitle(name +" - Matrice Générée");
    mat->genMatrice(true);
    mat->show();

    matrice_modified = true;
}

void Lorette::actionGen_Matrice()
{
    if(matrice_modified)
        if(!mayBeSaved())
            return;

    if(mat != NULL)
        delete mat;

    mat = new Matrice(ui->scrollArea,set);
    connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
    ui->scrollArea->setWidget(mat);
    setWindowTitle(name +" - Nouvelle Matrice");
    mat->genMatrice(false);
    mat->show();

    matrice_modified = true;
}

void Lorette::progress_value_changed(int value)
{
    m_progress->setValue(value);
}

void Lorette::delete_matrice()
{
    if(matrice_modified)
        if(!mayBeSaved())
            return;

    if(mat != NULL)
        delete mat;

    mat = NULL;

    this->setWindowTitle(name);
    ui->scrollArea->setWidget(new QWidget());
}

void Lorette::closeEvent(QCloseEvent *event)
{
    if(matrice_modified)
        if(!mayBeSaved())
            event->ignore();
}

bool Lorette::mayBeSaved()
{
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this,"Information",tr("La matrice a été modifiée.\n""Voulez-vous sauvegarder les modifications ?"),QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if(ret == QMessageBox::Save)
    {    if(!actionEnregistrer_triggered())
            return false;
         else
             matrice_modified = false;
    }
    else if(ret == QMessageBox::Cancel)
        return false;
    else
        matrice_modified = false;

    return true;
}


void Lorette::actionSettings()
{
    this->setDisabled(true);
    set->setEnabled(true);
    set->show();
}

void Lorette::closeSettings()
{
    this->setEnabled(true);
}

void Lorette::actionAbout()
{
    QMessageBox::information(this,"A Propos","A Propos",QMessageBox::Close);
}
