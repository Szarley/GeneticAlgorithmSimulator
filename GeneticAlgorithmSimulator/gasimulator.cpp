#include "gasimulator.h"
GASimulator::GASimulator()
{

}

GASimulator & GASimulator::setParameters(const SimulationParameters & parameters)
{
    this->parameters = parameters;
    return *this;
}

SimulationParameters GASimulator::getParameters() const
{
    return parameters;
}
