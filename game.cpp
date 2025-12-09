
#include "game.h"
#include "mine.h"
#include "matrix.h"
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
            
            int number_of_cells = Matrix::size * Matrix::size;
            int totalMines = number_of_cells - mine.getNumberOfNoneMines();
            int number_of_nonmines_found = 0;
            
            
                while(true){
                    std::cout << "Välj en ruta (skriv koordinater '(x,y)' eller 'Avsluta')";
                    std::string text;
                    std::cin >> text;

                    //spelplanen är 6x6 alltså ska inputen vara 5 tecken långt, fixa om tid finns så det ändras ifall storleken på minfältet ändras
                    if(text.length() == 5 && text[0] == '(' && text[2] == ',' && text[4] == ')'){

                        //kontrollera så det är siffror inlagda)
                        if (isdigit(text[1]) && isdigit(text[3])) {
                            int x = text[1] - '0'; // konvertera char '0'-'9' till int
                            int y = text[3] - '0';

                            // Kontrollera att koordinaterna ligger inom spelplanen
                            if (x >= 0 && x < 6 && y >= 0 && y < 6) {
                                std::cout << "Du valde ruta (" << x << "," << y << ")\n" << std::endl;
                                const Cell& c = mine.getMatrix().getCell(x, y);  //få värde från game matrisen
                                matrix_show->setCell(x, y, c);
                                matrix_show->display();

                                if (auto v = std::get_if<std::string>(&c.value)) {
                                    if (*v == "m") {
                                        std::cout << "Du träffade en mina, Game over"  << std::endl;
                                        return;
                                    }
                                }else if (auto vi = std::get_if<int>(&c.value)) {
                                    number_of_nonmines_found++;

                                    
                                }
                                //To control the winning functionality
                               // std::cout << "number of non mines found is: " << number_of_nonmines_found << std::endl;
                                //std::cout << "number of mines: " << totalMines << std::endl;
                                //std::cout << "cells: " << number_of_cells << std::endl;
                                if(number_of_cells == totalMines + number_of_nonmines_found){
                                    std::cout << "Du vann!!";
                                    return;
                                }
                                                        

                            } else {
                                std::cout << "Koordinaterna är utanför spelplanen.\n";
                            }
                        } else {
                            std::cout << "Fel input: du måste skriva siffror inom parenteserna.\n";
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

//number of minees felaktikgt!! kolla på det

