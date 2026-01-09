#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>

class System
{
private:
    std::vector<std::vector<int>> state; // 2D Grid
    double energy;

public:
    System(int size = 100); // Default system size = 100x100
    double calculateEnergy();
    int calculateMagnetization();
    void updateState(int x, int y, int newValue);
    const std::vector<std::vector<int>> &getState() const;
};

#endif // SYSTEM_H
