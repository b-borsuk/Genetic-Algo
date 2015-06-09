#include "chromosome.h"

#define RAND ((float)qrand() / RAND_MAX)
#include <QDebug>

Chromosome::Chromosome() :
    money(0)
{
}

Chromosome::Chromosome(const int money) :
    money(money)
{
    genes.clear();
    genes.append( Gene(10, 20, 12.5) );
    genes.append( Gene(10, 200, 6.8) );
    genes.append( Gene(100, 120, 20) );
    genes.append( Gene(5, 50, 10.4) );
    genes.append( Gene(40, 150, 18.9) );

    for (int i=0; i<genes.count(); ++i)
        genes[i].setCount( RAND );
}

double Chromosome::fitness() const
{
    double income = 0;
    for (int i=0; i<genes.count(); ++i)
        income += genes[i].income();

    double penalty = 0;


    return income - penalty;
}

Chromosome Chromosome::operator+(const Chromosome &ch)
{
    Chromosome res;

    res.money = this->money;

    res.genes.clear();
    for (int i=0; i<this->genes.count(); ++i)
        res.genes.append( RAND > 0.5 ? this->genes[i] : ch.genes[i] );

    return res;
}

bool Chromosome::operator<(const Chromosome &ch) const
{
    return this->fitness() < ch.fitness();
}

void Chromosome::mutate()
{
    for (int i=0; i<genes.count(); ++i)
        if (RAND > 0.6)
            genes[i].setCount( RAND );
}

