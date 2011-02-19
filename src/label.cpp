#include "label.h"

Label::Label(QWidget *parent, int i,int j) : QLabel(parent)
{
    m_x = i;
    m_y = j;
}
