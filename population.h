#ifndef POPULATION_H
#define POPULATION_H

#include <QList>
#include <QVector>
#include "chromosome.h"
#include "cluster.h"

class Population
{
public:
    Population(const int initalPopCount, const int clusterRadius, const double mutationProbability);
    void createNewPopulation();
    bool finished() const;

    void print() const;

protected:
    int clusterRadius;
    double mutationProbability;
    int popCount;
    QList<Chromosome> chromosomes;
    QVector<Cluster> clusters;

    void createNewChromosomes();
    void createNewChromosomesinClusters();
    void clustering();
};

#endif // POPULATION_H
