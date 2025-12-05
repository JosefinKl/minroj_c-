#ifndef MATRIX_H
#define MATRIX_H

#include "cell.h"
#include <memory>

class Matrix {
private:
    
    std::unique_ptr<std::unique_ptr<Cell[]>[]> grid;

public:
    Matrix();

    void setCell(int row, int col, const Cell& cell);
    const Cell& getCell(int row, int col) const;

    void display() const;
    static const int size = 6;
};




#endif