#ifndef PARAMETERS_LONG_PRETTYFULL_HEADER
#define PARAMETERS_LONG_PRETTYFULL_HEADER
#include "enumtypes.h"

typedef double (*FitnessFunction)(double,double);

struct SimulationParameters
{

    int iterationCount;

    double elitismCoefficient;

    double mutationCoefficient;

    SelectionType selectionType;

    MutationType mutationType;

    FinishCondition finishCondition;

    FitnessFunction fitFunction;

    SimulationParameters()
        : iterationCount        (0),
          elitismCoefficient    (0.0),
          mutationCoefficient   (0.0),
          selectionType         (SelectionType::RankSelection),
          mutationType          (MutationType::None),
          finishCondition       (FinishCondition::IterationCount),
          fitFunction           (nullptr)
    {
    }

    SimulationParameters(int iterationCount,
                         double elitismCoefficient,
                         double mutationCoefficient,
                         SelectionType selectionType,
                         MutationType mutationType,
                         FinishCondition finishCondition,
                         FitnessFunction fitFunction)

        : iterationCount        (iterationCount),
          elitismCoefficient    (elitismCoefficient),
          mutationCoefficient   (mutationCoefficient),
          selectionType         (selectionType),
          mutationType          (mutationType),
          finishCondition       (finishCondition),
          fitFunction           (fitFunction)
    {
    }
};

#endif // PARAMETERS_LONG_PRETTYFULL_HEADER

