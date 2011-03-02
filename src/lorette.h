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

#ifndef LORETTE_H
#define LORETTE_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QToolBar>
#include <QProgressBar>
#include <QSettings>
#include "matrice.h"
#include "settings.h"

namespace Ui {
    class Lorette;
}

class Lorette : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lorette(QWidget *parent = 0);
    ~Lorette();
    void createForm();

private:
    Ui::Lorette *ui;
    Matrice *mat;
    Settings *set;
    int methode;
    QString name;
    QPushButton *m_button_exec,*m_button_quit;
    QAction *newAct,*openAct,*saveAct,*saveAsAct,*exitAct,*addAct,*delAct,*genAAct,*genAct,*setAct,*aboutAct;
    QToolBar *fileToolBar,*toolBar;
    QProgressBar *m_progress;


private slots:
    void actionOuvrir_Matrice_triggered();
    bool actionEnregistrer_Sous_triggered();
    bool actionEnregistrer_triggered();
    void clickm_button_exec();
    void actionNouvelle_Matrice_triggered();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void pushButton_2_clicked();
    void pushButton_clicked();
    void actionGen_Matrice();
    void actionGen_Matrice_aleatoire();
    void progress_value_changed(int value);
    void delete_matrice();
    void actionSettings();
    void actionAbout();
    void closeSettings();
};

#endif // LORETTE_H
