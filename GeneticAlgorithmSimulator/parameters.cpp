#include "parameters.h"

const QString UILabels::finishConditionIteration = "number of iterations to finish";
const QString UILabels::finishConditionChrMajority = "% of twin Chromosome to finish";

SimulationParameters::SimulationParameters()
    : iterationCount        (0),
      elitismCoefficient    (0.0),
      mutationCoefficient   (0.0),
      selectionType         (SelectionType::RankSelection),
      mutationType          (MutationType::None),
      finishCondition       (FinishCondition::IterationCount),
      fitFunction           (nullptr)
{

}

SimulationParameters::SimulationParameters(int iterationCount,
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
