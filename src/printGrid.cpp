#include "printGrid.h"
#include <iostream>

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