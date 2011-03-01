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
