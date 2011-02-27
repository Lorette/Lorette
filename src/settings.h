#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSettings>

namespace Ui {
    class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    Ui::Settings *ui;
    bool steps;

public:
    void closeEvent(QCloseEvent *event);
    bool getSteps();
    void writeSettings();
    void readSettings();

private slots:
    void on_steps_clicked(bool checked);

signals:
    void closeW();

};

#endif // SETTINGS_H
