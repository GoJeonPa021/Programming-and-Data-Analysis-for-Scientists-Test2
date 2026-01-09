#include "System_inv.h"
#include <cstdlib> // For rand()

System::System(int size) : state(size, std::vector<int>(size)), energy(0.0)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            state[i][j] = (rand() % 2 == 0) ? 1 : -1; // Randomly assign +1 or -1
        }
    }
    calculateEnergy();
}

// Energy Calculation using Nearest-Neighbor Interaction in 2D
double System::calculateEnergy()
{
    energy = 0.0;
    int size = state.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int spin = state[i][j];

            // Nearest-neighbors with periodic boundary conditions
            int leftNeighbor = state[(i - 1 + size) % size][j];
            int rightNeighbor = state[(i + 1) % size][j];
            int topNeighbor = state[i][(j - 1 + size) % size];
            int bottomNeighbor = state[i][(j + 1) % size];

            // Energy calculation
            energy -= spin * (leftNeighbor + rightNeighbor + topNeighbor + bottomNeighbor);
        }
    }

    return energy / 2.0; // Divided by 2 to avoid double counting
}

int System::calculateMagnetization()
{
    int magnetization = 0;
    for (const auto &row : state)
    {
        for (int spin : row)
        {
            magnetization += spin;
        }
    }
    return magnetization;
}

// Update state value
void System::updateState(int x, int y, int newValue)
{
    state[x][y] = newValue;
    calculateEnergy(); // Recalculate energy after change
}

// Return the state vector
const std::vector<std::vector<int>> &System::getState() const
{
    return state;
}
