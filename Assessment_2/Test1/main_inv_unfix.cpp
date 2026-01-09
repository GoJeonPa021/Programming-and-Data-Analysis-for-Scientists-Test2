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
    const int iterations = 100000;
    const int numConfigurations = 10;  // Number of configurations for averaging

    // Create a CSV file to store results
    std::ofstream resultsFile("ising_3D_results.csv");
    resultsFile << "Beta,Configuration,Energy,Magnetization\n";

    for (double beta = 0.1; beta <= 11; beta += 1)  // Iterate over β values
    {
        for (int config = 0; config < numConfigurations; ++config)
        {
            System system(gridSize);
            MonteCarlo monteCarlo(system, beta);

            monteCarlo.runSimulation(iterations, beta);

            double energy = system.calculateEnergy();
            int magnetization = system.calculateMagnetization();

            resultsFile << beta << "," << config + 1 << "," << energy << "," << magnetization << "\n";

            std::cout << "Beta: " << beta
                      << " | Config " << config + 1
                      << " | Energy: " << energy
                      << " | Magnetization: " << magnetization << '\n';
        }
    }

    resultsFile.close();
    std::cout << "\nResults saved to 'ising_3D_results.csv'\n";

    return 0;
}
