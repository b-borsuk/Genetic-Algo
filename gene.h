#ifndef GENE_H
#define GENE_H

#define RAND ((float)qrand() / RAND_MAX)
#include "chromosometest.h"
class Gene
{
public:
    friend class ChromosomeTest;
    Gene();
    Gene(const int min, const int max, const double price, const double incomeAll);

    int count() const;
    double countDouble() const;
    void setCount(const int count);
    void setCount(const double count);
    double incomeAll() const;
    double income() const;
    double price() const;

protected:
    int min;
    int max;
    int _count;
    int _income;
    double _price;
};

#endif // GENE_H
