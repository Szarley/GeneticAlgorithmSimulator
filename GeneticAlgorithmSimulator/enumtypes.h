#ifndef ENUMTYPES_THIS_HEADER_SHOULD_BE_LONGER
#define ENUMTYPES_THIS_HEADER_SHOULD_BE_LONGER

/**
 * @brief The SelectionType enum specifies the selection type used in the GA.
 * Selection influences which chromosomes have the biggest chance to take part in the breeding process.
 */
enum class SelectionType
{
    RankSelection
};

/**
 * @brief The MutationType enum specifies the mutation type used in the GA.
 * Mutation changes 1 bit of the Chromosome.
 */
enum class MutationType
{
    None,
    RandomBit,
    ChosenBit
};

/**
 * @brief The FinishCondition enum specifies the algorithm finish condition.
 * After the condition is met, algorithm stops working and the last population is believed to be a result.
 */
enum class FinishCondition
{
    IterationCount,
    ChromosomeMajority
};

#endif // ENUMTYPES_THIS_HEADER_SHOULD_BE_LONGER

