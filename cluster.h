#ifndef CLUSTER_H
#define CLUSTER_H

#include <QList>
#include "chromosome.h"

class Cluster
{
public:
    Cluster();
    Cluster(Chromosome *chromosome);
    ~Cluster();

    void append(Chromosome *chromosome);
    void setCentroid(Chromosome *chromosome);
    Chromosome *centroid() const;
    bool isCentroid(const Chromosome *chromosome) const;
    double operator- (const Chromosome &ch);

    QList<Chromosome *> chromosomes;

protected:
    Chromosome *centroidChomosome;
};

#endif // CLUSTER_H
