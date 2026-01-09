# Ising Model Simulation in C++

This project implements a **2D Ising Model** using **Monte Carlo simulation** with the **Metropolis algorithm**. The code models magnetic systems on a 100x100 Cartesian grid, tracking energy and magnetization to study phase transitions and statistical properties.

When processing, the file name contain "inv" is the file for this investigation.
---

## 📋 Features
- ✅ Implements the **2D Ising Model** with periodic boundary conditions.
- ✅ Uses the **Metropolis algorithm** to simulate the system's evolution.
- ✅ Supports both **fixed β** and **variable β** scenarios.
- ✅ Tracks and visualizes **Energy** and **Magnetization** across multiple configurations.
- ✅ Provides **3D visualization** for better insights into system behavior.

---

## 🛠️ Installation
### **1. Clone the Repository**
```bash
git clone <repository-url>
cd <repository-folder>
```

### **2. Compile the Code**
For fixed β:
g++ main_inv_fixb.cpp System_inv.cpp Monte_inv.cpp -o test_fix


For unfixed:
g++ main_inv_unfix.cpp System_inv.cpp Monte_inv.cpp -o test_unfix



### **3. Run the Simulation**
For fixed β:
./test_fix

For unfixed:
./test_unfix