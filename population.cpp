#include "population.h"

#include <QDebug>

#define CHROMOSOME_MIN_LENGTH 0.00001

Population::Population(const int initalPopCount, const int clusterRadius, const double mutationProbability) :
    clusterRadius(clusterRadius),
    mutationProbability(mutationProbability),
    popCount(initalPopCount)
{
    for (int i=0; i<initalPopCount; ++i)
        chromosomes.append( Chromosome(2000) );
}

void Population::createNewPopulation()
{
    clustering();
    createNewChromosomesinClusters();

    //createNewChromosomes();
/*    for (int i=0; i<chromosomes.count(); ++i)
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
        */
}

bool Population::finished() const
{
    return chromosomes.count() == 1;
}

void Population::print() const
{
    for (int i=0; i<chromosomes.count(); ++i)
        qDebug() << chromosomes[i].income() << " | " << chromosomes[i].fitness();

}

void Population::createNewChromosomes()
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
}

void Population::createNewChromosomesinClusters()
{
    // create new chromosomes
    QList<Chromosome> newPopulation;
    newPopulation.append( chromosomes );
    for (int c=0, cL=clusters.count(); c<cL; ++c)
    {

        for (int i=0, iL=clusters[i].chromosomes.count() /2; i<iL; ++i)
        {
            int index = RAND * clusters[c].chromosomes.count();
            Chromosome f = *clusters[c].chromosomes[index];
            clusters[c].chromosomes.removeAt(index);

            index = RAND * clusters[c].chromosomes.count();
            Chromosome m = *clusters[c].chromosomes[index];
            clusters[c].chromosomes.removeAt(index);

            newPopulation.append( f + m );
            newPopulation.append( f + m );
            newPopulation.append( f + m );
            newPopulation.append( f + m );
        }
    }

    // kill bad chromosomes
    qSort( newPopulation );

    int count = popCount;
    //int count = chromosomes.count();
    int newCount = newPopulation.count();
    int removeIndex = 0;
    while (newCount-- > count)
    {
        if (removeIndex >= newCount)
            break; //TODO: ?
        bool isCentroid = false;
        for (int i=0, iL=clusters.count(); i<iL; ++i)
            if ( clusters[i].isCentroid( &newPopulation[removeIndex] ) )
            {
                isCentroid = true;
                break;
            }
        if ( ! isCentroid )
            newPopulation.removeAt( removeIndex );
        else
            removeIndex++;
    }

    // random mutation
    for (int i=0, iL=newPopulation.count(); i<iL; ++i)
    {
        bool isCentroid = false;
        for (int c=0, cL=clusters.count(); c<cL; ++c)
            if ( clusters[c].isCentroid( &newPopulation[i] ) )
            {
                isCentroid = true;
                break;
            }
        if ( ! isCentroid )
            if (RAND < mutationProbability)
                newPopulation[i].mutate();
    }

    clusters.clear();
    chromosomes.clear();
    chromosomes.append( newPopulation );
}

void Population::clustering()
{
    qSort(chromosomes);

    clusters.clear();
    for (int i=chromosomes.count()-1; i>=0; --i)
    {
        bool inCluster = false;
        for (int j=0, jL=clusters.count(); j<jL; ++j)
            if (clusters[j] - chromosomes[i] < clusterRadius)
            {
                clusters[j].append( &chromosomes[i] );
                inCluster = true;
            }
        if ( ! inCluster )
            clusters.append( Cluster( &chromosomes[i] ) );
    }

    //return;

    for (int i=0; i<clusters.count(); ++i)
        if (clusters[i].chromosomes.count() <= 1)
        {
            Chromosome ch = *clusters[i].chromosomes[0];
            ch.mutate();
            chromosomes.append( ch );
            clusters[i].append( &chromosomes[ chromosomes.count() -1 ] );
        }

}
