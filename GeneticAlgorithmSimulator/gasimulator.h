#ifndef GASIMULATOR_H
#define GASIMULATOR_H
#include <stack>
#include "chromosomepopulation.h"
#include "parameters.h"
typedef double (*FitnessFunction)(double,double);
class GASimulator
{
public:
    GASimulator();
    void start();
    void stop() const;
    GASimulator & setParameters(const SimulationParameters & parameters);
private:
    std::stack<ChromosomePopulation> populationStack;
    FitnessComparisonPredicate fCompPred;
    SimulationParameters parameters;
};

#endif // GASIMULATOR_H
