#ifndef RESULTAT_H
#define RESULTAT_H

#include <QFrame>
#include <QVector>
#include <QScrollArea>
#include <QLabel>

namespace Ui {
    class Resultat;
}

class Resultat : public QWidget
{
    Q_OBJECT

public:
    explicit Resultat();
    ~Resultat();
    void ajouterResultat(QVector< QVector<int> > mat,QString name);
    QWidget* createWidget(QVector< QVector<int> > mat,QWidget *parent);

private:
    Ui::Resultat *ui;
};

#endif // RESULTAT_H
