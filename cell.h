#ifndef CELL_H
#define CELL_H

#include <variant>
#include <string>

class Cell {
public:
    std::variant<int, std::string> value;

    //För heltal
    Cell(int num);

    // För sträng (minor)
    Cell(const std::string& text);
};

#endif // CELL_H