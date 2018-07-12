#include "Square.h"

Square::Square(double size) : Rectangle(size, size) {}

double Square::getSize() const { return getWidth(); }

std::string Square::getType() const { return "Square"; }
