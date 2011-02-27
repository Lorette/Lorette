#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent),ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
    connect(ui->close,SIGNAL(clicked()),this,SLOT(close()));
    readSettings();

    ui->steps->setChecked(steps);


}
Settings::~Settings()
{
    delete ui;
}

void Settings::on_steps_clicked(bool checked)
{
    steps = checked;
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

void Settings::writeSettings()
{
    QSettings settings("Lorette Inc", "Lorette");
    settings.beginGroup("Settings");
    settings.setValue("steps", steps);
    settings.endGroup();
}

void Settings::readSettings()
{
    QSettings settings("Lorette Inc", "Lorette");
    settings.beginGroup("Settings");
    steps = settings.value("steps").toBool();
}
