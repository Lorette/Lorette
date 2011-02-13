#include "matrice.h"
#include "ui_new_matrice.h"
#include <QIntValidator>
#include <QString>

Matrice::Matrice(QWidget *parent) : QDialog(parent),new_matrice(new Ui::new_Matrice),name("Untitled")
{
    new_matrice->setupUi(this);
    new_matrice->lineEdit_2->setValidator(new QIntValidator(0,100,this));
    this->show();
}

Matrice::~Matrice()
{
    delete new_matrice;
}

void Matrice::on_buttonBox_accepted()
{
    taille = new_matrice->lineEdit->text().toUInt();
}

QString Matrice::getName()
{
    return name;
}
