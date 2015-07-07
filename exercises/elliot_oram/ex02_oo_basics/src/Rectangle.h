#ifndef RECTANGLE_H
#define RECTANGLE_H
// Includes
#include "Shape.h"

// Class definition
class Rectangle : public Shape {
public:
  Rectangle();
  Rectangle(double h, double w);
  ~Rectangle();
  void print();

private:
};

#endif RECTANGLE_H

// End of File