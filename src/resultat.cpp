#include "resultat.h"
#include "ui_resultat.h"

Resultat::Resultat() : QWidget(0),ui(new Ui::Resultat)
{
    ui->setupUi(this);
}

Resultat::~Resultat()
{
    delete ui;
}

void Resultat::ajouterResultat(QVector< QVector<int> > mat,QString name)
{
    QScrollArea *m_scroll = new QScrollArea(this);
    QWidget *m_widget = createWidget(mat,m_scroll);

    m_widget->setMinimumSize(42*mat.size(),21*mat.size());
    m_scroll->setWidget(m_widget);

    ui->tabWidget->addTab(m_scroll,name);

    m_scroll->show();
    m_widget->show();

}

QWidget* Resultat::createWidget(QVector<QVector<int> > mat,QWidget *parent)
{
    QWidget *widget = new QWidget(parent);
    QLabel *m_label;

    for(int i = 0;i < mat.size();i++)
    {
        for(int j = 0;j < mat[i].size();j++)
        {
            m_label = new QLabel(parent);
            m_label->setText(QString::number(mat[i][j]));
            m_label->setGeometry(QRect(40*j+52,20*i+10,40,20));
            m_label->show();
        }

    }
    widget->show();
    return widget;
}
