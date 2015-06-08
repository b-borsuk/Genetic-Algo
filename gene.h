#ifndef GENE_H
#define GENE_H

class Gene
{
public:
    Gene(const int a, const int b, int count);

    double count() const;
    int count() const;
    void setCount(const int count);
    void setCount(const double count);


protected:
    int a;
    int b;
    int _count;
};

#endif // GENE_H
