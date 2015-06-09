#ifndef POPULATION_H
#define POPULATION_H

#include <QList>
#include "chromosome.h"

class Population
{
public:
    Population(const int initalPopCount);
    void createNewPopulation();

private:
    QList<Chromosome> chromosomes;
};

#endif // POPULATION_H
