# Multithreading Practice

A C++ project demonstrating thread synchronization and algorithm execution order using mutexes and condition variables.

## Overview

This project implements a thread synchronization mechanism that ensures three algorithms (A1, A2, A3) execute in a specific order regardless of the order in which their threads are created. The algorithms simulate different computational complexities:

- **Algorithm 1 (A1)**: O(n) complexity - Simple loop
- **Algorithm 2 (A2)**: O(n²) complexity - Nested loops
- **Algorithm 3 (A3)**: O(n³) complexity - Triple nested loops

## Features

- **Thread Synchronization**: Uses `std::mutex` and `std::condition_variable` to coordinate thread execution
- **Execution Order Control**: Ensures algorithms always execute in the order A1 → A2 → A3
- **Flexible Input**: Accepts algorithms in any order but maintains execution sequence
- **Modern C++**: Written in C++23 with best practices

## Project Structure

```text
Multithreading-practice/
├── src/
│   ├── main.cpp              # Main program with test cases
│   ├── threadspractice.cpp    # Implementation of thread synchronization
│   └── threadspractice.h      # Header file with class definitions
├── bin/                      # Compiled binaries (generated)
├── Makefile                  # Build configuration
└── README.md                 # This file
```

## Building and Running

### Prerequisites

- GCC compiler with C++23 support
- Make utility
- POSIX threads support

### Build

```bash
make
```

### Run

```bash
make run
```

Or run the executable directly:

```bash
./bin/main
```

### Clean

```bash
make clean
```

## How It Works

The `ThreadsPractice` class uses a state machine with three stages:

1. **First**: Only A1 can execute
2. **Second**: A1 completed, A2 can execute
3. **Third**: A1 and A2 completed, A3 can execute

### Synchronization Mechanism

- **Mutex**: Protects shared state and ensures thread-safe access
- **Condition Variable**: Blocks threads until their turn to execute
- **Stage Enum**: Tracks current execution stage

### Example Output

```text
Testing Order
Input: [A1, A2, A3] -> Output: A1 A2 A3 
Input: [A2, A1, A3] -> Output: A1 A2 A3 
Input: [A3, A1, A2] -> Output: A1 A2 A3 
Input: [A2, A3, A1] -> Output: A1 A2 A3 
Input: [A3, A2, A1] -> Output: A1 A2 A3 
Input: [A1, A3, A2] -> Output: A1 A2 A3 
```

## Key Classes and Functions

### `ThreadsPractice` Class

- `first()`: Executes algorithm 1 and signals completion
- `second()`: Waits for A1, executes algorithm 2, signals completion  
- `third()`: Waits for A1 and A2, executes algorithm 3

### Test Functions

- `algorithm1()`, `algorithm2()`, `algorithm3()`: The three algorithms with different complexities
- `ThreadedAlgorithmsTest::in_order()`: Creates threads and ensures proper execution order

## Learning Objectives

This project demonstrates:

- Thread creation and management
- Mutex usage for thread-safe operations
- Condition variables for thread coordination
- Function pointers and lambda expressions
- Modern C++ threading practices

## Compilation Flags

- `-std=c++23`: Use C++23 standard
- `-pthread`: Enable POSIX threading
- `-Wall -Wextra`: Enable comprehensive warnings
