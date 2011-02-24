#include "lorette.h"
#include "ui_lorette.h"


Lorette::Lorette(QWidget *parent) : QMainWindow(parent),ui(new Ui::Lorette)
{
    ui->setupUi(this);
    name = this->windowTitle();
    createForm();
    m_button_exec = new QPushButton("Executer",ui->buttonBox);
    m_button_quit = new QPushButton("Quitter",ui->buttonBox);
    ui->buttonBox->addButton(m_button_exec,QDialogButtonBox::NoRole);
    ui->buttonBox->addButton(m_button_quit,QDialogButtonBox::NoRole);

    connect(m_button_exec,SIGNAL(clicked()),this,SLOT(clickm_button_exec()));
    connect(m_button_quit,SIGNAL(clicked()),this,SLOT(actionQuitter_triggered()));

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
    delete newAct;
    delete openAct;
    delete saveAct;
    delete saveAsAct;
    delete exitAct;
    delete addAct;
    delete delAct;
    delete fileToolBar;
    delete toolBar;
}


void Lorette::actionQuitter_triggered()
{
    QApplication::quit();
}

void Lorette::clickm_button_exec()
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

void Lorette::actionEnregistrer_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::information(this,"Mais arrete ....","Batard ya rien a enregistrer",QMessageBox::Close);
        return;
    }

    if(mat->getm_file() == NULL)
        actionEnregistrer_Sous_triggered();
    else
        mat->save();

}

void Lorette::actionEnregistrer_Sous_triggered()
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

void Lorette::actionOuvrir_Matrice_triggered()
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



void Lorette::actionNouvelle_Matrice_triggered()
{
    mat = new Matrice(ui->scrollArea);
    ui->scrollArea->setWidget(mat);
    this->setWindowTitle(name +" - Nouvelle Matrice");
    mat->show();
}


void Lorette::createForm()
{
    toolBar = new QToolBar(tr("Outils"),this);
    fileToolBar = addToolBar(tr("File"));
    this->addToolBar(Qt::LeftToolBarArea,toolBar);




    newAct = new QAction(QIcon(":/images/new.png"), tr("Nouveau"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Creer une nouvelle matrice"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(actionNouvelle_Matrice_triggered()));

    openAct = new QAction(QIcon(":/images/open.png"), tr("Ouvrir"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Ouvrir un fichier .lor"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(actionOuvrir_Matrice_triggered()));

    saveAct = new QAction(QIcon(":/images/save.png"), tr("Sauvegarder"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Sauvegarder la matrice"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(actionEnregistrer_triggered()));

    saveAsAct = new QAction(QIcon(":/images/save-as.png"), tr("Sauvegarder Sous ..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Sauvegarder la matrice sous ..."));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(actionEnregistrer_Sous_triggered()));

    exitAct = new QAction(QIcon(":/images/exit.png"),tr("Quitter"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Quitter Lorette"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(actionQuitter_triggered()));

    addAct = new QAction(QIcon(":/images/add.png"), tr("Ajouter"), this);
    addAct->setStatusTip(tr("Ajouter une ligne"));
    connect(addAct, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));

    delAct = new QAction(QIcon(":/images/del.png"), tr("Supprimer"), this);
    delAct->setStatusTip(tr("Supprimer une ligne"));
    connect(delAct, SIGNAL(triggered()), this, SLOT(on_pushButton_2_clicked()));

    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addAction(exitAct);

    toolBar->addAction(addAct);
    toolBar->addAction(delAct);
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

void Lorette::on_pushButton_clicked()
{
    if(mat == NULL)
        actionNouvelle_Matrice_triggered();

    mat->modify_taille(1);
}

void Lorette::on_pushButton_2_clicked()
{
    if(mat != NULL)
        mat->modify_taille(-1);
}
