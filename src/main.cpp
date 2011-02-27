#include <QtGui/QApplication>
#include "lorette.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lorette w;
    w.show();
    return a.exec();
}
