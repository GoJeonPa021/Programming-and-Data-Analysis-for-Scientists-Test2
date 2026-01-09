#include "MonteCarlo.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

MonteCarlo::MonteCarlo(System &sys, double betaValue)
    : system(sys), beta(betaValue) {}

// Calculate ∆E based on nearest neighbors
double MonteCarlo::calculateDeltaE(int index)
{
    const auto &state = system.getState();
    int spin = state[index];

    // Nearest neighbors with periodic boundary conditions
    int leftNeighbor = (index == 0) ? state[state.size() - 1] : state[index - 1];
    int rightNeighbor = (index == state.size() - 1) ? state[0] : state[index + 1];

    // ∆E Calculation
    return 2 * spin * (leftNeighbor + rightNeighbor);
}

// Compute Probability P
double MonteCarlo::calculateAcceptanceProbability(double deltaE, double beta)
{
    double P = exp(-beta * deltaE);
    return (P > 1.0) ? 1.0 : P;
}

// Monte Carlo Simulation Process
void MonteCarlo::runSimulation(int iterations, double beta)
{
    for (int i = 0; i < iterations; ++i)
    {
        int index = rand() % system.getState().size(); // Randomly select site
        double deltaE = calculateDeltaE(index);

        double P = calculateAcceptanceProbability(deltaE, beta);

        // Generate random number and compare
        double randomValue = (double)rand() / RAND_MAX;

        // Accept or reject move
        if (randomValue < P)
        {
            int newValue = -system.getState()[index]; // Flip the spin
            system.updateState(index, newValue);
        }

        if (i % 1000 == 0)
        {
            std::cout << "Iteration " << i << " | Energy: " << system.calculateEnergy() << '\n';
        }
    }
}