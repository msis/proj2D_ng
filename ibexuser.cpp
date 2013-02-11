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
    // ibex::Function doesn't take a path into account!!
    function = new ibex::Function(charFilename);

    qDebug() << "function has " << function->nb_arg() << "argument(s).";
    for (int i = 0; i < function->nb_arg(); i++)
    {
        emit (newVariableFound(i,function->arg_name(i)));

        varNameMap.insert(i,function->arg_name(i));

        qDebug() << "argument " << i << " name is " << function->arg_name(i);
    }
    qDebug() << "the expression of the funciton is " << function->name;
}

void ibexUser::setVarInterval(int index, QString name, double lBound, double uBound)
{
    if (varNameMap.value(index) == name)
    {
        varLBMap.insert(index,lBound);
        varUBMap.insert(index,uBound);
    }
    else
        qDebug() << "Something is wrong: Waiting for variable name " << varNameMap.value(index) <<
                    ". Received " << name << " for index " << index;
}


void ibexUser::setStartBox()
{
    ibex::IntervalVector box(varNameMap.size());

    QMapIterator<int, QString> i(varNameMap);
    while (i.hasNext()) {
        i.next();

        int key = i.key();

        box[key] = ibex::Interval(varLBMap.value(key),varUBMap.value(key));
    }
    startBox = new ibex::IntervalVector(box);

    processBox();
}

void ibexUser::processBox()
{
    outBox = new ibex::IntervalMatrix(function->eval_matrix(*startBox));
    std::cout << *outBox << std::endl;
}
