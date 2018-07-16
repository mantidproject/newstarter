#include "Square.h"

Square::Square(double size) : Rectangle(size, size) {}

/**
 * method gets the object width
 * @params none
 * @return The width
 */
double Square::getSize() const { return getWidth(); }

/**
 * method gets the object type
 * @params none
 * @return A string relating to the objects type
 */
std::string Square::getType() const { return "square"; }
