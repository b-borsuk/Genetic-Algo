#include "cluster.h"

Cluster::Cluster()
{
    chromosomes.clear();
}

Cluster::Cluster(Chromosome *chromosome)
{
    chromosomes.clear();
    append( chromosome );
}

Cluster::~Cluster()
{
    chromosomes.clear();
}

void Cluster::append(Chromosome *chromosome)
{
    if ( chromosomes.isEmpty() )
        centroidChomosome = chromosome;
    chromosomes.append( chromosome );
}

void Cluster::setCentroid(Chromosome *chromosome)
{
    centroidChomosome = chromosome;
}

Chromosome *Cluster::centroid() const
{
    return centroidChomosome;
}

bool Cluster::isCentroid(const Chromosome *chromosome) const
{
    return chromosome == centroidChomosome;
}

double Cluster::operator-(const Chromosome &ch)
{
    return *centroidChomosome - ch;
}
