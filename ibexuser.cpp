#include "ibexuser.h"

ibexUser::ibexUser(QObject *parent) :
    QObject(parent)
{
}

ibexUser::~ibexUser()
{
    delete function;
}

void ibexUser::constraintsText(QString s)
{
    filename.append(QDateTime::currentDateTime().toString("yyMMddhhmm"));
    filename.append(".txt");

//Create special folder for functions
//    QDir d(QDir::current());
//    if (!d.mkdir("functions"))
//        qDebug() << "functions directory does not exist. It will be created";
//    filename.prepend("functions/");
//

    f.setFileName(filename);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Could not open the file in write mode" ;
        return;
    }


    QTextStream out(&f);
    out << s;

    f.close();
}

void ibexUser::setFilename(QString s)
{
    filename.clear();
    filename = s;
}

void ibexUser::feedIbexWithFunction()
{
    const char* charFilename=filename.toAscii().constData();
    function = new ibex::Function(charFilename);

    qDebug() << "function has " << function->nb_arg() << "argument(s).";
    for (int i = 0; i < function->nb_arg(); i++)
    {
        qDebug() << "argument " << i << " name is " << function->arg_name(i);
    }
    qDebug() << "the expression of the funciton is " << function->name;
}
