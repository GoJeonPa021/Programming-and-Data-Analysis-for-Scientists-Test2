#include "System_inv.h"
#include "Monte_inv.h"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time()
#include <fstream> // For writing results to file
#include <vector>  // For storing multiple configurations

int main()
{
    srand(static_cast<unsigned>(time(nullptr))); // Seed random number generator

    const int gridSize = 100;
    const double beta = 0.5;  // Fixed beta value
    const int iterations = 100000;
    const int numConfigurations = 20;  // Number of configurations for averaging

    // Create a CSV file to store results
    std::ofstream resultsFile("ising_fixed_beta_results.csv");
    resultsFile << "Configuration,Energy,Magnetization\n";

    std::vector<double> energyValues;
    std::vector<int> magnetizationValues;

    for (int config = 0; config < numConfigurations; ++config)
    {
        System system(gridSize);
        MonteCarlo monteCarlo(system, beta);

        monteCarlo.runSimulation(iterations, beta);

        double energy = system.calculateEnergy();
        int magnetization = system.calculateMagnetization();

        energyValues.push_back(energy);
        magnetizationValues.push_back(magnetization);

        resultsFile << config + 1 << "," << energy << "," << magnetization << "\n";
        std::cout << "Config " << config + 1
                  << " | Energy: " << energy
                  << " | Magnetization: " << magnetization << '\n';
    }

    resultsFile.close();
    std::cout << "\nResults saved to 'ising_fixed_beta_results.csv'\n";

    return 0;
}
