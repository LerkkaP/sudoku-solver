#include <array>
#include "constraints.h"
#include "grid.h"

namespace {
    bool isValidRow(const Grid &grid, int row, int col, int num) 
    {
        for (int j = 0; j < 9; ++j) {
            // if the column is same as the cell we are comparing to, skip
            if (j == col) {
                continue;
            }
            if (grid[row][j] == num) {
                return false;
            }
        }
        return true;
    }

    bool isValidColumn(const Grid &grid, int row, int col, int num)
    {
        for (int i = 0; i < 9; ++i) {
            // if the row is same as the cell we are comparing to, we skip
            if (i == row) {
                continue;
            }
            if (grid[i][col] == num) {
                return false;
            }
        }
        return true;
    }

    bool isValidSquare(const Grid &grid, int row, int col, int num)
    {
        int squareStartRow { (row / 3) * 3 };
        int squareEndRow { squareStartRow + 2 };

        int squareStartColumn { (col / 3) * 3 };
        int squareEndColumn { squareStartColumn + 2 };

        for (int i = squareStartRow; i <= squareEndRow; ++i) {
            for (int j = squareStartColumn; j <= squareEndColumn; ++j) {
                if (i == row && j == col) {
                    continue;
                }
                if (grid[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
}

bool isValid(const Grid &grid, int row, int col, int num) {

    return isValidRow(grid, row, col, num) &&
           isValidColumn(grid, row, col, num) &&
           isValidSquare(grid, row, col, num);
}
