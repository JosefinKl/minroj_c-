
#include "game.h"
#include "mine.h"
#include <iostream>
using namespace std;


// Implementera konstruktorn
Game::Game() : matrix(std::make_unique<Matrix>()) {
    // Initiera saker här om det behövs
}

// Implementera play-funktionen
void Game::play() {
    Cell cell(" "); 
    matrix->setCell(0, 0, cell);
    matrix->display();

    while(true){
        std::cout << "Vill du spela minröj? (Y/N) ";
        std::string text;
        std::cin >> text;

       
        if (text == "y" || text == "Y") {
            std::cout << "du skrev y" << std::endl;
            Mine mine;
            mine.start_mine();

        }else if (text == "n" || text == "N") {
            return;
        }else{
            std::cout << "Fel input, välj Y eller N";
            
        }

    }
   
}

