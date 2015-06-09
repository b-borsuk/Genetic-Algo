#ifndef GENE_H
#define GENE_H

#define RAND ((float)qrand() / RAND_MAX)

class Gene
{
public:
    Gene();
    Gene(const int min, const int max, const double incomeAll);

    int count() const;
    double countDouble() const;
    void setCount(const int count);
    void setCount(const double count);
    double incomeAll() const;
    double income() const;

protected:
    int min;
    int max;
    int _count;
    int _income;
};

#endif // GENE_H
