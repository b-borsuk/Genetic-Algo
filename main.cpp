#include <QCoreApplication>

#include "population.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Population p(20);

    p.createNewPopulation();

    return a.exec();
}
