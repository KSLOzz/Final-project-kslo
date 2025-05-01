# Final-project-kslo
PLEASE READ TO AVOID CONFUSION
my final project
kds0090
Kellan Sloan

please be careful when compiling, my computer was having trouble cmpiling so i had to split it into many files in order to make it run fast. please 

On first run, the application will create a default admin user:

Username: admin

Password: 0000

A C++ console application for managing bank accounts and branch staff, with role-based access control.

## Repository Structure
## Prerequisites

- A C++ compiler with C++17 support (e.g. `g++`, `clang++`)
- `make` (optional, for the provided Makefile)

## Building

From the project root:

```bash
# If you have make:
make

# Or compile manually:
g++ -std=c++17 -o teller \
  src/Teller.cpp src/UserManager.cpp src/AuthenticationManager.cpp \
  src/Client.cpp src/ClientManager.cpp src/Account.cpp src/AccountManager.cpp \
  src/PersistenceManager.cpp src/TellerTerminal.cpp src/main.cpp
