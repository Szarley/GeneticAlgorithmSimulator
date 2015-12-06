#include "parameters.h"

const QString UILabels::finishConditionIteration = "number of iterations to finish";
const QString UILabels::finishConditionChrMajority = "% of twin Chromosome to finish";

SimulationParameters::SimulationParameters()
    : finishCoefficient     (0),
      populationSize        (0),
      bitCount              (0),
      mutationBit           (0),
      elitismCoefficient    (0.0),
      mutationCoefficient   (0.0),
      selectionType         (SelectionType::RankSelection),
      mutationType          (MutationType::None),
      finishCondition       (FinishCondition::IterationCount)
{

}

SimulationParameters::SimulationParameters(
                     int finishCoeff,
                     int populationSize,
                     int bitCount,
                     int mutationBit,
                     double elitismCoefficient,
                     double mutationCoefficient,
                     SelectionType selectionType,
                     MutationType mutationType,
                     FinishCondition finishCondition)

    : finishCoefficient     (finishCoeff),
      populationSize        (populationSize),
      bitCount              (bitCount),
      mutationBit           (mutationBit),
      elitismCoefficient    (elitismCoefficient),
      mutationCoefficient   (mutationCoefficient),
      selectionType         (selectionType),
      mutationType          (mutationType),
      finishCondition       (finishCondition)
{

}
