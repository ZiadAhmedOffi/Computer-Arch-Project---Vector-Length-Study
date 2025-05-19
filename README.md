# 🧠 Vector Length and Performance in Vector Architecture

## 📚 Project Overview

This project investigates the **impact of vector length on the performance of a vector architecture**, specifically within the RISC-V ecosystem. By varying the vector length and analyzing execution performance, the study aims to provide insights into the trade-offs and efficiency of vector-based computation.

## 🔧 Tools and Technologies Used

- **RISC-V GNU Toolchain**  
  Used to compile vector-enabled C programs targeting the RISC-V architecture.

- **Spike RISC-V Simulator**  
  A functional simulator for RISC-V ISA, used to run and test vector programs.

- **Proxy Kernel (PK)**  
  Provides minimal OS functionality for bare-metal execution and interaction with the host during simulation.

## Environment Setup for RISC-V Vector Architecture Project

### Prerequisites

- Ubuntu 20.04/22.04 (Recommended)
- ~20GB disk space
- GCC, Make, Autoconf, and other build essentials
- Git

Install build tools:
```bash
sudo apt update
sudo apt install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev
```
### 1. RISC-V GNU Toolchain (with V-extension support)
Clone and build the toolchain with V-extension support:
```bash
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain

# Configure with RVV support (0.7.1 is a stable vector spec version)
./configure --prefix=/opt/riscv --with-arch=rv64gcv --with-abi=lp64d
make -j$(nproc)
```
Then add to your `~/.bashrc`:
```bash
export PATH=/opt/riscv/bin:$PATH
```
To verify installation use the following command:
```bash
riscv64-unknown-elf-gcc --version
```
### 2.Spike RISC-V Simulator
Build Spike with vector extension support:
```bash
git clone https://github.com/riscv-software-src/riscv-isa-sim
cd riscv-isa-sim
mkdir build
cd build
../configure --prefix=/opt/riscv --enable-vector
make -j$(nproc)
sudo make install
```
Verify installation:
```bash
spike --version
```
### 3. RISC-V Proxy Kernel (PK)
Build the proxy kernel for Spike:
```bash
git clone https://github.com/riscv-software-src/riscv-pk
cd riscv-pk
mkdir build
cd build
../configure --prefix=/opt/riscv --host=riscv64-unknown-elf
make -j$(nproc)
sudo make install
```
Now the environment should be ready to run the code and object files in the repo.
## 🧪 Methodology

1. Vector programs were written in C with vector intrinsics.
2. Multiple configurations with varying vector lengths were compiled using the RISC-V GNU Toolchain.
3. The compiled binaries were executed using the Spike simulator with Proxy Kernel support.
4. Performance data (e.g., cycle counts, instruction counts) was collected and compared across different vector lengths.

## 📈 Goals

- Measure performance trends across different vector lengths.
- Understand the scalability of vector instructions in RISC-V.
- Analyze architectural behavior in response to vector configuration changes.

## 👨‍💻 Contributors

- *Ahmed Osama Ibrahim*  
- *Moamen Mohamed Ahmed*  
- *Youseff Taha Saad*
- *Zeyad Hashem Mohamed*
- *Ziad Ahmed Mohamed*

## 🧑‍🏫 Supervisor

- *Proffessor Mai Mohamed*

## Organization

- *Benha University - Shoubra College of Engineering*

## 📂 Repository Contents

- Report – Complete report for the project  
- VectorTest.c – Source code file (C Programming Language)
- VectorTest – Resulting object file from the comopilation process

## Build Instructions

- Command used for  compilation is: `riscv64-unknown-elf-gcc -march=rv64gcv -mabi=lp64 -o OutputFile VectorTest.c`
- Command used to run the object file on the Spike simulator is: `spike --isa=rv64gcv /your/path/to/pk VectorTest`

---

