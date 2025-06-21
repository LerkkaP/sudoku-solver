#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <array>

bool isValidRow(const std::array<std::array<int, 9>, 9> &grid, int row, int col, int num);
bool isValidColumn(const std::array<std::array<int, 9>, 9> &grid, int row, int col, int num);
bool isValidSquare(const std::array<std::array<int, 9>, 9> &grid, int row, int col, int num);
bool isValid(const std::array<std::array<int, 9>, 9> &grid, int row, int col, int num);

#endif