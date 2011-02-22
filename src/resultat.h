#ifndef RESULTAT_H
#define RESULTAT_H

#include <QFrame>
#include <QVector>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

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

private:
    Ui::Resultat *ui;
    QPushButton *m_button_quit;

};

#endif // RESULTAT_H
