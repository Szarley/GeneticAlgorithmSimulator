#ifndef PARAMETERS_LONG_PRETTYFULL_HEADER
#define PARAMETERS_LONG_PRETTYFULL_HEADER
#include "enumtypes.h"
#include <QString>
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

    SimulationParameters();

    SimulationParameters(int iterationCount,
                         double elitismCoefficient,
                         double mutationCoefficient,
                         SelectionType selectionType,
                         MutationType mutationType,
                         FinishCondition finishCondition,
                         FitnessFunction fitFunction);
};

struct UILabels{
    static const QString finishConditionIteration;
    static const QString finishConditionChrMajority;
};

#endif // PARAMETERS_LONG_PRETTYFULL_HEADER

