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

#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent),ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
    connect(ui->close,SIGNAL(clicked()),this,SLOT(close()));
    readSettings();

}
Settings::~Settings()
{
    delete ui;
}

void Settings::on_steps_clicked(bool checked)
{
    steps = checked;
}

void Settings::on__max_valueChanged(int value)
{
    _max = value;
}


void Settings::on_prec_valueChanged(double value)
{
    prec = value;
}

void Settings::closeEvent(QCloseEvent *event)
{
    this->close();
    emit closeW();
    writeSettings();
}

bool Settings::getSteps()
{
    return steps;
}

int Settings::get_Max()
{
    return _max;
}

double Settings::getprec()
{
    return prec;
}

void Settings::writeSettings()
{
    QSettings settings("Lorette Inc", "Lorette");
    settings.beginGroup("Settings");
    settings.setValue("steps", steps);
    settings.setValue("_max", _max);
    settings.setValue("prec", prec);
    settings.endGroup();
}

void Settings::readSettings()
{
    QSettings settings("Lorette Inc", "Lorette");
    settings.beginGroup("Settings");
    steps = settings.value("steps").toBool();
    _max = settings.value("_max").toInt();
    prec = settings.value("prec").toDouble();
    settings.endGroup();

    ui->steps->setChecked(steps);
    ui->_max->setValue(_max);
    ui->prec->setValue(prec);
}
