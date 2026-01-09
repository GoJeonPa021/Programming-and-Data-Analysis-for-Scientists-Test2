#include <iostream>
#include "System.h"
#include "MonteCarlo.h"

int main()
{
    System system(100);         // Vector with 100 entries
    MonteCarlo mc(system, 0.5); // Beta = 0.5

    // Repeat steps 3-5 sufficiently (e.g., 10,000 iterations)
    mc.runSimulation(10000, 0.5);

    // Display final results
    std::cout << "Final Energy: " << system.calculateEnergy() << std::endl;
    std::cout << "Final Magnetization: " << system.calculateMagnetization() << std::endl;

    return 0;
}
