#include <iostream>
#include <array>

void printGrid(const std::array<std::array<int, 9>, 9> &grid);
bool isValidRow(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidColumn(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidSquare(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValid(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
void solveSudoku(std::array<std::array<int, 9>, 9> &grid);

int main()
{
    std::array<std::array<int, 9>, 9> sudokuGrid = {{
        {{0, 0, 2, 0, 1, 5, 0, 7, 8}},
        {{1, 8, 0, 0, 6, 3, 4, 0, 0}},
        {{0, 0, 4, 0, 2, 0, 5, 6, 1}},
        {{0, 9, 6, 0, 0, 7, 0, 3, 0}},
        {{0, 1, 0, 3, 0, 6, 0, 0, 5}},
        {{0, 0, 3, 2, 0, 4, 0, 9, 6}},
        {{0, 3, 0, 0, 0, 0, 0, 0, 0}},
        {{6, 4, 9, 8, 3, 0, 2, 0, 7}},
        {{0, 0, 7, 0, 0, 0, 0, 1, 0}}
    }};
    solveSudoku(sudokuGrid);
    printGrid(sudokuGrid);
    return 0;
}

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

bool isValid(std::array<std::array<int, 9>, 9> &grid, int row, int col) {
    if (isValidRow(grid, row, col) && isValidColumn(grid, row, col) && isValidSquare(grid, row, col)) {
        return true;
    }
    return false;
}

void solveSudoku(std::array<std::array<int, 9>, 9> &grid)
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

}

void printGrid(const std::array<std::array<int, 9>, 9> &grid)
{
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            std::cout << "\n";
            std::cout << "---------------------";
            std::cout << "\n";
        } else {
            std::cout << "\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                std::cout << "| ";
            }
            std::cout << grid[i][j];
            std::cout << " ";
        }
    }
    std::cout << '\n';
}


