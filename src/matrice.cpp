#include "matrice.h"


Matrice::Matrice(QWidget *parent) : QWidget(parent)
{
    this->taille = 1;
    this->m_file = NULL;

    val.resize(taille);
    val[0].resize(taille+1);

    this->createMatrice();
}

Matrice::Matrice(QWidget *parent,QString f) : QWidget(parent)
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
            val[i][j] = ((QString) m_list2.at(j)).toInt();
    }

    this->createMatrice();
}


void Matrice::createMatrice()
{
    m_result = NULL;
    setMinimumSize(42*taille,21*taille);
    m_spin = NULL;
    connect(this,SIGNAL(clicked()),this,SLOT(on_click()));
    this->affichMatrice();
}

Matrice::~Matrice()
{
    if(m_spin != NULL)
    {
        //delete m_spin;
        //delete m_label_modifying;
        delete m_file;
    }

    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille+1; j++)
                delete m_label[i][j];
        delete [] m_label[i];
    }

}


QFile* Matrice::getm_file()
{
    return m_file;
}

void Matrice::affichMatrice()
{
    m_label = new Label** [taille];
    for (int i = 0; i < taille; i++)
        m_label[i] = new Label* [taille+1];

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

    }
}

void Matrice::methode1()
{
    QVector< QVector<int> > a = this->val;
    int etape;
    int pivot;
    int repere;

    m_result = new Resultat();
    m_result->setWindowTitle("R�sultat :Pivot de Gauss");
    m_result->show();

    for(etape = 0;etape<taille-1;etape++)
    {
        pivot = a[etape][etape];
        m_result->ajouterResultat(a,"Etape " +QString::number(etape));
        for(int i = etape+1;i < taille;i++)
        {
            repere = a[i][etape];
            for(int j = etape; j < taille+1;j++)
                a[i][j] = pivot*a[i][j] - repere*a[etape][j];
        }
    }

    m_result->ajouterResultat(a,"Etape " +QString::number(etape));
    //La matrice est �chelonn�e ya pu qua trouver les valeurs ....




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

void Matrice::modify_taille(int t)
{
    if(taille == 1 && t == -1)
        return;

    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille+1; j++)
            delete m_label[i][j];
        delete [] m_label[i];
    }

    delete [] m_label;

    taille=taille+t;
    val.resize(taille);
    for(int i = 0;i < taille;i++)
        val[i].resize(taille+1);
    setMinimumSize(42*taille,21*taille);


    this->affichMatrice();
}
