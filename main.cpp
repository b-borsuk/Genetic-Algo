#include <QCoreApplication>

#include "population.h"
#include <QDebug>
#include "chromosometest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   /* ChromosomeTest *ch = new ChromosomeTest();
    ch->f(0);
    delete ch;
    return 0;*/

    Population p(20, 50, 0.2);

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
