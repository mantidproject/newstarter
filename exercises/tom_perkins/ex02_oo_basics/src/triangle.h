#ifndef TRIANGLE_H_
#define TRIANGLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"
#include <cmath>

/**
 * \brief Triangle represents an isoceles triangle
 */
class Triangle : public Shape {
public:
  Triangle(double heightIn, double baseIn, std::string nameIn);
  double perimeter() const;
  double area() const;

private:
  const double height;
  const double base;
};

#endif