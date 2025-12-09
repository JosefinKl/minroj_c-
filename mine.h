#ifndef MINE_H
#define MINE_H

#include <variant>
#include <string>
#include "matrix.h"

class Mine {
    private:
    Matrix matrix;
    
    int number_of_nonemine;

    public:
    void start_mine(); 
    const Matrix& getMatrix() const { return matrix; }

    // Getter för att läsa antal minor
    int getNumberOfNoneMines() const { return number_of_nonemine; }
    
};

#endif