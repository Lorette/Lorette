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

void Lorette::actionEnregistrer_triggered()
{
    if(mat == NULL)
    {
        QMessageBox::critical(this,"Erreur","Vous devez dabord charger une matrice",QMessageBox::Close);
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
    {
        QMessageBox::critical(this,"Erreur","Vous devez dabord charger une matrice",QMessageBox::Close);
        return;
    }
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
        connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
        ui->scrollArea->setWidget(mat);
        mat->show();
        this->setWindowTitle(name + " - " +file);
    }
}



void Lorette::actionNouvelle_Matrice_triggered()
{
    mat = new Matrice(ui->scrollArea);
    connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
    ui->scrollArea->setWidget(mat);
    this->setWindowTitle(name +" - Nouvelle Matrice");
    mat->show();
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

    genAct = new QAction(QIcon(":/images/new.png"), tr("Générer"), this);
    connect(genAct, SIGNAL(triggered()), this, SLOT(actionGen_Matrice()));

    addAct = new QAction(QIcon(":/images/add.png"), tr("Ajouter"), this);
    connect(addAct, SIGNAL(triggered()), this, SLOT(pushButton_clicked()));

    delAct = new QAction(QIcon(":/images/del.png"), tr("Supprimer"), this);
    connect(delAct, SIGNAL(triggered()), this, SLOT(pushButton_2_clicked()));

    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addAction(exitAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(genAct);
    fileToolBar->addSeparator();
    fileToolBar->addWidget(m_progress);
    toolBar->addAction(addAct);
    toolBar->addAction(delAct);
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
}

void Lorette::pushButton_2_clicked()
{
    if(mat != NULL)
        mat->del_line();
}

void Lorette::actionGen_Matrice()
{
    mat = new Matrice(ui->scrollArea);
    connect(mat,SIGNAL(progress_value_changed(int)),this,SLOT(progress_value_changed(int)));
    ui->scrollArea->setWidget(mat);
    setWindowTitle(name +" - Matrice Générée");
    mat->genMatrice();
    mat->show();
}

void Lorette::progress_value_changed(int value)
{
    m_progress->setValue(value);
}

void Lorette::delete_matrice()
{
    if(mat != NULL)
        delete mat;

    mat = NULL;

    this->setWindowTitle(name);
    ui->scrollArea->setWidget(new QWidget());
}
