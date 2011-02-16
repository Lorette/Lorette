#include "matrice.h"


Matrice::Matrice(QWidget *parent,int taille) : QWidget(parent)
{
    this->taille = taille;
    setMinimumSize(42*taille,21*taille);
    val = new int* [taille];
    for (int i = 0; i < taille; i++)
        val[i] = new int[taille];
    for (int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            val[i][j] = 1;


    m_spin = new QSpinBox* [taille];

    this->affichMatrice();
}

Matrice::~Matrice()
{
    for (int i = 0; i < taille; i++)
    {
          delete [] val[i];
          delete m_spin[i];
    }
    delete [] val;
    delete [] m_spin;
}

void Matrice::affichMatrice()
{
    char c = 'A';
    QLabel **x = new QLabel* [taille];

    for(int i = 0;i < taille;i++)
    {
        for(int j = 0;j < taille;j++,c++)
        {
            x[i] = new QLabel(this);
            m_spin[i] = new QSpinBox(this);
            m_spin[i]->setValue(*val[i]);
            m_spin[i]->setGeometry(QRect(40*j+20, 20*i+10, 30, 20));
            x[i]->setText(QString::fromAscii(&c));
            x[i]->setGeometry(QRect(40*j+52,20*i+10,6,20));
            x[i]->show();
            m_spin[i]->show();
        }

        c = 'A';
    }
}
