#ifndef RECTANGLE_H
#define RECTANGLE_H
// Includes
#include "Shape.h"

/**
 *A Class used to model a Rectangle 
 *Rectangle inherits from the Shape super class
 */
class Rectangle : public Shape {
public:
  Rectangle();
  Rectangle(const double &h, const double &w);
  ~Rectangle();
  void print();

private:
};

#endif

// End of File