#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <array>

bool isValidRow(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidColumn(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValidSquare(const std::array<std::array<int, 9>, 9> &grid, int row, int col);
bool isValid(const std::array<std::array<int, 9>, 9> &grid, int row, int col);

#endif