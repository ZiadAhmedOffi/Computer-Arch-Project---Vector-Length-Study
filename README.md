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

