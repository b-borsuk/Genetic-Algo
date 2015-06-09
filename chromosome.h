#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "gene.h"

#include <QVector>

class Chromosome
{
public:
    Chromosome();
    Chromosome(const int money);

    double fitness() const;
    Chromosome operator+ (const Chromosome &ch);
    double operator- (const Chromosome &ch);
    bool operator< (const Chromosome &ch) const;
    void mutate();

    double income() const;
protected:
    QVector<Gene> genes;
    int money;
};

#endif // CHROMOSOME_H
