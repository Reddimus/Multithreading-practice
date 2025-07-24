# Multithreading Practice

A C++ project demonstrating thread synchronization and algorithm execution order using mutexes and condition variables.

## Overview

This project implements a thread synchronization mechanism that ensures three algorithms (A1, A2, A3) display their output in a specific order (A1 → A2 → A3) regardless of which algorithm finishes execution first. All algorithms start their computational work immediately when threads are created, but their output is synchronized to maintain the correct display order.

The algorithms simulate different computational complexities:

- **Algorithm 1 (A1)**: O(n³) complexity - Triple nested loops
- **Algorithm 2 (A2)**: O(n²) complexity - Double nested loops
- **Algorithm 3 (A3)**: O(n) complexity - Simple loop

## Features

- **Concurrent Execution**: All algorithms run simultaneously when threads are created
- **Output Synchronization**: Uses `std::mutex` and `std::condition_variable` to coordinate output display
- **Display Order Control**: Ensures algorithm results always display in the order A1 → A2 → A3
- **Flexible Input**: Accepts algorithms in any order but maintains output sequence
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

**Important**: All algorithms start executing immediately when their threads are created. The synchronization only controls when their output is displayed, ensuring the results appear in the correct order (A1 → A2 → A3) regardless of which algorithm finishes first.

The `ThreadsPractice` class uses a state machine with three stages for output synchronization:

1. **First**: Only A1's output can be displayed
2. **Second**: A1's output completed, A2's output can be displayed
3. **Third**: A1 and A2's output completed, A3's output can be displayed

### Synchronization Mechanism

- **Immediate Execution**: All algorithms begin their computational work as soon as their threads are created
- **Output Synchronization**: Only the display of results is synchronized using thread coordination
- **Mutex**: Protects shared state and ensures thread-safe access to output control
- **Condition Variable**: Blocks threads from displaying output until their turn
- **Stage Enum**: Tracks which algorithm's output can currently be displayed

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

## Execution Model

This project demonstrates **output synchronization** rather than execution synchronization:

1. **Thread Creation**: When `in_order()` is called, all threads are created immediately
2. **Concurrent Execution**: All algorithms (A1, A2, A3) begin their computational work simultaneously
3. **Completion Timing**: Algorithms may finish in any order depending on their complexity and system load
4. **Output Synchronization**: Results are displayed in the fixed order A1 → A2 → A3, regardless of completion order

**Example Timeline**:

```text
Time →  [Thread Creation] → [Concurrent Execution] → [Synchronized Output]
T1:     A1, A2, A3         A1: ████████████████      A1 output displayed
T2:     threads created    A2: ██████████            (waits for A1)
T3:                        A3: ████                  A2 output displayed
T4:                        (all may finish          A3 output displayed
T5:                         in any order)           (waits for A2)
```

## Key Classes and Functions

### `ThreadsPractice` Class

- `first()`: Displays algorithm 1 output and signals completion
- `second()`: Waits for A1 output, displays algorithm 2 output, signals completion  
- `third()`: Waits for A1 and A2 output, displays algorithm 3 output

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
