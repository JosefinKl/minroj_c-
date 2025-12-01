#ifndef MATRIX_H
#define MATRIX_H

#include "cell.h"
#include <memory>

class Matrix {
private:
    static const int size = 6;
    std::unique_ptr<std::unique_ptr<Cell[]>[]> grid;

public:
    Matrix();

    void setCell(int row, int col, const Cell& cell);
    void display() const;
};




#endif