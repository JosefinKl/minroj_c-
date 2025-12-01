#ifndef CELL_H
#define CELL_H

#include <variant>
#include <string>

class Cell {
public:
    std::variant<int, std::string> value;

     Cell(); 
    //För heltal
    Cell(int num);

    // För sträng (minor)
    Cell(const std::string& text);
};

#endif 