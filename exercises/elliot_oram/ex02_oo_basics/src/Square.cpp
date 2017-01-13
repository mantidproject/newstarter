// Includes
#include "Square.h"

#include <iomanip>
#include <iostream>
#include <string>

// Constructors
Square::Square() {}

/**
 *Sets the height, width, perimeter and area of a Square
 *@param h The height of the Square
 *@param w The width of the Square
 */
Square::Square(const double &h, const double &w) : Shape("Square", 4) {
  setHeight(h);
  setWidth(w);
  setPerimeter(h * 4);
  setArea(h * h);
}

Square::~Square() {}

// Member Functions

/**
 *Prints the height, base and footer of the Square Object
 */
void Square::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Height: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << std::setw(12) << std::left << "Width: " << std::setw(10)
            << std::left << getWidth() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File