# Sudoku Solver

A simple C++ command-line program that solves a given Sudoku puzzle using backtracking and prints the solution to the console.

## Features
- Uses backtracking algorithm to find a valid Sudoku solution.
- Accepts input as a 9×9 grid where each cell is an integer from 0 to 9; zeros indicate empty cells.
- Outputs the completed Sudoku grid in a readable format.

## Prerequisites

- C++ compiler with C++17 support

## Build Instructions

1. Clone the repo:

    ```bash
    git clone https://github.com/LerkkaP/sudoku-solver
    ```

2. Navigate to project root

3. Build the project (g++):

    ```bash
    g++ -Iinclude src/*.cpp -o sudoku-solver
    ```

## Run the project

From the project root run:

```bash
./sudoku-solver
