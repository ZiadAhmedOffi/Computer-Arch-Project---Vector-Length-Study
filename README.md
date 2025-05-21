# 🚀 Simulation of Vector Length and Performance in RISC-V Architecture

A simulation project that models and analyzes **the impact of vector length on the performance of vector-based computation** within the RISC-V ecosystem. This project explores how varying vector lengths affect the performance of programs using RISC-V vector instructions.

---

## 📚 Table of Contents

- [💡 Acknowledgments](#-acknowledgments)
- [🔍 Problem Description](#-problem-description)
- [🧰 Prerequisites](#-prerequisites)
- [🖥️ Environment Setup](#-environment-setup)
- [✏️ Simulation Code Implementation](#-simulation-code-implementation)
- [🏁 Compile and Run](#-compile-and-run)
- [🧪 Testing and Validation](#-testing-and-validation)
- [🧩 Challenges Encountered](#-challenges-encountered)
- [🛠️ Handling Challenges](#-handling-challenges)
- [📝 Conclusion](#-conclusion)
- [📌 References](#-references)
- [👥 Contributors](#-contributors)

---

## 💡 Acknowledgments

- Supervised by *Professor Mai Mohamed* at *Benha University - Shoubra College of Engineering*.

## 🔍 Problem Description

This project investigates the performance impact of varying vector lengths in the RISC-V vector architecture. By compiling and simulating C programs that use vector instructions, we assess how vector configuration influences execution efficiency.

## 🧰 Prerequisites

- Ubuntu 20.04/22.04 (Recommended)
- ~20GB disk space
- GCC, Make, Autoconf, and other build essentials
- Git

Install build tools:

```bash
sudo apt update
sudo apt install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev
```

## 🖥️ Environment Setup

### 1. RISC-V GNU Toolchain (with V-extension support)

```bash
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv --with-arch=rv64gcv --with-abi=lp64d
make -j$(nproc)
echo 'export PATH=/opt/riscv/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
```

### 2. Spike RISC-V Simulator

```bash
git clone https://github.com/riscv-software-src/riscv-isa-sim
cd riscv-isa-sim
mkdir build && cd build
../configure --prefix=/opt/riscv --enable-vector
make -j$(nproc)
sudo make install
```

### 3. RISC-V Proxy Kernel (PK)

```bash
git clone https://github.com/riscv-software-src/riscv-pk
cd riscv-pk
mkdir build && cd build
../configure --prefix=/opt/riscv --host=riscv64-unknown-elf
make -j$(nproc)
sudo make install
```

## ✏️ Simulation Code Implementation

The main simulation code is written in C using RISC-V vector intrinsics. It varies vector lengths and measures corresponding performance metrics.

## 🏁 Compile and Run

Compile:

```bash
riscv64-unknown-elf-gcc -march=rv64gcv -mabi=lp64 -o VectorTest VectorTest.c
```

Run:

```bash
spike --isa=rv64gcv /opt/riscv/bin/pk VectorTest
```

## 🧪 Testing and Validation

- Programs were compiled for various vector lengths.
- Execution was tested with Spike simulator.
- Performance metrics such as cycle counts and instruction counts were recorded and compared.

## 🧩 Challenges Encountered

- Ensuring compatibility across various vector lengths.
- Configuring toolchain and simulator for vector extension.
- Limited documentation on specific vector behaviors.

## 🛠️ Handling Challenges

- Referred to RISC-V vector specification v0.7.1 and GitHub issues.
- Manually traced instruction behavior through Spike logs.
- Incrementally built environment to isolate tool-specific errors.

## 📝 Conclusion

The experiment demonstrated clear correlations between vector length and program execution efficiency. Longer vector lengths generally improve performance up to hardware limits, but not without trade-offs.

## 📌 References

- RISC-V Vector Extension Spec v0.7.1
- RISC-V GNU Toolchain Documentation
- Spike ISA Simulator GitHub Repo

## 👥 Contributors

- Ahmed Osama Ibrahim
- Moamen Mohamed Ahmed
- Youseff Taha Saad
- Zeyad Hashem Mohamed
- Ziad Ahmed Mohamed
