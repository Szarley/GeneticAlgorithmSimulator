#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include <cmath>
#include <string>
#include "uniformintgenerator.h"
class Chromosome
{
    friend Chromosome* copy(Chromosome *source);
public:
    static Chromosome* createRandomChromosome(const int bitCount);
    static Chromosome* createZeroChromosome(const int bitCount);
    int getBitCount() const;
    int getDecimalRepresentation() const;
    void mutateRandomBit();
    bool mutateBit(const int bitNumber);
    std::string toString() const;
private:
    std::vector<bool> bits;
    Chromosome(const int bitCount);
    Chromosome(const std::vector<bool> bits);
    void randomizeBits();
};


#endif // CHROMOSOME_H
