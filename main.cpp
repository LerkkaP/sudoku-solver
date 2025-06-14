#include <iostream>

void printGrid(const int (&grid)[9][9]);
bool isValidRow(int grid[9][9], int row, int col);
bool isValidColumn(int grid[9][9], int row, int col);
bool isValidSquare(int grid[9][9], int row, int col);

int main()
{
    int sudokuGrid[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 9, 4, 5, 6, 7, 8, 9},
        {9, 8, 7, 4, 5, 6, 7, 8, 9},
        {4, 2, 3, 4, 5, 6, 7, 8, 9},
        {5, 2, 3, 2, 2, 3, 7, 8, 9},
        {6, 2, 3, 4, 5, 6, 7, 8, 9},
        {7, 2, 3, 7, 8, 9, 7, 8, 9},
        {8, 2, 3, 4, 5, 6, 7, 8, 9},
        {9, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    printGrid(sudokuGrid);
    return 0;
}

// checks that the row is valid according to the constraints
bool isValidRow(int grid[9][9], int row, int col) 
{
    int cell {grid[row][col]};

    for (int j = 0; j < col; j++) {
        if (grid[row][j] == cell) {
            return false;
        }
    }
    return true;
}

// checks that the column is valid according to the constraints
bool isValidColumn(int grid[9][9], int row, int col)
{
    int cell {grid[row][col]};

    for (int i = 0; i < row; i++) {
        if (grid[i][col] == cell) {
            return false;
        }
    }
    return true;
}

// checks that the square is valid according to the constraints
bool isValidSquare(int grid[9][9], int row, int col)
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

void printGrid(const int (&grid)[9][9])
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
}


