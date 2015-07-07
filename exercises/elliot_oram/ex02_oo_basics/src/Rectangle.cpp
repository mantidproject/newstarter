// Includes
#include "Rectangle.h"
#include <string>
#include <iomanip>
#include <iostream>

// Constructors
Rectangle::Rectangle() {}

/**
 *Sets the height, width, perimeter and area of a Rectangle
 *@param h The height of the rectangle
 *@param w The width of the rectangle
 */
Rectangle::Rectangle(double h, double w) : Shape("Rectangle", 4) {
  setHeight(h);
  setWidth(w);
  setPerimeter((2 * h) + (2 * w));
  setArea(h * w);
}

Rectangle::~Rectangle() {}

// Member Functions
/**
 *Prints the height, width and footer of the Rectangle Object
 */
void Rectangle::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Height: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << std::setw(12) << std::left << "Width: " << std::setw(10)
            << std::left << getWidth() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File