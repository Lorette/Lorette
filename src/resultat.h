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

#ifndef RESULTAT_H
#define RESULTAT_H

#include <QFrame>
#include <QVector>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QList>

namespace Ui {
    class Resultat;
}

class Resultat : public QWidget
{
    Q_OBJECT

public:
    explicit Resultat();
    ~Resultat();
    void ResulatMethode1(QVector< QVector<float> > mat,QString name);
    QWidget* WidgetMethode1(QVector< QVector<float> > mat,QWidget *parent);
    void ResulatMethode2(QVector<float> inco,QString name);
    QWidget* WidgetMethode2(QVector<float> inco,QWidget *parent);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Resultat *ui;
    QPushButton *m_button_quit;
    QList<QLabel*> m_list;

};

#endif // RESULTAT_H
