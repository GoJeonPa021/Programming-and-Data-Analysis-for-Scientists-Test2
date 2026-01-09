#include <iostream>
#include <cassert>
#include "System.h"
#include "MonteCarlo.h"

void testSystemInitialization() {
    System system(100);  // Initialize with 100 entries
    const auto& state = system.getState();

    assert(state.size() == 100 && "System size should be 100");

    // Verify that all values are either +1 or -1
    for (int spin : state) {
        assert((spin == 1 || spin == -1) && "Spin values should be ±1");
    }

    std::cout << " System Initialization Test Passed!\n";
}

void testEnergyCalculation() {
    System system(100);

    // For controlled testing, override the state
    std::vector<int> controlledState(100, 1);  // All spins are +1
    for (int i = 0; i < 100; ++i) {
        system.updateState(i, controlledState[i]);
    }

    // Energy should be -99 for 100 aligned spins (all +1 or all -1)
    assert(system.calculateEnergy() == -99 && "Energy calculation is incorrect");

    std::cout << " Energy Calculation Test Passed!\n";
}

void testMagnetizationCalculation() {
    System system(100);

    // Controlled test state
    std::vector<int> testState(100, 1);  // All spins = 1
    for (int i = 0; i < 100; ++i) {
        system.updateState(i, testState[i]);
    }

    // Magnetization should be 100 for all +1
    assert(system.calculateMagnetization() == 100 && "Magnetization calculation is incorrect");

    std::cout << " Magnetization Calculation Test Passed!\n";
}

void testMonteCarloSimulation() {
    System system(100);
    MonteCarlo mc(system, 0.5);

    mc.runSimulation(10000, 0.5);

    // Energy should not increase drastically
    double finalEnergy = system.calculateEnergy();
    assert(finalEnergy < 0 && "Energy should tend to decrease over time");

    std::cout << " Monte Carlo Simulation Test Passed!\n";
}

void testSmallSystemEnergy() {
    System system(3);  // Smaller system for easy verification
    system.updateState(0, 1);
    system.updateState(1, -1);
    system.updateState(2, 1);

    assert(system.calculateEnergy() == 2 && "Energy calculation failed for 3-atom system");

    std::cout << " Energy Test for Small System Passed!\n";
}

void testSpinFlipLogic() {
    System system(5);  
    system.updateState(0, 1);
    system.updateState(1, 1);
    system.updateState(2, -1);
    system.updateState(3, -1);
    system.updateState(4, 1);

    MonteCarlo mc(system, 0.5);

    // Select entry 2 (third site) for flipping
    double deltaE = mc.calculateDeltaE(2);

    // Expected ∆E calculation for flipping the site
    assert(deltaE == 0 && "∆E calculation failed for selected site");

    std::cout << "Spin Flip Test for Small System Passed!\n";
}

void testMonteCarloSimulationSmall() {
    System system(5);  
    MonteCarlo mc(system, 0.5);

    mc.runSimulation(5000, 0.5);  // Fewer iterations for quick testing

    double finalEnergy = system.calculateEnergy();
    assert(finalEnergy < 0 && "Energy should tend to decrease over time");

    std::cout << "Monte Carlo Simulation (Small System) Test Passed!\n";
}


int main() {
    testSystemInitialization();
    testEnergyCalculation();
    testMagnetizationCalculation();
    testMonteCarloSimulation();

    testSmallSystemEnergy();
    testSpinFlipLogic();
    testMonteCarloSimulationSmall();

    std::cout << " All Tests Completed Successfully!\n";
    return 0;
}

