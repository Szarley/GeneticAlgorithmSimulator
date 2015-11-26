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
    this->populationLimit = source.populationLimit;
    for(auto chromosome : source.population)
    {
        this->population.push_back(copy(chromosome));        
    }
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

ChromosomePopulation & ChromosomePopulation::sortByFitness(FitnessComparisonPredicate compare)
{
    std::sort(population.begin(),population.end(),compare);
    return *this;
}
ChromosomePopulation & ChromosomePopulation::mutate(MutationType mutationType, const double mutationCoefficient, const int bit)
{
    switch(mutationType)
    {
    case MutationType::ChosenBit:
        return chosenBitMutation(mutationCoefficient, bit);
    case MutationType::RandomBit:
        return randomMutation(mutationCoefficient);
    case MutationType::None:
        return *this;
    default:
        return *this;
    };
}

/*
 *
 * TODO:
 * Functions:
 * ChromosomePopulation::randomMutation
 * ChromosomePopulation::chosenBitMutation  ->  DRY violation....
 *
 */
ChromosomePopulation & ChromosomePopulation::chosenBitMutation(const double mutationCoefficient, const int bit)
{
    int coefficient = transposeMutationCoefficient(mutationCoefficient);
    for(auto chromosome : population)
    {
        if(UniformIntGenerator::instance().generate(1,100) < coefficient)
            chromosome->mutateBit(bit);
    }
    return *this;
}

ChromosomePopulation & ChromosomePopulation::randomMutation(const double mutationCoefficient)
{
    int coefficient = transposeMutationCoefficient(mutationCoefficient);
    for(auto chromosome : population)
    {
        if(UniformIntGenerator::instance().generate(1,100) < coefficient)
            chromosome->mutateRandomBit();
    }
    return *this;
}

int ChromosomePopulation::transposeMutationCoefficient(const double mutationCoefficient) const
{
    if(mutationCoefficient <= 0) return 0;
    if(mutationCoefficient >= 1.0) return 100;
    return (mutationCoefficient * 100);
}
