#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "System.h"

class MonteCarlo
{
private:
    System &system;
    double beta; // Inverse temperature

public:
    MonteCarlo(System &sys, double betaValue);
    double calculateDeltaE(int index);
    double calculateAcceptanceProbability(double deltaE, double beta);
    void runSimulation(int iterations, double beta);
};

#endif // MONTECARLO_H
