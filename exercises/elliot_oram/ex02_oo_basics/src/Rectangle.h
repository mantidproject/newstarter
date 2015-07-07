#ifndef RECTANGLE_H
#define RECTANGLE_H
// Includes
#include "Shape.h"

// Class definition
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