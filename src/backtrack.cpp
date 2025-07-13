#include <array>
#include "backtrack.h"
#include "constraints.h"
#include "grid.h"
#include "constants.h"

bool backtrack(Grid &grid)
{   
    for (int row = 0; row < Constants::gridSize; ++row) {
        for (int col = 0; col < Constants::gridSize; ++col) {
            // skip non-empty cell
            if (grid[row][col] != 0) {
                continue;
            }
            for (int num = 1; num <= 9; ++num) {
                if (isValid(grid, row, col, num)) {
                    grid[row][col] = num;
                    if (backtrack(grid)) {
                        return true;
                    }
                    grid[row][col] = 0;
                }
            }
            // no number between 1-9 fits the cell
            return false;
        }
    }
    return true;
}