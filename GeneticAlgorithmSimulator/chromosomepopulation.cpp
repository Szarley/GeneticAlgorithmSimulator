#include "chromosomepopulation.h"

ChromosomePopulation::ChromosomePopulation(const int populationSize,const int bitCount, chromosomeGenerator generator)
{
    population.reserve(populationSize);
    for(int i = 0; i < populationSize ; ++i)
        population.push_back(generator(bitCount));
}
ChromosomePopulation* ChromosomePopulation::createNullPopulation(const int populationSize, const int bitCount)
{
    return new ChromosomePopulation(populationSize, bitCount, & Chromosome::createNullChromosome);
}

ChromosomePopulation* ChromosomePopulation::createRandomPopulation(const int populationSize, const int bitCount)
{
    return new ChromosomePopulation(populationSize, bitCount, & Chromosome::createRandomChromosome);
}

ChromosomePopulation::~ChromosomePopulation()
{
    for(auto chr : population)
        delete chr;
}
