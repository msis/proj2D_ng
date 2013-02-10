#include <QtGui/QApplication>
#include "proj2d_ng.h"
#include "expnode.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proj2D_NG w;
    w.show();
    
    return a.exec();
}
