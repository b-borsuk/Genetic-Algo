#include "gene.h"

Gene::Gene() :
    min(0),
    max(0),
    _count(0),
    _income(0)
{
}

Gene::Gene(const int min, const int max, const double income) :
    min(min),
    max(max),
    _count(0),
    _income(income)
{
}

int Gene::count() const
{
    return _count;
}

double Gene::countDouble() const
{
    return _count / (min+max);
}

void Gene::setCount(const int count)
{
    _count = count;
}

void Gene::setCount(const double count)
{
    _count = count * (min+max);
}

double Gene::incomeAll() const
{
    return _income * _count;
}

double Gene::income() const
{
    return _income;
}

