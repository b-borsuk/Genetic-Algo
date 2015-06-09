#include "chromosometest.h"

#include "chromosome.h"
#include <QDebug>

ChromosomeTest::ChromosomeTest() :
    file("test.txt")
{
    ch = new Chromosome(2000);
    count = ch->genes.count() -1;


    file.open(QFile::Text | QFile::WriteOnly);
    ts = new QTextStream(&file);
    m = -1000000000;
}

ChromosomeTest::~ChromosomeTest()
{
    file.close();
    delete ch;
    delete ts;
    qDebug() << m;
}

void ChromosomeTest::f(int i)
{
    for (int g=ch->genes[i].min, iL=ch->genes[i].max; g<iL; ++g)
    {
        if (i == 0)
            qDebug() << g;
        if (i == 1)
            qDebug() <<"--" << g;
        ch->genes[i].setCount(g);
        if (count == i)
        {

            /*for (int j=0; j<=count; ++j)
                *ts << ch->genes[j].count() << " | ";
            *ts << ch->fitness();*/
            double k = ch->fitness();
            if (k>m)
                m = k;

        }
        else
            f(i+1);
    }
}

