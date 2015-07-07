// Includes
#include "Triangle.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

// Constructors
Triangle::Triangle() {}

/**
 *Sets the height, width, perimeter and area of a Triangle
 *@param h The height of the Triangle
 *@param w The base width of the Triangle
 */
Triangle::Triangle(double h, double w) : Shape("Triangle", 3) {
  setHeight(h);
  setWidth(w);
  setPerimeter(
      w + sqrt((h * h) + ((w * w) / 4))); // Assumed to be isoceles triangle
  setArea(0.5 * (h * w));
}

Triangle::~Triangle() {}

// Member Functions

/**
 *Prints the height, base and footer of the Triangle Object
 */
void Triangle::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Height: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << std::setw(12) << std::left << "Base: " << std::setw(10)
            << std::left << getWidth() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File