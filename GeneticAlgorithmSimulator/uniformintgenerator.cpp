#include "uniformintgenerator.h"

UniformIntGenerator::UniformIntGenerator()
    : generator(std::random_device()()),dis(0,1)
{

}
UniformIntGenerator & UniformIntGenerator::instance()
{
    static UniformIntGenerator instance;
    return instance;
}
/**
 * @brief Returns a number between specified bounds.
 * Ifnbounds are changed from the last time, the new distribution is created.
 */
int UniformIntGenerator::generate(const int lowerBound, const int upperBound)
{
    if(dis.a() != lowerBound || dis.b() != upperBound)
        dis = std::uniform_int_distribution<>(lowerBound,upperBound);

    return dis(generator);
}

