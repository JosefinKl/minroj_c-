
#include "game.h"

// Implementera konstruktorn
Game::Game() : matrix(std::make_unique<Matrix>()) {
    // Initiera saker här om det behövs
}

// Implementera play-funktionen
void Game::play() {
    Cell cell(" "); 
    matrix->setCell(0, 0, cell);
    matrix->display();
}