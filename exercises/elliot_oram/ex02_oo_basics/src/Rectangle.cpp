// Includes
#include "Rectangle.h"
#include <string>
#include <iomanip>
#include <iostream>

// Constructors
Rectangle::Rectangle() {}

Rectangle::Rectangle(double h, double w) : Shape("Rectangle", 4) {
  setHeight(h);
  setWidth(w);
  setPerimeter((2 * h) + (2 * w));
  setArea(h * w);
}

Rectangle::~Rectangle() {}

// Member Functions
void Rectangle::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Height: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << std::setw(12) << std::left << "Width: " << std::setw(10)
            << std::left << getWidth() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File