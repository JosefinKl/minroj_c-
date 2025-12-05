#include "mine.h"
#include "matrix.h"

#include <iostream>
#include <random>



void Mine::start_mine(){
    std::string text;
    text = "m";
    int x;

    Cell c(text);

     // Skapa en slumpmässig talgenerator som ska generera minor
    std::random_device rd;  // Används för att få en slumpmässig startpunkt
    std::mt19937 gen(rd()); 

    Matrix matrix;

    for (int i = 0; i < Matrix::size; ++i) {
        
        for (int j = 0; j < Matrix::size; ++j) {
           

            //Intervall för slumpning av antal minor
            std::uniform_int_distribution<> distr(0, Matrix::size-1); 

            // Slumpa ett tal
            int col_number_random = distr(gen);

            matrix.setCell(i, col_number_random, c);
           
        }
        std::cout << std::endl;

    }

    //Kontrollera så det är minor på några platser, blir lite för många minor men fixar senare om tid finns. 
    matrix.display();

    //Ge siffror för hur många angränsande minor

    int num_close_mine = 0;

for (int i = 0; i < Matrix::size; ++i) {
    for (int j = 0; j < Matrix::size; ++j) {

        int nearby = 0;

        // Gå igenom alla 8 närliggande celler
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {

                if (di == 0 && dj == 0) continue; // hoppa över sig själv

                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < Matrix::size &&
                    nj >= 0 && nj < Matrix::size) {

                    const Cell& neigh = matrix.getCell(ni, nj);

                    if (auto v = std::get_if<std::string>(&neigh.value)) {
                        if (*v == "m") {
                            nearby++;
                        }
                    }
                }
            }
        }

        std::cout << "Cell (" << i << "," << j 
                  << ") har " << nearby << " minor runt sig\n";
    }
}



}

