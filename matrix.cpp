#include "matrix.h"
#include <iostream>

Matrix::Matrix() {
    grid = std::make_unique<std::unique_ptr<Cell[]>[]>(size);
    for (int i = 0; i < size; ++i) {
        grid[i] = std::make_unique<Cell[]>(size);
    }
}

void Matrix::setCell(int row, int col, const Cell& cell) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        grid[row][col] = cell;
    }
}

const Cell& Matrix::getCell(int row, int col) const {
    return grid[row][col];
}


void Matrix::display() const {
    // Skriv ut den övre kanten
    std::cout << "+";
    for (int i = 0; i < size; ++i) {
        std::cout << "---+";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        // Skriv ut vänsterkanten för raden
        std::cout << "|";
        for (int j = 0; j < size; ++j) {
            std::visit([](auto&& arg) { std::cout << " " << arg << " "; }, grid[i][j].value);
            // Skriv ut högerkanten för varje cell
            std::cout << "|";
        }
        std::cout << std::endl;

        // Skriv ut den nedre kanten för raden
        std::cout << "+";
        for (int j = 0; j < size; ++j) {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
}