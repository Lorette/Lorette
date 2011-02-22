#include "resultat.h"
#include "ui_resultat.h"

Resultat::Resultat() : QWidget(0),ui(new Ui::Resultat)
{
    ui->setupUi(this);
    m_button_quit = new QPushButton("Fermer",ui->buttonBox);
    ui->buttonBox->addButton(m_button_quit,QDialogButtonBox::NoRole);

    connect(m_button_quit,SIGNAL(clicked()),this,SLOT(close()));
}

Resultat::~Resultat()
{
    delete m_button_quit;
    delete ui;
}

void Resultat::ResulatMethode1(QVector< QVector<float> > mat,QString name)
{
    QScrollArea *m_scroll = new QScrollArea(this);
    QWidget *m_widget = WidgetMethode1(mat,m_scroll);

    m_widget->setMinimumSize(42*mat.size(),21*mat.size());
    m_scroll->setWidget(m_widget);

    ui->tabWidget->addTab(m_scroll,name);
    ui->tabWidget->setCurrentWidget(m_scroll);

    m_scroll->show();
    m_widget->show();

}

QWidget* Resultat::WidgetMethode1(QVector<QVector<float> > mat,QWidget *parent)
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

void Resultat::ResulatMethode2(QVector<float> inco,QString name)
{
    QScrollArea *m_scroll = new QScrollArea(this);
    QWidget *m_widget = WidgetMethode2(inco,m_scroll);

    m_widget->setMinimumSize(42*inco.size(),21*inco.size());
    m_scroll->setWidget(m_widget);

    ui->tabWidget->addTab(m_scroll,name);
    ui->tabWidget->setCurrentWidget(m_scroll);

    m_scroll->show();
    m_widget->show();

}

QWidget* Resultat::WidgetMethode2(QVector<float> inco,QWidget *parent)
{
    QWidget *widget = new QWidget(parent);
    QLabel *m_label;

    for(int i = 0;i < inco.size();i++)
    {
        m_label = new QLabel(parent);
        m_label->setText("Inconnue n° "+QString::number(i+1) +" = " +QString::number(inco[i]));
        m_label->setGeometry(QRect(52,20*i+10,200,20));
        m_label->show();
    }
    widget->show();
    return widget;
}
