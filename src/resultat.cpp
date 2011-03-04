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
    m_list.clear();
}

void Resultat::ResulatMethode1(QVector< QVector<float> > mat,QString name)
{
    QScrollArea *m_scroll = new QScrollArea(this);
    QWidget *m_widget = WidgetMethode1(mat,m_scroll);

    m_widget->setMinimumSize(60*mat.size()+27,28.5*mat.size()+25);
    m_scroll->setWidget(m_widget);

    ui->tabWidget->addTab(m_scroll,name);
    ui->tabWidget->setCurrentWidget(m_scroll);

    m_scroll->show();
    m_widget->show();

}

QWidget* Resultat::WidgetMethode1(QVector<QVector<float> > mat,QWidget *parent)
{
    QWidget *widget = new QWidget(parent);
    QLabel *m_label = new QLabel(widget);

    for(int i = 0;i < mat.size();i++)
    {
        for(int j = 0;j < mat[i].size();j++)
            m_label->setText(m_label->text() +"       " +QString::number(mat[i][j]));
        m_label->setText(m_label->text()+"\n\n");
    }

    m_label->setGeometry(QRect(27,25,60*(mat.size()+1),28.5*mat.size()));
    m_label->show();
    m_list << m_label;

    widget->show();
    return widget;
}

void Resultat::ResulatMethode2(QVector<float> inco,QString name)
{
    QScrollArea *m_scroll = new QScrollArea(this);
    QWidget *m_widget = WidgetMethode2(inco,m_scroll);
    m_widget->setMinimumSize(350+40,28.5*inco.size()+25);
    m_scroll->setWidget(m_widget);

    ui->tabWidget->addTab(m_scroll,name);
    ui->tabWidget->setCurrentWidget(m_scroll);

    m_scroll->show();
    m_widget->show();

}

QWidget* Resultat::WidgetMethode2(QVector<float> inco,QWidget *parent)
{
    QWidget *widget = new QWidget(parent);
    QLabel *m_label = new QLabel(widget);

    for(int i = 0;i < inco.size();i++)
    {
        m_label->setText(m_label->text() +"Inconnue n° "+QString::number(i+1) +" = " +QString::number(inco[i]) +"\n\n");
    }

    m_label->setGeometry(QRect(40,25,350,29*inco.size()));
    m_label->show();
    m_list << m_label;

    widget->show();
    return widget;
}

void Resultat::closeEvent(QCloseEvent *event)
{

    this->deleteLater();
}
