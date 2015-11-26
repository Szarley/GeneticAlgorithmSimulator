#ifndef GASIMULATOR_H
#define GASIMULATOR_H
#include <stack>
#include "chromosomepopulation.h"
#include "parameters.h"

class GASimulator
{
public:
    GASimulator();

    void start();

    GASimulator & setParameters(SimulationParameters newParameters);

private:
    std::stack<ChromosomePopulation> populationStack;

    FitnessComparisonPredicate fCompPred;

    SimulationParameters parameters;
};








#endif // GASIMULATOR_H
