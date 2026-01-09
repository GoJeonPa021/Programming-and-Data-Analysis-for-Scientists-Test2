#include "System.h"
#include <cstdlib> // For rand()

System::System(int size) : state(size), energy(0.0)
{
    for (int i = 0; i < size; ++i)
    {
        state[i] = (rand() % 2 == 0) ? 1 : -1; // Randomly assign +1 or -1
    }
    calculateEnergy();
}

// Energy Calculation using Nearest-Neighbor Interaction
double System::calculateEnergy()
{
    energy = 0.0;
    for (size_t i = 0; i < state.size() - 1; ++i)
    {
        energy -= state[i] * state[i + 1]; // Neighbor interaction
    }
    return energy;
}

int System::calculateMagnetization()
{
    int magnetization = 0;
    for (int spin : state)
    {
        magnetization += spin; // Sum of all spin values
    }
    return magnetization;
}

// Update state value
void System::updateState(int index, int newValue)
{
    state[index] = newValue;
    calculateEnergy(); // Recalculate energy after change
}

// Return the state vector
const std::vector<int> &System::getState() const
{
    return state;
}
