#ifndef POPULATION_H
#define POPULATION_H

#include <QList>
#include "chromosome.h"

class Population
{
public:
    Population(const int initalPopCount);
    void createNewPopulation();
    bool finished() const;

    void print() const;

protected:
    QList<Chromosome> chromosomes;
};

#endif // POPULATION_H
