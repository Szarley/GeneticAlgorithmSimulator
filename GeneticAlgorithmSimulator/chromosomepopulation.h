#ifndef CHROMOSOMEPOPULATION_H
#define CHROMOSOMEPOPULATION_H
#include <vector>
#include <algorithm>
#include "chromosome.h"

double (*fitnessComparisonCheck)(Chromosome*,Chromosome*);
class ChromosomePopulation
{
public:
    ~ChromosomePopulation();
    ChromosomePopulation(const int populationLimit);
    ChromosomePopulation(const ChromosomePopulation &);
    ChromosomePopulation & operator=(const ChromosomePopulation &);

    ChromosomePopulation & fillWithRandomChromosomes(const int bitCount);
    ChromosomePopulation & fillWithZeroChromosomes(const int bitCount);
    ChromosomePopulation & kill();
    bool addChromosome(Chromosome* chromosome);
    ChromosomePopulation & sortByFitness(fitnessComparisonCheck);
    bool isFull() const;
    int size() const;

private:
    std::vector<Chromosome*> population;
    int populationLimit;
    void deletePopulationPointers();
};


#endif // CHROMOSOMEPOPULATION_H
