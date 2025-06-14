#include <iostream>
#include <array>

void printGrid(const std::array<std::array<int, 9>, 9> &grid);
bool isValidRow(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidColumn(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidSquare(const std::array<std::array<int, 9>, 9> &grid, int row, int col);

int main()
{
    std::array<std::array<int, 9>, 9> sudokuGrid = {{
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}}
    }};
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


