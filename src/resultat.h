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
