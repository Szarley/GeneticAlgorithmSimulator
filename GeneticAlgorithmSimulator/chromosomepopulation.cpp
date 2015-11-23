#include "chromosomepopulation.h"

ChromosomePopulation::ChromosomePopulation(const int populationSize)
    : populationLimit(populationSize)
{
    population.reserve(populationSize);
}

ChromosomePopulation::ChromosomePopulation(const ChromosomePopulation & source)
    : populationLimit(source.populationLimit)
{
    this->population.reserve(populationLimit);
    for(auto chromosome : source.population)
        this->population.push_back(copy(chromosome));
}
ChromosomePopulation & ChromosomePopulation::operator=(const ChromosomePopulation & source)
{
    this->kill();
    for(auto chromosome : source.population)
        this->population.push_back(copy(chromosome));
    return *this;
}

ChromosomePopulation::~ChromosomePopulation()
{
    deletePopulationPointers();
}

ChromosomePopulation & ChromosomePopulation::fillWithRandomChromosomes(const int bitCount)
{
    while(population.size() != populationLimit)
        population.push_back(Chromosome::createRandomChromosome(bitCount));
    return *this;
}

ChromosomePopulation & ChromosomePopulation::fillWithZeroChromosomes(const int bitCount)
{
    while(population.size() != populationLimit)
        population.push_back(Chromosome::createZeroChromosome(bitCount));
    return *this;
}

ChromosomePopulation & ChromosomePopulation::kill()
{
    deletePopulationPointers();
    population.clear();
    return *this;
}

bool ChromosomePopulation::isFull() const
{
    return population.size() == populationLimit;
}

int ChromosomePopulation::size() const
{
    return population.size();
}
void ChromosomePopulation::deletePopulationPointers()
{
    for(auto chr : population)
        delete chr;
}
bool ChromosomePopulation::addChromosome(Chromosome *chromosome)
{
    if(isFull())
        return false;
    population.push_back(chromosome);
    return true;
}

ChromosomePopulation& ChromosomePopulation::sortByFitness(fitnessComparisonCheck)
{
    std::sort(population.begin(),population.back(),fitnessComparisonCheck);
}
