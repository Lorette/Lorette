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

#include "matrice.h"


Matrice::Matrice(QWidget *parent,Settings *settings) : QWidget(parent), set(settings)
{
    this->taille = 1;
    this->m_file = NULL;
    this->m_result = NULL;
    val.resize(taille);
    val[0].resize(taille+1);

    this->createMatrice();
}

Matrice::Matrice(QWidget *parent,QString f,Settings *settings) : QWidget(parent),set(settings)
{
    QString str;

    this->setm_file(f);

    if (!m_file->open(QFile::ReadOnly))
    {
        return;
    }

    QTextStream in(m_file);
    in >> str;
    m_file->close();

    QStringList m_list = str.split("%");
    QStringList m_list2;

    taille = m_list.count()-1;

    val.resize(taille);
    for (int i = 0; i < taille; i++)
        val[i].resize(taille+1);


    for(int i = 0; i < taille; i++)
    {
        m_list2 = ((QString) m_list.at(i)).split("#");
        for(int j = 0;j<taille+1;j++)
            val[i][j] = ((QString) m_list2.at(j)).toFloat();
    }

    this->createMatrice();
}


void Matrice::createMatrice()
{
    m_label.resize(taille);
    for(int i = 0;i < taille;i++)
        m_label[i].resize(taille+1);
    m_result = NULL;
    setMinimumSize(42*taille,21*taille);
    m_spin = NULL;
    connect(this,SIGNAL(clicked()),this,SLOT(on_click()));
    this->affichMatrice();
}

Matrice::~Matrice()
{
    if(m_spin != NULL) delete m_spin;
    if(m_file != NULL) delete m_file;
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille+1; j++)
                delete m_label[i][j];
    }

}


QFile* Matrice::getm_file()
{
    return m_file;
}

void Matrice::affichMatrice()
{
    for(int i = 0;i < taille;i++)
    {
        for(int j = 0;j < taille+1;j++)
        {
            m_label[i][j] = new Label(this,i,j);
            m_label[i][j]->setText(QString::number(val[i][j]));
            connect(m_label[i][j],SIGNAL(clicked(Label*)),this,SLOT(on_label_click(Label*)));
            m_label[i][j]->setGeometry(QRect(40*j+52,20*i+10,40,20));
            m_label[i][j]->show();
        }
        emit(progress_value_changed((int)(((float)i/(float)taille)*100)));
    }

        emit(progress_value_changed(0));
}

void Matrice::methode1()
{
    QVector< QVector<float> > a = this->val;
    QVector<float> result(taille);
    int pivot,repere;

    m_result = new Resultat();
    m_result->setWindowTitle("Résultat : Pivot de Gauss");

    for(int etape = 0;etape<taille-1;etape++)
    {
        pivot = a[etape][etape];
        for(int i = etape+1;i < taille;i++)
        {
            repere = a[i][etape];
            for(int j = etape; j < taille+1;j++)
                a[i][j] = pivot*a[i][j] - repere*a[etape][j];

        }
        emit(progress_value_changed((int)(((float)etape/(float)taille)*100)));
        if(set->getSteps())
            m_result->ResulatMethode1(a,"Etape " +QString::number(etape+1));

    }

    for(int i = taille-1;i >= 0;i--)
    {
        repere = a[i][i];
        for(int j = 0;j< taille+1;j++)
            a[i][j]/=repere;

        result[i] = a[i][taille];
        for(int j=0;j<taille;j++)
            if(j!=i)
                result[i] -= a[i][j]*result[j];

        emit(progress_value_changed((int)(((float)i/(float)taille)*100)));
    }

    m_result->ResulatMethode2(result,"Final");

    m_result->show();

    emit(progress_value_changed(0));
}


void Matrice::methode2()
{
    QVector< QVector<float> > a = this->val;
    float repere,_max = 1;
    QVector<float> inco(taille);
    QVector<float> new_inco(taille);
    bool force;

    if(verif_matrice())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, "Information",tr("La matrice ne satisfait les conditions pour une méthode de Jacobi.\n"
                        "Elle n'est pas à diagionale strictement dominante.\n""Voulez vous essayer de la transformer ?"),
                                   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (ret == QMessageBox::Yes)
            force = true;
        else if (ret == QMessageBox::No)
                new_inco = askStartValue();
        else
            return;
    }

    if(force)
    {
        bool error = false;
        QList<float> corres;

        for(int i = 0;i < taille && !error; i++)
        {
            int j,value = 0;
            for(j = 0;j< taille;j++)
            {
                value = abs(a[i][j])*2;
                for(int k = 0;k < taille;k++)
                    value -= fabs(a[i][k]);
                if(value >=0 && !corres.contains(j))
                    break;
            }

            if(j == taille)
                error = true;
            else if(value >= 0)
            {
                if(corres.contains(j))
                    error = true;
                else
                    corres << j;
            }
        }

        if(error)
        {
            QMessageBox::StandardButton ret;
            ret = QMessageBox::warning(this,"Information",tr("La matrice ne peut pas être transformé pour satisfaire la condition.\n""Il vous faut entrer le vecteur de départ.\n"),QMessageBox::Ok | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;
            else
            {
                inco = askStartValue();
            }
        }
        else
        {
            for(int i=0; i < corres.count();i++)
                for(int j = 0; j < taille +1;j++)
                    a[corres.at(i)][j] = val[i][j];
        }
    }

    m_result = new Resultat();
    m_result->setWindowTitle("Résultat : Jacobi");

    for(int i = 0; i < taille;i++)
    {
        repere = a[i][i];
        for(int j = 0;j < taille+1;j++)
            a[i][j] = a[i][j]/repere;
    }


    for(int etape = 0;_max > 0.005 && etape < 100;etape++)
    {
        _max = 0;
        for(int i = 0;i<taille;i++)
        {
            new_inco[i] = a[i][taille];
            for(int j = 0;j<taille;j++)
                new_inco[i] = new_inco[i] - a[i][j]*inco[j];
            new_inco[i] += inco[i];
        }
        for(int i = 0; i < taille;i++)
            _max = (_max > fabs((new_inco[i]-inco[i])/new_inco[i])) ? _max : fabs((new_inco[i]-inco[i])/new_inco[i]);

        inco = new_inco;
        if(set->getSteps())
            m_result->ResulatMethode2(inco,"Etape "+QString::number(etape+1));

    }  
	
    m_result->ResulatMethode2(inco,"Final");
    m_result->show();
}

void Matrice::methode3()
{
    QVector< QVector<float> > a = this->val;
    float repere;
    float _max = 1;
    QVector<float> inco(taille);
    QVector<float> new_inco(taille);
    bool force = false;

    if(verif_matrice())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, "Information",tr("La matrice ne satisfait les conditions pour une méthode de Gauss-Seidel.\n"
                        "Elle n'est pas à diagionale strictement dominante.\n""Voulez vous essayer de la transformer ?"),
                                   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (ret == QMessageBox::Yes)
            force = true;
        else if (ret == QMessageBox::No)
                new_inco = askStartValue();
        else
            return;
    }

    if(force)
    {
        bool error = false;
        QList<float> corres;

        for(int i = 0;i < taille && !error; i++)
        {
            int j,value = 0;
            for(j = 0;j< taille;j++)
            {
                value = abs(a[i][j])*2;
                for(int k = 0;k < taille;k++)
                    value -= fabs(a[i][k]);
                if(value >=0 && !corres.contains(j))
                    break;
            }

            if(j == taille)
                error = true;
            else if(value >= 0)
            {
                if(corres.contains(j))
                    error = true;
                else
                    corres << j;
            }
        }

        if(error)
        {
            QMessageBox::StandardButton ret;
            ret = QMessageBox::warning(this,"Information",tr("La matrice ne peut pas être transformé pour satisfaire la condition.\n""Il vous faut entrer le vecteur de départ.\n"),QMessageBox::Ok | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;

            new_inco = askStartValue();
        }
        else
        {
            for(int i=0; i < corres.count();i++)
                for(int j = 0; j < taille +1;j++)
                    a[corres.at(i)][j] = val[i][j];
        }
    }

    m_result = new Resultat();
    m_result->setWindowTitle("Résultat : Gauss-Seidel");

    for(int i = 0; i < taille;i++)
    {
        repere = a[i][i];
        for(int j = 0;j < taille+1;j++)
            a[i][j] = a[i][j]/repere;
    }

    for(int etape = 0;/*_max > 0.005 && */etape < 8;etape++)
    {
        _max = 0;
        for(int i = 0;i<taille;i++)
        {
            new_inco[i] = a[i][taille];
            for(int j = 0;j<taille;j++)
                if(j!=i)
                    new_inco[i] = new_inco[i] - a[i][j]*new_inco[j];
        }
        for(int i = 0; i < taille;i++)
            _max = (_max > fabs((new_inco[i]-inco[i])/new_inco[i])) ? _max : fabs((new_inco[i]-inco[i])/new_inco[i]);

        inco = new_inco;
        if(set->getSteps())
            m_result->ResulatMethode2(new_inco,"Etape "+QString::number(etape+1));

    }

    m_result->ResulatMethode2(new_inco,"Final");
    m_result->show();
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

    for(int i=0;i<taille;i++)
    {
        for(int j=0;j<taille+1;j++)
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
    m_spin->setMinimum(-999);
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

void Matrice::add_line()
{
    taille++;
    m_label.resize(taille);
    val.resize(taille);
    for(int i = 0;i < taille;i++)
    {
        val[i].resize(taille+1);
        m_label[i].resize(taille+1);
    }

    for(int i = 0 ; i < taille;i++)
    {
        m_label[taille-1][i] = new Label(this,taille-1,i);
        m_label[i][taille] = new Label(this,i,taille);
        m_label[taille-1][i]->setText(QString::number(val[taille-1][i]));
        m_label[i][taille]->setText(QString::number(val[i][taille]));
        connect(m_label[taille-1][i],SIGNAL(clicked(Label*)),this,SLOT(on_label_click(Label*)));
        connect(m_label[i][taille],SIGNAL(clicked(Label*)),this,SLOT(on_label_click(Label*)));
        m_label[taille-1][i]->setGeometry(QRect(40*i+52,20*(taille-1)+10,40,20));
        m_label[i][taille]->setGeometry(QRect(40*taille+52,20*i+10,40,20));
        m_label[taille-1][i]->show();
        m_label[i][taille]->show();

        emit(progress_value_changed((int)(((float)i/(float)taille)*100)));

    }

    emit(progress_value_changed(0));
    setMinimumSize(42*taille,21*taille);
}

void Matrice::del_line()
{
    if(taille == 1)
        return;


    taille--;

    for(int i = 0 ; i < taille+1;i++)
    {
        delete m_label[taille][i];
        delete m_label[i][taille+1];
    }
    setMinimumSize(42*taille,21*taille);

    m_label.resize(taille);
    val.resize(taille);
    for(int i = 0;i < taille;i++)
    {
        val[i].resize(taille+1);
        m_label[i].resize(taille+1);
        emit(progress_value_changed((int)(((float)i/(float)taille)*100)));
    }

    emit(progress_value_changed(0));
}

void Matrice::genMatrice(bool aleatoire)
{

    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille+1; j++)
            delete m_label[i][j];
    }


    taille = QInputDialog::getInt(0,"Taille","Entrez la taille de votre matrice",1,1,1000000);

    val.resize(taille);
    m_label.resize(taille);
    for(int i = 0;i<taille;i++)
    {
        val[i].resize(taille+1);
        m_label[i].resize(taille+1);
    }
    for(int i=0;i<taille;i++)
    {
        for(int j=0;j<taille+1;j++)
        {
            if(aleatoire)
                val[i][j] = qrand()%20;
            else
                val[i][j] = 0;
        }
    }
    setMinimumSize(42*taille,21*taille);
    this->affichMatrice();
}

bool Matrice::verif_matrice()
{
    int value;
    bool error = false;

    for(int i = 0; i < taille && !error; i++)
    {
        value = fabs(val[i][i])*2;
        for(int j = 0;j < taille; j++)
            value -= fabs(val[i][j]);
        if(value < 0)
            error = true;
        else
            value = 0;
    }

    return error;
}

QVector<float> Matrice::askStartValue()
{
   QList<float> a;

   for(int i = 0;i< taille;i++)
       a << QInputDialog::getInt(this,tr("Vecteur de départ"),tr("Entrez la valeur du vecteur de départ"));
   return a.toVector();
}
