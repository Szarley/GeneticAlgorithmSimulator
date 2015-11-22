#ifndef CHROMOSOMEPOPULATION_H
#define CHROMOSOMEPOPULATION_H
#include <vector>
#include "chromosome.h"

typedef Chromosome* (*chromosomeGenerator)(int);
class ChromosomePopulation
{
public:
    static ChromosomePopulation* createNullPopulation(const int populationSize, const int bitCount);
    static ChromosomePopulation* createRandomPopulation(const int populationSize, const int bitCount);
    ~ChromosomePopulation();
private:
    std::vector<Chromosome*> population;
    ChromosomePopulation(const int populationSize,const int bitCount, chromosomeGenerator generator);

    ChromosomePopulation(const ChromosomePopulation &)=delete;
    ChromosomePopulation & operator=(const ChromosomePopulation &)=delete;
};

#endif // CHROMOSOMEPOPULATION_H
