#include "population.h"

#include <QDebug>

#define CHROMOSOME_MIN_LENGTH 0.00001

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

    chromosomes.append( newPopulation );

    for (int i=0; i<chromosomes.count(); ++i)
        for (int j=0; j<chromosomes.count(); ++j)
        {
            if (i==j)
                continue;
            if (chromosomes[i] - chromosomes[j] < CHROMOSOME_MIN_LENGTH)
            {
                chromosomes.removeAt(i);
                --i;
                break;
            }
        }
}

void Population::print() const
{
    for (int i=0; i<chromosomes.count(); ++i)
        qDebug() << chromosomes[i].income() << " | " << chromosomes[i].fitness();

}

bool Population::finished() const
{
    return chromosomes.count() == 1;
}

