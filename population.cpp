#include "population.h"

#include <QDebug>

Population::Population(const int initalPopCount)
{
    for (int i=0; i<initalPopCount; ++i)
        chromosomes.append( Chromosome(2000) );
}

void Population::createNewPopulation()
{

}

