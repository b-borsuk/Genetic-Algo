#ifndef CHROMOSOMETEST_H
#define CHROMOSOMETEST_H

#include <QFile>
#include <QTextStream>


class Chromosome;

class ChromosomeTest //: public Chromosome
{
public:
    ChromosomeTest();
    ~ChromosomeTest();

    void f(int i);

    Chromosome *ch;
    int count;
    QFile file;
    QTextStream *ts;

    double m;
};

#endif // CHROMOSOMETEST_H
