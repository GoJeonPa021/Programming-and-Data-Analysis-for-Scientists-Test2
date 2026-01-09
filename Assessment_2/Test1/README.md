# Monte Carlo Simulation - Code Testing Guide

This project implements a Monte Carlo simulation for a one-dimensional chain of 100 interacting atoms. This guide explains the code testing process, ensuring that each function behaves correctly according to the assessment requirements.

---

## Code Testing Overview
The project includes a dedicated `test_cases.cpp` file designed to validate:

1. **System Initialization**
   - Ensures the system correctly initializes with **100 entries**, each with values of either `+1` or `-1`.

2. **Energy Calculation**
   - Confirms the calculated energy follows the defined interaction rules between neighboring sites.

3. **Magnetization Calculation**
   - Verifies the magnetization function correctly computes the net magnetization.

4. **Monte Carlo Simulation Logic**
   - Ensures:
     - Correct calculation of \( \Delta E \) (energy change for spin flips).
     - Proper calculation of acceptance probability \( P = e^{-\beta \Delta E} \).
     - Spin flipping follows the correct acceptance criterion.

5. **Final Configuration Check**
   - Ensures the system stabilizes with reduced energy after sufficient iterations.

---

## Compilation Instructions
To compile the code and run the tests:

1. **Compile the Main Simulation**
```bash
g++ main.cpp MonteCarlo.cpp System.cpp -o monte_carlo_run 
```
2. **Compile the Test Cases**
```bash
g++ test_cases.cpp MonteCarlo.cpp System.cpp -o test_run
```
3. **Compile the Test Cases**
For the main Monte Carlo simulation:
```bash
./monte_carlo_run
```
For the test cases:
```bash
./test_run
```

## Simplified Test Cases
- Introduced smaller systems (3-5 atoms) for easier verification.
- Added tests to verify:
  - Correct calculation of energy for a 3-atom system.
  - Correct ∆E calculation for controlled spin flips.
  - Monte Carlo simulation behavior in smaller systems.

