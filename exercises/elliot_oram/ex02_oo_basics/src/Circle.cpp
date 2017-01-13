// Includes
#define _USE_MATH_DEFINES

#include "Circle.h"

#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

// Constructors
Circle::Circle() {}

/**
 *Sets the height, width, perimeter and area of a Circle
 *@param r The radius of the Circle
 */
Circle::Circle(const double &r) : Shape("Circle", 1) {
  setHeight(r);
  setPerimeter(2 * M_PI * r);
  setArea(M_PI * (r * r));
}

Circle::~Circle() {}

// Member Fuctions

/**
 *Prints the radius and footer of the Circle Object
 */
void Circle::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Radius: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File