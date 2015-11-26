#ifndef CHROMOSOMEPOPULATION_H
#define CHROMOSOMEPOPULATION_H
#include <vector>
#include <algorithm>
#include "chromosome.h"
#include "enumtypes.h"

typedef bool (*FitnessComparisonPredicate)(Chromosome*,Chromosome*);

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

    ChromosomePopulation & mutate(MutationType mutationType = MutationType::None,
                                  const double mutationCoefficient = 0.01,
                                  const int bit=0);

    bool addChromosome(Chromosome* chromosome);

    ChromosomePopulation & sortByFitness(FitnessComparisonPredicate comparator);

    bool isFull() const;

    int size() const;

private:
    std::vector<Chromosome*> population;

    int populationLimit;

    void deletePopulationPointers();

    int transposeMutationCoefficient(const double mutationCoefficient) const;

    ChromosomePopulation & randomMutation(const double mutationCoefficient);

    ChromosomePopulation & chosenBitMutation(const double mutationCoefficient,
                                  const int bit);
};


#endif // CHROMOSOMEPOPULATION_H
