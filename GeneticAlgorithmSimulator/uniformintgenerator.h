#ifndef UNIFORMINTGENERATOR_H
#define UNIFORMINTGENERATOR_H
#include <random>

class UniformIntGenerator
{
public:
    static UniformIntGenerator& instance();
    int generate(const int lowerBound, const int upperBound);
private:
    std::mt19937 generator;
    std::uniform_int_distribution<> dis;

    UniformIntGenerator();
    UniformIntGenerator(const UniformIntGenerator &);
    void operator=(const UniformIntGenerator &);
};

#endif // UNIFORMINTGENERATOR_H
