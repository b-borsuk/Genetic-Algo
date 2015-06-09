#include "chromosome.h"

#include <QtCore/QtMath>

Chromosome::Chromosome() :
    money(0)
{
}

Chromosome::Chromosome(const int money) :
    money(money)
{
    genes.clear();
    genes.append( Gene(10, 20, 6, 12.5) );
    genes.append( Gene(10, 50, 2, 6.8) );
    genes.append( Gene(100, 120, 11.6, 20) );
    genes.append( Gene(5, 50, 20, 10.4) );
    genes.append( Gene(40, 90, 5, 18.9) );

    for (int i=0; i<genes.count(); ++i)
        genes[i].setCount( RAND );
}

double Chromosome::fitness() const
{
    double buf = this->price();

    double income = 0;
    for (int i=0; i<genes.count(); ++i)
        income += genes[i].income() * genes[i].price() / buf;

    double penalty = (2 * qAbs(buf - money) + buf - money) / 2;

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

double Chromosome::operator-(const Chromosome &ch)
{
    double res=0;

    for (int i=0; i<this->genes.count(); ++i)
        res += qPow( this->genes[i].count() - ch.genes[i].count(), 2 );

    return qSqrt(res);
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

double Chromosome::income() const
{
    double income = 0;

    for (int i=0; i<genes.count(); ++i)
        income += genes[i].incomeAll();

    return income;
}

double Chromosome::price() const
{
    double income = 0;

    for (int i=0; i<genes.count(); ++i)
        income += genes[i].price();

    return income;
}

