#include <QtGui/QApplication>
#include "proj2d_ng.h"
#include "ibexuser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ibexUser ibexer;

    Proj2D_NG w;
    w.setIbexUser(&ibexer);
    w.show();
    
    return a.exec();
}
