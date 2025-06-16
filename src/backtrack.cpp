#include <array>
#include "backtrack.h"
#include "constraints.h"

bool backtrack(std::array<std::array<int, 9>, 9> &grid)
{
    /* PSEUDOCODE

    1. Place digit 1 in the first cell containing 0
    2. If the digit satisfies the constraints:
           advance to next 0 cell and jump to 1.
       else:
           increment the value by +1
    3. If no number between 1-9 is allowed in a cell:
           leave the cell 0 and backtrack to last cell then increment by +1.
    
    */
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int i = 1; i <= 9; i++) {
                    grid[row][col] = i;
                    if (isValid(grid, row, col) && backtrack(grid)) {
                        return true;
                    }
                    grid[row][col] = 0;

                }
                // no number between 1-9 fits the cell
                return false;
            }
        }
    }
    return true;
}