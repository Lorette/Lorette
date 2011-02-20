#include "matrice.h"


Matrice::Matrice(QWidget *parent,int taille) : QWidget(parent)
{
    this->taille = taille;
    this->m_file = NULL;

    val = new int* [taille];
    for (int i = 0; i < taille; i++)
        val[i] = new int[taille];
    for (int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            val[i][j] = 0;

    this->createMatrice();
}

Matrice::Matrice(QWidget *parent,QString f) : QWidget(parent)
{
    QString str;

    this->setm_file(f);

    if (!m_file->open(QFile::ReadOnly))
    {
        QMessageBox::warning(this, "Erreur",
                             "Pov tache");
        return;
    }

    QTextStream in(m_file);
    in >> str;
    m_file->close();

    QStringList m_list = str.split("%");
    QStringList m_list2;

    taille = m_list.count()-1;

    val = new int* [taille];
    for (int i = 0; i < taille; i++)
        val[i] = new int[taille];

    for(int i = 0; i < taille; i++)
    {
        m_list2 = ((QString) m_list.at(i)).split("#");
        for(int j = 0;j<taille;j++)
            val[i][j] = ((QString) m_list2.at(j)).toInt();
    }

    this->createMatrice();
}


void Matrice::createMatrice()
{
    setMinimumSize(42*taille,21*taille);
    m_spin = NULL;
    connect(this,SIGNAL(clicked()),this,SLOT(on_click()));
    this->affichMatrice();
}

Matrice::~Matrice()
{
    for (int i = 0; i < taille; i++)
    {
          delete [] val[i];
    }
    delete [] val;
    if(m_spin != NULL)
    {
        delete m_spin;
        delete m_label_modifying;
        delete m_file;
    }

}


QFile* Matrice::getm_file()
{
    return m_file;
}

void Matrice::affichMatrice()
{
    Label **x = new Label* [taille];

    for(int i = 0;i < taille;i++)
    {
        for(int j = 0;j < taille;j++)
        {
            x[i] = new Label(this,i,j);
            x[i]->setText(QString::number(val[i][j]));
            connect(x[i],SIGNAL(clicked(Label*)),this,SLOT(on_label_click(Label*)));
            x[i]->setGeometry(QRect(40*j+52,20*i+10,40,20));
            x[i]->show();
        }

    }
}

void Matrice::methode1()
{
    QMessageBox::information(this,"Methode 1","C'est la methode 1",QMessageBox::Close);
}

void Matrice::methode2()
{
    QMessageBox::information(this,"Methode 2","C'est la methode 2",QMessageBox::Close);
}

void Matrice::methode3()
{
    QMessageBox::information(this,"Methode 3","C'est la methode 3",QMessageBox::Close);
}

void Matrice::setm_file(QString f)
{
    m_file = new QFile(f);
}

void Matrice::save()
{
    if (!m_file->open(QFile::WriteOnly))
    {
        m_file = NULL;
        return;
    }

    QTextStream out(m_file);
    //out.setVersion(QDataStream::Qt_4_7);

    for(int i=0;i<taille;i++)
    {
        for(int j=0;j<taille;j++)
            out << QString::number(val[i][j])+"#";
        out << "%";
    }

    m_file->close();
}

void Matrice::on_label_click(Label *l)
{
   if(m_spin != NULL)
      delete m_spin;

    m_spin = new QSpinBox(this);
    m_spin->setMaximum(999);
    m_label_modifying = l;
    m_spin->setGeometry(QRect(l->geometry().left()-3,l->geometry().top(),40,20));
    connect(m_spin,SIGNAL(valueChanged(int)),this,SLOT(on_finished_changed(int)));
    m_spin->setValue(l->text().toInt());
    m_spin->show();

}

void Matrice::on_finished_changed(int value)
{
    m_label_modifying->setText(QString::number(value));
    val[m_label_modifying->getm_x()][m_label_modifying->getm_y()] = value;
}

void Matrice::on_click()
{
    if(m_spin != NULL)
       delete m_spin;
    m_spin = NULL;
}
