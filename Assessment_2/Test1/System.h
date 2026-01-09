#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector> // Using vector instead of array

class System
{
private:
    std::vector<int> state; // Vector to hold system state (100 entries)
    double energy;

public:
    System(int size = 100); // Default system size = 100
    double calculateEnergy();
    int calculateMagnetization();
    void updateState(int index, int newValue);
    const std::vector<int> &getState() const;
};

#endif // SYSTEM_H
