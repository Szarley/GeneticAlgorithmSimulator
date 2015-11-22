#include "chromosome.h"
Chromosome::Chromosome(const int bitCount)
    :bits(bitCount,false)
{

}

Chromosome* Chromosome::createNullChromosome(const int bitCount)
{
    return new Chromosome(bitCount);
}

Chromosome* Chromosome::createRandomChromosome(const int bitCount)
{
    Chromosome* chromosome = new Chromosome(bitCount);
    chromosome->randomizeBits();
    return chromosome;
}

void Chromosome::randomizeBits()
{
    for(auto && bit : bits)
    {
        if(UniformIntGenerator::instance().generate(0,1))
            bit = !bit;
    }
}

int Chromosome::getBitCount() const
{
    return bits.size();
}

int Chromosome::getDecimalRepresentation() const
{
    int power = 0;
    int result = 0;
    for(auto bit : bits)
    {
        result += (bit ? std::pow(2, power++) : 0);
    }
    return result;
}

std::string Chromosome::toString() const
{
    std::string result = "";
    for(int i = bits.size() - 1 ; i >=0 ; --i)
    {
        result+= bits[i] ? "1" : "0";
    }
    return result;
}

bool Chromosome::mutateBit(const int bitNumber)
{
    if(bitNumber < 0 || bitNumber >= getBitCount())
        return false;

    bits.at(bitNumber) = !bits.at(bitNumber);
    return true;
}

void Chromosome::mutateRandomBit()
{
    int bit = UniformIntGenerator::instance().generate(0 , bits.size() - 1);
    bits[bit] = !bits[bit];
}
