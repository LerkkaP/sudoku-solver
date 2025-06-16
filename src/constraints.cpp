#include <array>
#include "constraints.h"

// checks that the row is valid according to the constraints
bool isValidRow(const std::array<std::array<int, 9>, 9> &grid, int row, int col) 
{
    int cell {grid[row][col]};

    for (int j = 0; j < 9; j++) {
        // if the column is same as the cell we are comparing to, we skip
        if (j == col) {
            continue;
        }
        if (grid[row][j] == cell) {
            return false;
        }
    }
    return true;
}

// checks that the column is valid according to the constraints
bool isValidColumn(const std::array<std::array<int, 9>, 9> &grid, int row, int col)
{
    int cell {grid[row][col]};

    for (int i = 0; i < 9; i++) {
        // if the row is same as the cell we are comparing to, we skip
        if (i == row) {
            continue;
        }
        if (grid[i][col] == cell) {
            return false;
        }
    }
    return true;
}

// checks that the square is valid according to the constraints
bool isValidSquare(const std::array<std::array<int, 9>, 9> &grid, int row, int col)
{
    int cell {grid[row][col]};

    int squareStartRow { (row / 3) * 3 };
    int squareEndRow { squareStartRow + 2 };

    int squareStartColumn { (col / 3) * 3 };
    int squareEndColumn { squareStartColumn + 2 };

    for (int i = squareStartRow; i <= squareEndRow; i++) {
        for (int j = squareStartColumn; j <= squareEndColumn; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (grid[i][j] == cell) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(const std::array<std::array<int, 9>, 9> &grid, int row, int col) {
    if (isValidRow(grid, row, col) && isValidColumn(grid, row, col) && isValidSquare(grid, row, col)) {
        return true;
    }
    return false;
}
