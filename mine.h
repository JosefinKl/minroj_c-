#ifndef MINE_H
#define MINE_H

#include <variant>
#include <string>
#include "matrix.h"

class Mine {
    private:
    Matrix matrix;

    public:
    void start_mine(); 
    const Matrix& getMatrix() const { return matrix; }
};

#endif