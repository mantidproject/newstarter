// Includes
#include "Square.h"

#include <iomanip>
#include <iostream>
#include <string>

// Constructors
Square::Square() {}

Square::Square(double h, double w) : Shape("Square", 4) {
  setHeight(h);
  setWidth(w);
  setPerimeter(h * 4);
  setArea(h * h);
}

Square::~Square() {}

// Member Functions
void Square::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Height: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << std::setw(12) << std::left << "Width: " << std::setw(10)
            << std::left << getWidth() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File