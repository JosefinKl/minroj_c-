#include "cell.h"

Cell::Cell() : value(" ") {}  
Cell::Cell(int num) : value(num) {}

Cell::Cell(const std::string& text) : value(text) {}