#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>

class Label : public QLabel
{
    Q_OBJECT;

    public :
        explicit Label(QWidget *parent,int i,int j);
        int getm_x()
        {
            return m_x;
        }
        int getm_y()
        {
            return m_y;
        }

    private :
        int m_x;
        int m_y;

    public slots:
        void mouseReleaseEvent ( QMouseEvent * event )
        {
            emit(clicked(this));
             event->accept();
        }

    signals:
    void clicked(Label *l);
};

#endif // LABEL_H
