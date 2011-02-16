#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mat = NULL;
    QPushButton *butt = ui->buttonBox->button(QDialogButtonBox::Cancel);
    butt->setText("Fils de pute");
    }

MainWindow::~MainWindow()
{
    delete ui;
    if(mat != NULL)
        delete mat;
}

void MainWindow::on_actionNouvelle_Matrice_activated()
{
    mat = new Matrice(ui->scrollArea,10);
    ui->scrollArea->setWidget(mat);
    mat->show();
}
