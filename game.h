#ifndef MINROJ_GAME_H
#define MINROJ_GAME_H


#include <vector>
#include <string>

#include "matrix.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Matrix> matrix;

public:
    Game() : matrix(std::make_unique<Matrix>()) {
        // Du kan initiera saker här om det behövs
    }

    void play() {
        // Använd Matrix-metoder här
        Cell cell; // Anta att du har en konstruktor för Cell
        matrix->setCell(0, 0, cell);
        matrix->display();
    }
};


#endif //MINROJ_GAME_H