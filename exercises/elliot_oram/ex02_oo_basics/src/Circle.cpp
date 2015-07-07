// Includes
#define _USE_MATH_DEFINES

#include "Circle.h"

#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

// Constructors
Circle::Circle() {}

Circle::Circle(double r) : Shape("Circle", 1) {
  setHeight(r);
  setPerimeter(2 * M_PI * r);
  setArea(M_PI * (r * r));
}

Circle::~Circle() {}

// Member Fuctions
void Circle::print() {
  Shape::print();
  std::cout << std::setw(12) << std::left << "Radius: " << std::setw(10)
            << std::left << getHeight() << std::endl;
  std::cout << "============================================" << std::endl;
}

// End of File