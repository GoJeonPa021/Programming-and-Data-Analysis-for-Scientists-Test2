#include "Monte_inv.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

MonteCarlo::MonteCarlo(System &sys, double betaValue)
    : system(sys), beta(betaValue) {}

// Calculate ∆E based on 2D nearest neighbors
double MonteCarlo::calculateDeltaE(int x, int y)
{
    const auto &state = system.getState();
    int size = state.size();
    int spin = state[x][y];

    // Nearest-neighbors with periodic boundary conditions
    int leftNeighbor  = state[(x - 1 + size) % size][y];
    int rightNeighbor = state[(x + 1) % size][y];
    int topNeighbor   = state[x][(y - 1 + size) % size];
    int bottomNeighbor = state[x][(y + 1) % size];

    // ∆E Calculation
    return 2 * spin * (leftNeighbor + rightNeighbor + topNeighbor + bottomNeighbor);
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
        int x = rand() % system.getState().size();
        int y = rand() % system.getState()[0].size(); // Random 2D coordinates

        double deltaE = calculateDeltaE(x, y);
        double P = calculateAcceptanceProbability(deltaE, beta);

        // Generate random number and compare
        double randomValue = (double)rand() / RAND_MAX;

        // Accept or reject move
        if (randomValue < P)
        {
            int newValue = -system.getState()[x][y]; // Flip the spin
            system.updateState(x, y, newValue);
        }

        if (i % 1000 == 0)
        {
            std::cout << "Iteration " << i << " | Energy: " << system.calculateEnergy()
                      << " | Magnetization: " << system.calculateMagnetization() << '\n';
        }
    }
}
