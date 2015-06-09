#include "population.h"

#include <QDebug>

Population::Population(const int initalPopCount)
{
    for (int i=0; i<initalPopCount; ++i)
        chromosomes.append( Chromosome(2000) );
}

void Population::createNewPopulation()
{
    QList<Chromosome> newPopulation;
    newPopulation.append( chromosomes );

    int count = chromosomes.count();
    for (int i=0, iL=chromosomes.count() /2; i<iL; ++i)
    {
        int index = RAND * chromosomes.count();
        Chromosome f = chromosomes[index];
        chromosomes.removeAt(index);

        index = RAND * chromosomes.count();
        Chromosome m = chromosomes[index];
        chromosomes.removeAt(index);

        newPopulation.append( f + m );
        newPopulation.append( f + m );
        newPopulation.append( f + m );
        newPopulation.append( f + m );
    }

    qSort( newPopulation );

    int newCount = newPopulation.count();
    while (newCount-- > count)
        newPopulation.removeFirst();
}

