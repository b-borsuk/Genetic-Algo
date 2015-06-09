#include <QCoreApplication>

#include "population.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Population p(20);

    p.print();

    int i;
    for (i=0; i<5000; ++i)
    {
        p.createNewPopulation();
        if ( p.finished() )
            break;
    }

    qDebug() << "------------";
    qDebug() << i;
    qDebug() << "------------";
    p.print();

    return a.exec();
}
