#ifndef PARAMETERS_LONG_PRETTYFULL_HEADER
#define PARAMETERS_LONG_PRETTYFULL_HEADER
#include "enumtypes.h"
#include <QString>
struct SimulationParameters
{

    int finishCoefficient;

    int populationSize;

    int bitCount;

    int mutationBit;

    double elitismCoefficient;

    double mutationCoefficient;

    SelectionType selectionType;

    MutationType mutationType;

    FinishCondition finishCondition;

    SimulationParameters();

    SimulationParameters(int finishCoeff,
                         int populationSize,
                         int bitCount,
                         int mutationBit,
                         double elitismCoefficient,
                         double mutationCoefficient,
                         SelectionType selectionType,
                         MutationType mutationType,
                         FinishCondition finishCondition);
};

struct UILabels{
    static const QString finishConditionIteration;
    static const QString finishConditionChrMajority;
};

#endif // PARAMETERS_LONG_PRETTYFULL_HEADER

