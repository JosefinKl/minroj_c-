#ifndef MINROJ_GAME_H
#define MINROJ_GAME_H

#include <memory>
#include "matrix.h"

class Game {
private:
    std::unique_ptr<Matrix> matrix;

public:
    Game(); // Deklaration av konstruktorn
    void play(); // Deklaration av play-funktionen
    
};

#endif