
#include "game.h"
#include "mine.h"
#include <iostream>
using namespace std;


// Implementera konstruktorn
Game::Game() : matrix_show(std::make_unique<Matrix>()) {
    // Initiera saker här om det behövs
}


void Game::play() {
    Cell cell(" "); 
    matrix_show->setCell(0, 0, cell);
    matrix_show->display();

    while(true){
        std::cout << "Vill du spela minröj? (Y/N) ";
        std::string text;
        std::cin >> text;

       
        if (text == "y" || text == "Y") {
            std::cout << "du skrev y" << std::endl;
            Mine mine;
            mine.start_mine();

            while(true){
                std::cout << "Välj en ruta (skriv koordinater '(x,y)' eller 'Avsluta')";
                std::string text;
                std::cin >> text;

                //spelplanen är 6x6 alltså ska inputen vara 5 tecken långt, fixa om tid finns så det ändras ifall storleken på minfältet ändras
                if(text.length() == 5 && text[0] == '(' && text[2] == ',' && text[4] == ')'){
                    int x = text[1] - '0'; // konvertera char '0'-'9' till int
                    int y = text[3] - '0';
                    std::cout << "Du valde ruta (" << x << "," << y << ")\n";
                    const Cell& c = mine.getMatrix().getCell(x, y);  //få värde från game matrisen
                    matrix_show->setCell(x, y, c);
                    matrix_show->display();

                    if (auto v = std::get_if<std::string>(&c.value)) {
                        if (*v == "m") {
                            std::cout << "Du träffade en mina, Game over";
                            return;
                        }
                    }
                    

                }else if(text == "Avsluta"){
                    return;
                }else{
                std::cout << "Fel input, Välj en ruta (skriv koordinater '(x,y)')";
                
                }

                
            }


        }else if (text == "n" || text == "N") {
            return;
        }else{
            std::cout << "Fel input, välj Y eller N";
            
        }

    }
   
}

