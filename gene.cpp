#include "gene.h"

Gene::Gene(const int a, const int b, int count) :
    a(a),
    b(b),
    _count(count)
{
}

int Gene::count() const
{
    return _count;
}

double Gene::count() const
{
    return _count / (a+b);
}

void Gene::setCount(const int count)
{
    _count = count;
}

void Gene::setCount(const double count)
{
    _count = count * (a+b);
}
