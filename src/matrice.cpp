#include "matrice.h"


Matrice::Matrice(int taille)
{
    this->taille = taille;
    val = new int* [taille];
    sb = new QSpinBox* [taille];
    for (int i = 0; i < taille; i++)
        val[i] = new int[taille];

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
    char c = 'A';
    QLabel **x = new QLabel* [taille];

    for(int i = 0;i < taille;i++)
    {
        for(int j = 0;j < taille;j++,c++)
        {
            x[i] = new QLabel(parent);
            sb[i] = new QSpinBox(parent);
            sb[i]->setValue(*val[i]);
            sb[i]->setGeometry(QRect(40*j+20, 20*i+10, 30, 20));
            x[i]->setText(QString::fromAscii(&c));
            x[i]->setGeometry(QRect(40*j+52,20*i+10,6,20));
            x[i]->show();
            sb[i]->show();
        }

        c = 'A';
    }
}
