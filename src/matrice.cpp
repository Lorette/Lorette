#include "matrice.h"


Matrice::Matrice(int taille)
{
    this->taille = taille;
    val = new uint* [taille];
    for (int i = 0; i < taille; i++)
        val[i] = new uint[taille];

    for (int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            val[i][j] = 1;
}

Matrice::~Matrice()
{
    for (int i = 0; i < taille; i++)
          delete [] val[i];
    delete [] val;
}

int Matrice::getTaille()
{
    return this->taille;
}

void Matrice::affichMatrice(QWidget* parent)
{
    QLabel *l = new QLabel(parent);
    QLabel *mat = new QLabel(parent);

    l->setText("Taille de la matrice :" + QString::number(this->taille));
    mat->setGeometry(QRect(80, 40, 241, 15*taille));
    for(int i = 0;i<taille;i++)
    {    for(int j = 0;j<taille;j++)
            mat->setText(mat->text() +QString::number(val[i][j]) + ('A' +j) + " + ");
        mat->setText(mat->text() +"\n");
    }
    l->show();
    mat->show();
}
